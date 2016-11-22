#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include "graphics_common.hpp"
#include "Shader.hpp"


namespace libre{
    namespace graphics{

    class ShaderProgram{

    private:
        GLuint m_program;
        std::vector<Shader*> m_shaders;
        bool m_shaderChecked[6];
        bool m_isLoaded;
        bool use();

    public:
        ShaderProgram(Shader *shader);

        void addShader(Shader *shader);
        void removeShader(Shader *shader);
        void removeShader(short index);

        //load the shaders
        bool load();

        //link the shaders
        bool link();

    };


    }
}


#endif // SHADERPROGRAM_HPP
