/********************************************************************************
** Form generated from reading UI file 'projectcreategui.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTCREATEGUI_H
#define UI_PROJECTCREATEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectCreateGUI
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *projectName;
    QLabel *label_2;
    QLineEdit *projectDir;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *ProjectCreateGUI)
    {
        if (ProjectCreateGUI->objectName().isEmpty())
            ProjectCreateGUI->setObjectName(QStringLiteral("ProjectCreateGUI"));
        ProjectCreateGUI->resize(400, 217);
        formLayoutWidget = new QWidget(ProjectCreateGUI);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 401, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        projectName = new QLineEdit(formLayoutWidget);
        projectName->setObjectName(QStringLiteral("projectName"));

        formLayout->setWidget(2, QFormLayout::FieldRole, projectName);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        projectDir = new QLineEdit(formLayoutWidget);
        projectDir->setObjectName(QStringLiteral("projectDir"));

        formLayout->setWidget(3, QFormLayout::FieldRole, projectDir);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(5, QFormLayout::SpanningRole, horizontalSpacer);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);
        comboBox->setMaxVisibleItems(2);
        comboBox->setMaxCount(2);
        comboBox->setMinimumContentsLength(2);
        comboBox->setModelColumn(0);

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBox);

        horizontalLayoutWidget = new QWidget(ProjectCreateGUI);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, 170, 401, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        retranslateUi(ProjectCreateGUI);

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ProjectCreateGUI);
    } // setupUi

    void retranslateUi(QWidget *ProjectCreateGUI)
    {
        ProjectCreateGUI->setWindowTitle(QApplication::translate("ProjectCreateGUI", "Form", 0));
        label->setText(QApplication::translate("ProjectCreateGUI", "Project Name:     ", 0));
        label_2->setText(QApplication::translate("ProjectCreateGUI", "Project Directory:", 0));
        pushButton->setText(QApplication::translate("ProjectCreateGUI", "Find Directory", 0));
        label_3->setText(QApplication::translate("ProjectCreateGUI", "Rendering Type:  ", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ProjectCreateGUI", "2D", 0)
         << QApplication::translate("ProjectCreateGUI", "3D", 0)
        );
        comboBox->setCurrentText(QApplication::translate("ProjectCreateGUI", "3D", 0));
        pushButton_2->setText(QApplication::translate("ProjectCreateGUI", "Create", 0));
        pushButton_3->setText(QApplication::translate("ProjectCreateGUI", "Reset", 0));
        pushButton_4->setText(QApplication::translate("ProjectCreateGUI", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectCreateGUI: public Ui_ProjectCreateGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTCREATEGUI_H
