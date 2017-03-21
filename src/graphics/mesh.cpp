#include "../../include/graphics/mesh.hpp"

namespace libre{

    namespace graphics{

    void Mesh::setupMesh()
    {

            OpenGL::genVertexArrays(1, &this->VAO);
            OpenGL::genBuffers(1.&this->VBO);
            OpenGL::genBuffers(1.&this->VBO);

            OpenGL::BindVertexArray(this->VAO);
            OpenGL::BindBuffer(GL_ARRAY_BUFFER, this->VBO);

            OpenGL::BufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(i_MeshVertex),
                         &this->m_vertices[0], GL_STATIC_DRAW);

            OpenGL::bindBuffers(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
            OpenGL::BufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(GLuint),
                         &this->m_indices[0], GL_STATIC_DRAW);

            // Vertex Positions
            OpenGL::enableVertexAttribArray(0);
            OpenGL::VertexAttributePointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(i_MeshVertex),
                                 (GLvoid*)0);
            // Vertex Normals
            OpenGL::enableVertexAttribArray(1);
            OpenGL::VertexAttributePointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(i_MeshVertex),
                                 (GLvoid*)offsetof(i_MeshVertex, m_normals));
            // Vertex Texture Coords
            OpenGL::enableVertexAttribArray(2);
            OpenGL::VertexAttributePointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                 (GLvoid*)offsetof(i_MeshVertex, m_texCoords));

            OpenGL::BindVertexArray(0);
        }


    // Render the mesh
    void Mesh::Draw(Shader shader)
    {
        // Bind appropriate textures
        GLuint diffuseNr = 1;
        GLuint specularNr = 1;
        for(GLuint i = 0; i < this->textures.size(); i++)
        {
            OpenGL::activeTexture(GL_TEXTURE0 + i); // Active proper texture unit before binding
            // Retrieve texture number (the N in diffuse_textureN)
            std::stringstream ss;
            std::string number;
            std::string name = this->textures[i].type;
            if(name == "texture_diffuse")
                ss << diffuseNr++; // Transfer GLuint to stream
            else if(name == "texture_specular")
                ss << specularNr++; // Transfer GLuint to stream
            number = ss.str();
            // Now set the sampler to the correct texture unit
            OpenGL::Uniform1i(glGetUniformLocation(shader.Program, (name + number).c_str()), i);
            // And finally bind the texture
            OpenGL::bindTexture(GL_TEXTURE_2D, this->m_textures[i].id);
        }

        // Also set each mesh's shininess property to a default value (if you want you could extend this to another mesh property and possibly change this value)
        OpenGL::Uniform1f(glGetUniformLocation(shader.Program, "material.shininess"), 16.0f);

        // Draw mesh
        OpenGL::BindVertexArray(this->VAO);
        OpenGL::drawElements(GL_TRIANGLES, this->m_indices.size(), GL_UNSIGNED_INT, 0);
        OpenGL::BindVertexArray(0);

        // Always good practice to set everything back to defaults once configured.
        for (GLuint i = 0; i < this->m_textures.size(); i++)
        {
            OpenGL::ActiveTexture(GL_TEXTURE0 + i);
            OpenGL::bindTexture(GL_TEXTURE_2D, 0);
        }
    }



    }
}
