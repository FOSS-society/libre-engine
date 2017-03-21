#ifndef MESH_HPP
#define MESH_HPP


#include "../math/libremath.hpp"
#include <vector>
#include "graphics_common.hpp"
#include "graphics/Shader.hpp"
#include "../system/OpenGL.hpp"

namespace libre{

    //foward declare
    class system::BufferLayout;

    namespace graphics{

    struct i_MeshVertex{
    std::vector<math::vector3<float>> m_positions;
    std::vector<math::vector3<float>> m_normals;
    std::vector<math::vector2<float>> m_texCoords;
    };

    struct i_MeshTexture {
        GLuint id;
        string type;
    };


    class Mesh{
    private:
         system::BufferLayout m_layout;
         std::vector<i_MeshVertex> m_verticies;
         std::vector<GLuint> m_indices;
         std::vector<i_MeshTexture> m_textures;
         /*  Render data  */
         GLuint VAO, VBO, EBO;
         /*  Functions    */
         void setupMesh();
        public:
         Mesh(std::vector<i_MeshVertex> vertices, std::vector<GLuint> indices,
              std::vector<i_MeshTexture> textures);

         void Draw(Shader shader);


    };

    }
}
#endif
