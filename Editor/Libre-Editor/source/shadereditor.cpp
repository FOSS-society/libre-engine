#include "include/shadereditor.h"
#include "ui_shadereditor.h"

ShaderEditor::ShaderEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShaderEditor)
{
    ui->setupUi(this);
}

ShaderEditor::~ShaderEditor()
{
    delete ui;
}

void ShaderEditor::on_Exit_clicked()
{
    this->close();
}
