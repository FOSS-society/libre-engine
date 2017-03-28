#include "include/projectcreategui.h"
#include "ui_projectcreategui.h"
#include "../include/mainwindow.h"
#include "../../include/system/Utility.hpp"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QDebug>


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

    QString fullProjectPath;

   libre::graphics::RendererType tempt;
   char *types;

   switch(ui->comboBox->currentIndex()){

   case 0:
       tempt = libre::graphics::RendererType::RT_2D;
       types = "2D";
        break;
   case 1:
       tempt = libre::graphics::RendererType::RT_3D;
       types = "3D";
       break;
   }

   m_main->setProject(new UserProject(ui->projectName->text(),ui->projectDir->text(),tempt));
   fullProjectPath = ui->projectDir->text();
   fullProjectPath.append("/");
   fullProjectPath.append(ui->projectName->text());
   QString assetProjectPath = fullProjectPath + "/" + QString("Assets");
   const QDir temp;
   temp.mkdir(fullProjectPath);
   temp.mkdir(assetProjectPath);
   temp.mkdir(QString(assetProjectPath + QString("/Scripts")));

   QString defShaderPath = QString("/usr/local/etc/libre-engine/shaders");
   QString destShaderPath = QString(assetProjectPath + QString("/Shaders"));


    if(!copyDir(defShaderPath,destShaderPath)){
        qDebug() << "Copying Failed!!!";
        QApplication::exit(-1);
    }
    QFile meta;
    meta.setFileName(fullProjectPath.append("/le.meta"));
    meta.open(QFile::WriteOnly);
    meta.write(types);
    meta.close();
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

/**
    Thank you falco!
 */

bool copyDir(const QString &srcFilePath,
                            const QString &tgtFilePath)
{
    QFileInfo srcFileInfo(srcFilePath);
    if (srcFileInfo.isDir()) {
        // if srcFileInfo.isDir, targetDir is set to tgtFilePath
        QDir targetDir(tgtFilePath);
       targetDir.cdUp();
        if (!targetDir.mkdir(QFileInfo(tgtFilePath).fileName()))
            return false;
        QDir sourceDir(srcFilePath);
        QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
        if(fileNames.isEmpty()){
            qDebug() << "Nothing in " << sourceDir.dirName();
            return true;
        }
        Q_FOREACH (const QString &fileName, fileNames) {
            const QString newSrcFilePath
                    = srcFilePath + QLatin1Char('/') + fileName;
            const QString newTgtFilePath
                    = tgtFilePath + QLatin1Char('/') + fileName;
            if (!copyDir(newSrcFilePath, newTgtFilePath))
                return false;
        }
    } else {
        if (!QFile::copy(srcFilePath, tgtFilePath)){
            return false;
        }else{
        }
    }
    return true;
}


