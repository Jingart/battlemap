#ifndef BATTLEMAP_H
#define BATTLEMAP_H


#include <QPainter>
#include <QResizeEvent>
#include <QWidget>
#include "clickstatus.h"


class Battlemap : public QWidget
{
  Q_OBJECT

  public:
    Battlemap(QWidget *parent = 0);
    Battlemap(int x, int y);
    //battlemap(QWidget *parent, int rows, int columns);

  private:
    void drawMapWindow();
    void InitializeMatrix();
    QPoint WindowCenter();
    void drawBox(QPen pen, int x, int y);
    void deselectTile();
    ClickStatus *clickStatus;

  protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void setupTile();



};

#endif
