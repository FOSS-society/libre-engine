#ifndef USERPROJECT_H
#define USERPROJECT_H


#include <QString>
#include <libre-engine/graphics/Renderer.hpp>


///
/// \brief The UserProject class
///
/// The class which describes the project
/// inside the file-system.  It contains a
/// the directory path as a string, as well
/// as a RendererType enum.
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
    QString directoryPath() const;
    void setDirectoryPath(const QString &directoryPath);
    libre::graphics::RendererType RenderingType() const;
    void setRenderingType(const libre::graphics::RendererType &RenderingType);
    QString name() const;
    void setName(const QString &name);
};



#endif // USERPROJECT_H
