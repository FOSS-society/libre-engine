#ifndef USERPROJECT_H
#define USERPROJECT_H


#include <QString>
#include <libre-engine/graphics/Renderer.hpp>

class UserProject
{

private:
    QString m_name;
    QString m_directoryPath;
    libre::graphics::RendererType m_RenderingType;
public:
    UserProject();
    UserProject(QString name,QString dirpath, libre::graphics::RendererType type);


    static UserProject CreateProject();
};

#endif // USERPROJECT_H
