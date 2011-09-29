#ifndef BATTLEMAP_H
#define BATTLEMAP_H


#include <QPainter>
#include <QResizeEvent>
#include <QWidget>
#include "selectedtile.h"
#include "tileposition.h"


class Battlemap : public QWidget
{
  Q_OBJECT

  public:
    Battlemap(QWidget *parent = 0);
    Battlemap(int x, int y);
    //battlemap(QWidget *parent, int rows, int columns);

  private:
    SelectedTile *clickStatus;
    SelectedTile *destinationStatus;
    QPoint findWindowCenter();
    void drawMapWindow();
    void InitializeMatrix();
    void drawBox(QPen pen, int x, int y);
    TilePosition findTileAt(QPoint point);
    void resetTileSelect(SelectedTile *tileSelect);
    void setTileSelect(SelectedTile *tileSelect, int row, int column, QColor color);

  protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setupTile();



};

#endif
