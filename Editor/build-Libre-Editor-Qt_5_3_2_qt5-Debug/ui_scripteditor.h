/********************************************************************************
** Form generated from reading UI file 'scripteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTEDITOR_H
#define UI_SCRIPTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptEditor
{
public:
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListView *listView;
    QFrame *line;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QListView *listView_2;

    void setupUi(QWidget *ScriptEditor)
    {
        if (ScriptEditor->objectName().isEmpty())
            ScriptEditor->setObjectName(QStringLiteral("ScriptEditor"));
        ScriptEditor->resize(1014, 539);
        groupBox = new QGroupBox(ScriptEditor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 161, 501));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-1, 29, 161, 471));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 148, 469));
        listView = new QListView(scrollAreaWidgetContents);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 146, 461));
        scrollArea->setWidget(scrollAreaWidgetContents);
        line = new QFrame(ScriptEditor);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 30, 1031, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget = new QWidget(ScriptEditor);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 501, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        frame = new QFrame(ScriptEditor);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(190, 60, 811, 471));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 811, 311));
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(-1, -1, 811, 281));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 798, 279));
        textEdit = new QTextEdit(scrollAreaWidgetContents_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(3, -6, 801, 301));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        scrollArea_3 = new QScrollArea(frame);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(-1, 319, 811, 151));
        scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 798, 149));
        listView_2 = new QListView(scrollAreaWidgetContents_3);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(0, 0, 801, 151));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        retranslateUi(ScriptEditor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ScriptEditor);
    } // setupUi

    void retranslateUi(QWidget *ScriptEditor)
    {
        ScriptEditor->setWindowTitle(QApplication::translate("ScriptEditor", "Script Editor", 0));
        groupBox->setTitle(QApplication::translate("ScriptEditor", "Project Directory", 0));
        pushButton_2->setText(QApplication::translate("ScriptEditor", "New Script", 0));
        pushButton->setText(QApplication::translate("ScriptEditor", "Open Script", 0));
        pushButton_3->setText(QApplication::translate("ScriptEditor", "Save Script", 0));
        pushButton_4->setText(QApplication::translate("ScriptEditor", "Compile", 0));
        pushButton_5->setText(QApplication::translate("ScriptEditor", "Exit", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ScriptEditor", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ScriptEditor", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class ScriptEditor: public Ui_ScriptEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTEDITOR_H
