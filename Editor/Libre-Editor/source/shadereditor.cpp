#include "include/shadereditor.h"
#include "ui_shadereditor.h"
#include <QFileDialog>
#include <QDebug>
#include <QtCore>

ShaderEditor::ShaderEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShaderEditor)
{
    ui->setupUi(this);
    connect(this->ui->tableWidget->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(onHeaderClicked(int)));
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
    qDebug() << "Clicked on" <<item->data(Qt::DisplayRole).toString();

    int tempRow, tempColumn;
    tempRow = item->row();
    tempColumn = item->column();
    QString filepath;
    QStringList templist;
    QTableWidgetItem *qtwi; // i use this for the filepath name
    QTableWidgetItem *qtwi2; // i use this for the file name
    QString shaders;
    switch(item->column()){
    case 0:
        break;
    case 1:
        shaders = m_main->project()->directoryPath();
        shaders.append("/");
        shaders.append(m_main->project()->name());
        shaders.append("/Assets/Shaders");
        filepath = QFileDialog::getOpenFileName(this,QString("Select Shader"),shaders,QString(),0,0);
        templist = filepath.split("/");
        qtwi = new QTableWidgetItem(filepath);
        qtwi2 = new QTableWidgetItem(templist.back());
        this->ui->tableWidget->setItem(tempRow,tempColumn,qtwi);
        this->ui->tableWidget->setItem(tempRow,tempColumn-1,qtwi2);
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


void ShaderEditor::on_Load_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,QString("Select Shader"),m_main->project()->directoryPath(),QString(),0,0);
    QFile file;
    file.setFileName(filepath);
    file.open(QFile::ReadOnly);
    QByteArray data = file.readAll();
    this->ui->textEdit->setText(data);
    file.close();
    /**
        TODO: Implement GLSL Highlighting
      **/
}

void ShaderEditor::onHeaderClicked(int index)
{
    QString filepath = ui->tableWidget->item(index,1)->data(Qt::DisplayRole).toString();
    QFile file;
    file.setFileName(filepath);
    file.open(QFile::ReadOnly);
    QByteArray data = file.readAll();
    this->ui->textEdit->setText(data);
    file.close();
}

