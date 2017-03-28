#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../include/shadereditor.h"
#include "../include/scripteditor.h"
#include "../include/projectcreategui.h"
#include "../../include/system/Utility.hpp"

#include <QDir>
#include <QFileDialog>
#include <QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_project(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit(0);
}

void MainWindow::on_actionShader_Editor_triggered()
{
    ShaderEditor *window = new ShaderEditor;
    window->setVisible(true);
    window->setEnabled(true);
    window->show();

}

void MainWindow::on_actionScript_Editor_triggered()
{
    ScriptEditor *window = new ScriptEditor;
    window->setVisible(true);
    window->setEnabled(true);
    window->show();
    window->setMain(this);
    window->updateListView();
}

void MainWindow::on_actionNew_Project_triggered()
{
    ProjectCreateGUI *window = new ProjectCreateGUI();
    window->setMain(this);
    window->setVisible(true);
    window->setEnabled(true);
    window->show();


}
UserProject *MainWindow::project() const
{
    return m_project;
}

void MainWindow::setProject(UserProject *project)
{
    m_project = project;
}


void MainWindow::on_actionLoad_Project_triggered()
{
    QString FullProjectDirectory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                                 "/home",
                                                                 QFileDialog::ShowDirsOnly
                                                                 | QFileDialog::DontResolveSymlinks);

    QStringList templist = FullProjectDirectory.split("/");
    QString projectName = templist.back();
    // I will need to chomp the directory name as well as the trailing '/'
    QString projectDirectory = FullProjectDirectory;
    projectDirectory.chop(projectName.size()+1);
    QFile meta;
    meta.setFileName(FullProjectDirectory.append(QString("/le.meta")));

    libre::graphics::RendererType type;

    meta.open(QFile::ReadOnly);
    QByteArray arr = meta.read(2);

    switch(arr.at(0)){
    case '2':
        type = libre::graphics::RendererType::RT_2D;
        break;
     case '3':
        type = libre::graphics::RendererType::RT_3D;
        break;
    }
    meta.close();

    m_project = new UserProject(projectName,projectDirectory,type);

}
