#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "graphics_common.hpp"


namespace libre{
    namespace graphics{

    //foward Declare
    class Shader;

    /**
     * @brief The ShaderProgram class
     *
     *
     * Notes: The Array of shaders need to match the Pipeline:
     *           0: Vertex
     *           1:Tessalation Control
     *           2:Tessalation Evaluation
     *           3:Geometry
     *           4:Fragment
     *
     *
     * 1,2,3 are not needed
     *
     *
     *
     */




    class ShaderProgram{

    private:
        GLuint m_program;
        Shader m_shaderList[5];


    public:

        /**
         * Constructors
         * 1. All shader filepaths
         * 2. All Shaders
         */

        ShaderProgram(const std::string &vertex,const std::string &fragment,const std::string &tess1 = nullptr,
                      const std::string &tess2= nullptr,const std::string &geometry=nullptr);
        ShaderProgram(const Shader &vertex,const Shader &fragment,const Shader &tess1 = nullptr,
                      const Shader &tess2= nullptr,const Shader &geometry=nullptr);


        Shader getShader(int index);
        Shader ShaderC(int index)const;

        void setShader(int index, const std::string &shaderpath);
        void setShader(int index, const Shader &shader);

        GLuint getProgram();
        GLuint Program()const;

    };




    }
}




#endif // SHADERPROGRAM_H
