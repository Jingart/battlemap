#include "battlemap.h"

//battlemap::battlemap()
//{
//}

//#include "lines.h"
#include <QApplication>
#include <QPainter>


battlemap::battlemap(QWidget *parent)
                    : QWidget(parent)
{

}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPen pen(Qt::black, 2, Qt::SolidLine);

  QPainter painter(this);

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
}

void battlemap::drawBox(QPen pen, int x, int y)
{
    QPainter painter(this);
    painter.setPen(pen);

}
