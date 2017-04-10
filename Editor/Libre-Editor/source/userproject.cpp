#include "include/userproject.h"



QString UserProject::directoryPath() const
{
    return m_directoryPath;
}

void UserProject::setDirectoryPath(const QString &directoryPath)
{
    m_directoryPath = directoryPath;
}

libre::graphics::RendererType UserProject::RenderingType() const
{
    return m_RenderingType;
}

void UserProject::setRenderingType(const libre::graphics::RendererType &RenderingType)
{
    m_RenderingType = RenderingType;
}

QString UserProject::name() const
{
    return m_name;
}

void UserProject::setName(const QString &name)
{
    m_name = name;
}
UserProject::UserProject()
{
}

UserProject::UserProject(QString name, QString dirpath, libre::graphics::RendererType type):m_name(name),
    m_directoryPath(dirpath),m_RenderingType(type)
{

}
