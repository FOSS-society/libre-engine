#include "include/userproject.h"


UserProject::UserProject()
{
}

UserProject::UserProject(QString name, QString dirpath, libre::graphics::RendererType type):m_name(name),
    m_directoryPath(dirpath),m_RenderingType(type)
{

}
