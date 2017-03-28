#include "include/scripteditor.h"
#include "include/mainwindow.h"
#include "ui_scripteditor.h"
#include <QDir>
#include <QTabWidget>
#include <QDirIterator>
#include <QStringListModel>
#include <QDebug>
#include <QModelIndex>
#include <QVariant>
#include <QFileDialog>


ScriptEditor::ScriptEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScriptEditor),m_main(nullptr)
{
    ui->setupUi(this);
}

ScriptEditor::~ScriptEditor()
{
    delete ui;
}

void ScriptEditor::on_pushButton_5_clicked()
{
      this->close();
}
MainWindow *ScriptEditor::main() const
{
    return m_main;
}

void ScriptEditor::setMain(MainWindow *main)
{
    m_main = main;
}

///
/// \brief ScriptEditor::updateListView
/// TODO: FIX THIS
///
void ScriptEditor::updateListView()
{
    if(this->m_main->project() == nullptr){
        qDebug() << "There is no user project setup yet";
        return;
    }else{
        QDir dir;
        QString fpath = m_main->project()->directoryPath();
        fpath.append("/");
        fpath.append(m_main->project()->name());
        fpath.append("/Assets/Scripts/");
        dir.setPath(fpath);
        //dir.cd(QString("Scripts"));
        //
        QString txt = "*.txt";
        QStringList list;
        list= dir.entryList(QDir::Files,QDir::Name);



        QStringListModel *model= new QStringListModel(this);
        model->setStringList(list);


     ui->listView->setModel(model);
    }
}


void ScriptEditor::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void ScriptEditor::on_pushButton_2_clicked()
{
    QWidget *tab = new QWidget();
    QScrollArea *scroll = new QScrollArea(tab);
    QTextEdit *textEditor = new QTextEdit(scroll);
    ui->tabWidget->addTab(tab,"New Tab");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(tab));
    scroll->setGeometry(ui->scrollArea_2->geometry());
    textEditor->setGeometry(ui->textEdit->geometry());

}



void ScriptEditor::on_listView_doubleClicked(const QModelIndex &index)
{
    QString fullProjectDir = m_main->project()->directoryPath();
    fullProjectDir.append(QString("/%1/Assets/Scripts/").arg(m_main->project()->name()));
    QString indexString = index.data(Qt::DisplayRole).toString();
    QWidget *tab = new QWidget();
    QScrollArea *scroll = new QScrollArea(tab);
    QTextEdit *textEditor = new QTextEdit(scroll);
    ui->tabWidget->addTab(tab, index.data(Qt::DisplayRole).toString());
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(tab));

    scroll->setGeometry(ui->scrollArea_2->geometry());
    textEditor->setGeometry(ui->textEdit->geometry());

    QFile file;
    file.setFileName(fullProjectDir+ index.data(Qt::DisplayRole).toString());
    file.open(QFile::ReadWrite);
    QByteArray data = file.readAll();
    textEditor->setText(data.data());

}
;

void ScriptEditor::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName();

    QStringList list = filePath.split("/");

    QWidget *tab = new QWidget();
    QScrollArea *scroll = new QScrollArea(tab);
    QTextEdit *textEditor = new QTextEdit(scroll);
    ui->tabWidget->addTab(tab, list.back());
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(tab));

    scroll->setGeometry(ui->scrollArea_2->geometry());
    textEditor->setGeometry(ui->textEdit->geometry());
    QFile file;
    file.setFileName(filePath);
    file.open(QFile::ReadWrite);
    QByteArray data = file.readAll();
    textEditor->setText(data.data());



}

void ScriptEditor::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
           tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
          QFile file(fileName);
           if (!file.open(QIODevice::WriteOnly)) {
                   // error message
                   qDebug() << "There was an error somewhere";
               } else {
                   QTextStream stream(&file);
                    stream << ui->tabWidget->currentWidget()->findChild<QScrollArea*>()->findChild<QTextEdit*>()->toPlainText();
                   stream.flush();
                  file.close();
               }
          }

}
