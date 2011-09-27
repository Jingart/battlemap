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
    QPoint findWindowCenter();
    void drawMapWindow();
    void InitializeMatrix();
    void drawBox(QPen pen, int x, int y);
    void deselectTile();
    void selectTile();
    void setTileSelected(int row, int column);
    TilePosition findTileAt(QPoint point);

  protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setupTile();



};

#endif
