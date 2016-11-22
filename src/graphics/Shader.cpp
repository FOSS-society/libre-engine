#include "../../include/graphics/Shader.hpp"
#include "../../include/system/Utility.hpp"
#include "../../include/system/OpenGL.hpp"
#include "../../include/system/Logger.hpp"

namespace libre{

namespace graphics{


bool Shader::linked() const
{
    return m_linked;
}

void Shader::setLinked(bool linked)
{
    m_linked = linked;
}
Shader::Shader(std::string name, std::string filepath, ShaderType type):
    m_name(name),m_filePath(filepath),m_type(type),m_compiled(false),m_linked(false)
{
    this->m_Source = Utility::readFile(filepath.c_str());
        //First lets deal with the handle and type of shader
        switch(type){
        case ShaderType::VERTEX:
            m_handle = OpenGL::createShader(GL_VERTEX_SHADER);
            break;
        case ShaderType::GEOMETRY:
            m_handle = OpenGL::createShader(GL_GEOMETRY_SHADER);
            break;
        case ShaderType::TESSALATION1:
            m_handle = OpenGL::createShader(GL_TESS_CONTROL_SHADER);
            break;
        case ShaderType::TESSALATION2:
            m_handle = OpenGL::createShader(GL_TESS_EVALUATION_SHADER);
            break;
        case ShaderType::COMPUTE:
            m_handle = OpenGL::createShader(GL_COMPUTE_SHADER);
            break;
        case ShaderType::FRAGMENT:
            m_handle = OpenGL::createShader(GL_TESS_CONTROL_SHADER);
            break;
        }

        // find out the amount of Attributes
        GLint attrAmount;
        GLint gsize; // size of the variable
        GLenum gtype; // type of the variable (float, vec3 or mat4, etc)

        const GLsizei bufSize = 16; // maximum name length
        GLchar gname[bufSize]; // variable name in GLSL
        GLsizei glength; // name length

        OpenGL::getProgramParameter(this->m_handle,GL_ACTIVE_ATTRIBUTES,&attrAmount);

        //create the m_attribute vector
        m_attributes = new std::vector<ShaderVariable>(attrAmount);

        //loop through Attributes in opengl, assign name and type to temp variables
        //and then push back a ShaderVariable

        for(GLint i = 0;i < attrAmount; i++){
            OpenGL::getActiveAttribute(this->m_handle, (GLuint)i, bufSize, &glength, &gsize, &gtype, gname);

            switch(gtype){
            case GL_FLOAT:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::FLOAT)));
                break;
            case GL_FLOAT_VEC2:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::VEC2FLOAT)));
                break;
            case GL_FLOAT_VEC3:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::VEC3FLOAT)));

                break;
            case GL_FLOAT_VEC4:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::VEC4FLOAT)));

                break;
            case GL_FLOAT_MAT2:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::MAT2FLOAT)));

                break;
            case GL_FLOAT_MAT3:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::MAT3FLOAT)));

                break;
            case GL_FLOAT_MAT4:
                this->m_attributes->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::MAT4FLOAT)));

                break;
           }

        }

        // find out the amount of uniforms

        GLint uniformCount;
        OpenGL::getProgramParameter(this->m_handle, GL_ACTIVE_UNIFORMS, &uniformCount);
        //create the m_uniform vector

        m_uniforms = new std::vector<ShaderVariable>(uniformCount);

        //loop through uniforms in opengl, assign name and type to temp variables
        //and then push back a ShaderVariable

        for(GLint i = 0;i < uniformCount; i++){
            OpenGL::GetActiveUniform(this->m_handle, (GLuint)i, bufSize, &glength, &gsize, &gtype, gname);

            switch(gtype){
            case GL_FLOAT:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::FLOAT)));
                break;
            case GL_FLOAT_VEC2:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::VEC2FLOAT)));
                break;
            case GL_FLOAT_VEC3:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::VEC3FLOAT)));

                break;
            case GL_FLOAT_VEC4:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::VEC4FLOAT)));

                break;
            case GL_FLOAT_MAT2:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::MAT2FLOAT)));

                break;
            case GL_FLOAT_MAT3:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::MAT3FLOAT)));

                break;
            case GL_FLOAT_MAT4:
                this->m_uniforms->push_back(ShaderVariable((const char *)gname,core::Variant(core::DataType::MAT4FLOAT)));

                break;
           }

        }


}

ShaderType Shader::getType()
{
    return m_type;
}

ShaderType Shader::Type()const
{
    return m_type;
}

bool Shader::compile()
{
        if(m_Source.empty()){
            system::Logger::LogInstance()->Log("Error, Shader source %s appears to be null",this->getName().c_str());
        }

        OpenGL::compileShader(this->m_handle);
        m_compiled = true;
}



    }
}
