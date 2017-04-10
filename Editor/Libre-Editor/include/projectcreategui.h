#ifndef PROJECTCREATEGUI_H
#define PROJECTCREATEGUI_H

#include <QWidget>

namespace Ui {
class ProjectCreateGUI;
}

//foward declare
class MainWindow;


///
/// \brief The ProjectCreateGUI class
///
/// This is the Class that represents
/// the GUI for Project Creation.  After
/// the project is created, a directory is
/// created as well as a meta-file which
/// defines renderer types.  More information
/// will be stored in here.
class ProjectCreateGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCreateGUI(QWidget *parent = 0);
    ~ProjectCreateGUI();

    MainWindow *main() const;
    void setMain(MainWindow *main);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::ProjectCreateGUI *ui;
    MainWindow *m_main;
};

/**
    Thank you falco!
 */

bool copyDir(const QString &srcFilePath,
             const QString &tgtFilePath);

#endif // PROJECTCREATEGUI_H
