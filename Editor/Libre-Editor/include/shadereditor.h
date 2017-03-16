#ifndef SHADEREDITOR_H
#define SHADEREDITOR_H

#include <QWidget>

namespace Ui {
class ShaderEditor;
}

class ShaderEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ShaderEditor(QWidget *parent = 0);
    ~ShaderEditor();

private slots:
    void on_Exit_clicked();

private:
    Ui::ShaderEditor *ui;
};

#endif // SHADEREDITOR_H
