#include "battlemap.h"
#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>
#include <vector>

using namespace std;

//BattlemapTile ***bmmatrix;
std::vector<std::vector<BattlemapTile> > bmmatrix2(10);

battlemap::battlemap(QWidget *parent)
                    : QWidget(parent)
{

}

battlemap::battlemap(QWidget *parent, int x, int y)
                    : QWidget(parent)
{
    //**bmmatrix

}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPen pen(Qt::black, 2, Qt::SolidLine);
  QPainter painter(this);

  int top = 0;
  int left = 0;
  int right = 100;
  int bottom = 100;

  QPoint ltop(left,top);
  QPoint rtop(right,top);
  QPoint lbottom(left,bottom);
  QPoint rbottom(right,bottom);

  painter.setPen(pen);
  painter.drawLine(ltop, rtop);
  painter.drawLine(rtop, rbottom);
  painter.drawLine(rbottom, lbottom);
  painter.drawLine(lbottom, ltop);


  /*
  painter.setPen(pen);
  painter.drawLine(20, 40, 250, 40);

  pen.setStyle(Qt::DashLine);
  painter.setPen(pen);
  painter.drawLine(20, 80, 250, 80);

  pen.setStyle(Qt::DashDotLine);
  painter.setPen(pen);
  painter.drawLine(20, 120, 250, 120);

  pen.setStyle(Qt::DotLine);
  painter.setPen(pen);
  painter.drawLine(20, 160, 250, 160);

  pen.setStyle(Qt::DashDotDotLine);
  painter.setPen(pen);
  painter.drawLine(20, 200, 250, 200);


  QVector<qreal> dashes;
  qreal space = 4;

  dashes << 1 << space << 5 << space;

  pen.setStyle(Qt::CustomDashLine);
  pen.setDashPattern(dashes);
  painter.setPen(pen);
  painter.drawLine(20, 240, 250, 240);
  */
}

void battlemap::drawBox(QPen pen, int x, int y)
{
    QPainter painter(this);
    painter.setPen(pen);

}
