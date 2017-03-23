/********************************************************************************
** Form generated from reading UI file 'tilemapeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILEMAPEDITOR_H
#define UI_TILEMAPEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TileMapEditor
{
public:

    void setupUi(QWidget *TileMapEditor)
    {
        if (TileMapEditor->objectName().isEmpty())
            TileMapEditor->setObjectName(QStringLiteral("TileMapEditor"));
        TileMapEditor->resize(1171, 711);

        retranslateUi(TileMapEditor);

        QMetaObject::connectSlotsByName(TileMapEditor);
    } // setupUi

    void retranslateUi(QWidget *TileMapEditor)
    {
        TileMapEditor->setWindowTitle(QApplication::translate("TileMapEditor", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class TileMapEditor: public Ui_TileMapEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILEMAPEDITOR_H
