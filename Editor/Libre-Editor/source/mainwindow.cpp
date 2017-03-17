#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../include/shadereditor.h"
#include "../include/scripteditor.h"
#include "../include/projectcreategui.h"

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
}

void MainWindow::on_actionNew_Project_triggered()
{
    ProjectCreateGUI *window = new ProjectCreateGUI();
    window->setVisible(true);
    window->setEnabled(true);
    window->show();
    window->setMain(this);

}
UserProject *MainWindow::project() const
{
    return m_project;
}

void MainWindow::setProject(UserProject *project)
{
    m_project = project;
}

