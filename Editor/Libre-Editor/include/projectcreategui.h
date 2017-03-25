#ifndef PROJECTCREATEGUI_H
#define PROJECTCREATEGUI_H

#include <QWidget>

namespace Ui {
class ProjectCreateGUI;
}

//foward declare
class MainWindow;

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

void copyPath(QString src, QString dst);
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);


#endif // PROJECTCREATEGUI_H
