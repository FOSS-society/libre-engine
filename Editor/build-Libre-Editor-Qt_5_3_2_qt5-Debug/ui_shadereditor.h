/********************************************************************************
** Form generated from reading UI file 'shadereditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHADEREDITOR_H
#define UI_SHADEREDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShaderEditor
{
public:
    QPushButton *New;
    QPushButton *Load;
    QPushButton *Exit;
    QPushButton *Save;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *textEdit;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *ShaderEditor)
    {
        if (ShaderEditor->objectName().isEmpty())
            ShaderEditor->setObjectName(QStringLiteral("ShaderEditor"));
        ShaderEditor->resize(925, 522);
        New = new QPushButton(ShaderEditor);
        New->setObjectName(QStringLiteral("New"));
        New->setGeometry(QRect(430, 480, 90, 26));
        Load = new QPushButton(ShaderEditor);
        Load->setObjectName(QStringLiteral("Load"));
        Load->setGeometry(QRect(530, 480, 90, 26));
        Exit = new QPushButton(ShaderEditor);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(720, 480, 90, 26));
        Save = new QPushButton(ShaderEditor);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setGeometry(QRect(620, 480, 90, 26));
        scrollArea = new QScrollArea(ShaderEditor);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 351, 491));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 336, 489));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 341, 491));
        scrollArea->setWidget(scrollAreaWidgetContents);
        graphicsView = new QGraphicsView(ShaderEditor);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(390, 10, 521, 331));

        retranslateUi(ShaderEditor);

        QMetaObject::connectSlotsByName(ShaderEditor);
    } // setupUi

    void retranslateUi(QWidget *ShaderEditor)
    {
        ShaderEditor->setWindowTitle(QApplication::translate("ShaderEditor", "Shader Editor", 0));
        New->setText(QApplication::translate("ShaderEditor", "New", 0));
        Load->setText(QApplication::translate("ShaderEditor", "Load", 0));
        Exit->setText(QApplication::translate("ShaderEditor", "Exit", 0));
        Save->setText(QApplication::translate("ShaderEditor", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class ShaderEditor: public Ui_ShaderEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADEREDITOR_H
