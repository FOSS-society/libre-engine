#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionShader_Editor_triggered();

    void on_actionScript_Editor_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
