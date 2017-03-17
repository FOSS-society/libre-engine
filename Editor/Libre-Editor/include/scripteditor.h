#ifndef SCRIPTEDITOR_H
#define SCRIPTEDITOR_H

#include <QWidget>

namespace Ui {
class ScriptEditor;
}

class ScriptEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ScriptEditor(QWidget *parent = 0);
    ~ScriptEditor();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::ScriptEditor *ui;
};

#endif // SCRIPTEDITOR_H
