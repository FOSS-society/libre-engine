#include "include/projectcreategui.h"
#include "ui_projectcreategui.h"
#include "../include/mainwindow.h"
#include "../../include/system/Utility.hpp"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QProcess>


ProjectCreateGUI::ProjectCreateGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectCreateGUI),m_main(nullptr)
{
    ui->setupUi(this);
}

ProjectCreateGUI::~ProjectCreateGUI()
{
    delete ui;
}

void ProjectCreateGUI::on_pushButton_2_clicked()
{
    if(ui->projectDir->text().isEmpty() || ui->projectName->text().isEmpty()){
        QMessageBox warning(QMessageBox::Warning,QString("Error!"),QString("Either Project Name Or Directory Is Empty"),QMessageBox::Ok,this);
        warning.show();
        return;
    }

   libre::graphics::RendererType tempt;

   switch(ui->comboBox->currentIndex()){

   case 0:
       tempt = libre::graphics::RendererType::RT_2D;
        break;
   case 1:
       tempt = libre::graphics::RendererType::RT_3D;
       break;
   }

   m_main->setProject(new UserProject(ui->projectName->text(),ui->projectDir->text(),tempt));
   QString fullProjectPath = ui->projectDir->text();
   fullProjectPath.append("/");
   fullProjectPath.append(ui->projectName->text());
   QString assetProjectPath = fullProjectPath + "/" + QString("Assets");
   const QDir temp;
   temp.mkdir(fullProjectPath);
   temp.mkdir(assetProjectPath);
   temp.mkdir(QString(assetProjectPath + QString("/Scripts")));
   temp.mkdir(QString(assetProjectPath + QString("/Shaders")));
   //temp.mkdir(QString(assetProjectPath + QString("/Shaders/vertex")));
   //temp.mkdir(QString(assetProjectPath + QString("/Shaders/te")));
   //temp.mkdir(QString(assetProjectPath + QString("/Shaders/tc")));
   //temp.mkdir(QString(assetProjectPath + QString("/Shaders/fragment")));
   //temp.mkdir(QString(assetProjectPath + QString("/Shaders/geometry")));
   //temp.mkdir(QString(assetProjectPath + QString("/Shaders/compute")));

   QString defShaderPath = QString("/usr/local/etc/libre-engine");
   QString destShaderPath = QString(assetProjectPath + QString("/Shaders"));
  // copyDirectoryFiles(defShaderPath, QString(assetProjectPath + QString("/Shaders")),true);
    QString fullSrcShaderPath = QString(defShaderPath + QString("/."));
    QString cpcmd = "cp -R";

    QString command = QString("%1 %2 %3").arg(cpcmd,fullSrcShaderPath,destShaderPath);

    QProcess proc;
    proc.start(command);

    proc.close();


   this->close();
}

void ProjectCreateGUI::on_pushButton_4_clicked()
{
    this->close();
}
MainWindow *ProjectCreateGUI::main() const
{
    return m_main;
}

void ProjectCreateGUI::setMain(MainWindow *main)
{
    m_main = main;
}

void ProjectCreateGUI::on_pushButton_clicked()
{
    ui->projectDir->setText(QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                              "/home",
                                                              QFileDialog::ShowDirsOnly
                                                              | QFileDialog::DontResolveSymlinks));
}






