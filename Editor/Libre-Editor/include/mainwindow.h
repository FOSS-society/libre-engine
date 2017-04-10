#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userproject.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    UserProject *project() const;
    void setProject(UserProject *project);

private slots:
    void on_actionExit_triggered();

    void on_actionShader_Editor_triggered();

    void on_actionScript_Editor_triggered();

    void on_actionNew_Project_triggered();

    void on_actionLoad_Project_triggered();

private:
    Ui::MainWindow *ui;
    UserProject *m_project;

};

#endif // MAINWINDOW_H
