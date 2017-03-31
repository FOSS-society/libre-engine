#ifndef SHADEREDITOR_H
#define SHADEREDITOR_H

#include <QWidget>
#include <QTableWidgetItem>
#include "mainwindow.h"

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


private:
    Ui::ShaderEditor *ui;
    MainWindow *m_main;
};

#endif // SHADEREDITOR_H
