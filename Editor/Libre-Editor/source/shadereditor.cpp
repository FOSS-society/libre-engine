#include "include/shadereditor.h"
#include "ui_shadereditor.h"
#include <QFileDialog>
#include <QDebug>

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



void ShaderEditor::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    QString filepath;
    QStringList templist;
    QTableWidgetItem *qtwi; // i use this for the filepath name
    QTableWidgetItem *qtwi2; // i use this for the file name
    QString shaders;
     QString proj;
    switch(item->column()){
    case 0:
        break;
    case 1:
        shaders = m_main->project()->directoryPath();
        shaders.append("/");
        shaders.append(m_main->project()->name());
        shaders.append("/Shaders");
        filepath = QFileDialog::getOpenFileName(this,QString("Select Shader"),shaders,QString(),0,0);
        templist = filepath.split("/");
        qtwi = new QTableWidgetItem(filepath);
        qtwi2 = new QTableWidgetItem(templist.back());
        this->ui->tableWidget->setItem(item->row(),item->column(),qtwi);
      //  this->ui->tableWidget->setItem(item->row(),0,qtwi2); //What Is Breaking this?
        break;
    default:
        qDebug () << "Error picking column";
        break;
    }
}
MainWindow *ShaderEditor::main() const
{
    return m_main;
}

void ShaderEditor::setMain(MainWindow *main)
{
    m_main = main;
}

