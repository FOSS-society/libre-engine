#include "include/tilemapeditor.hpp"
#include "ui_tilemapeditor.h"

TileMapEditor::TileMapEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TileMapEditor)
{
    ui->setupUi(this);
}

TileMapEditor::~TileMapEditor()
{
    delete ui;
}
