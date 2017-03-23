#ifndef TILEMAPEDITOR_HPP
#define TILEMAPEDITOR_HPP

#include <QWidget>

namespace Ui {
class TileMapEditor;
}

class TileMapEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TileMapEditor(QWidget *parent = 0);
    ~TileMapEditor();

private:
    Ui::TileMapEditor *ui;
};

#endif // TILEMAPEDITOR_HPP
