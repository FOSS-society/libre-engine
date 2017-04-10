#ifndef SHADEREDITOR_H
#define SHADEREDITOR_H

#include <QWidget>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "glslhighlighter.h"
namespace Ui {
class ShaderEditor;
}

class ShaderEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ShaderEditor(QWidget *parent = 0);
    ~ShaderEditor();

    MainWindow *main() const;
    void setMain(MainWindow *main);

private slots:
    void on_Exit_clicked();


    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_Load_clicked();
    void onHeaderClicked(int index);


private:
    Ui::ShaderEditor *ui;
    MainWindow *m_main;
    GLSLHighlighter *m_highlighter;
};

#endif // SHADEREDITOR_H
