#ifndef SCRIPTEDITOR_H
#define SCRIPTEDITOR_H

#include <QWidget>

namespace Ui {
class ScriptEditor;
}
//foward declare
class MainWindow;

class ScriptEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ScriptEditor(QWidget *parent = 0);
    ~ScriptEditor();

    MainWindow *main() const;
    void setMain(MainWindow *main);
    void updateListView();

private slots:
    void on_pushButton_5_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_pushButton_2_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ScriptEditor *ui;
    MainWindow *m_main;
};

#endif // SCRIPTEDITOR_H
