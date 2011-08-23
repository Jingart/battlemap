#include "battlemap.h"
#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>
#include <vector>

using namespace std;

//BattlemapTile ***bmmatrix;
vector<vector<BattlemapTile> > bmmatrix;

battlemap::battlemap(QWidget *parent)
                    : QWidget(parent)
{

}

battlemap::battlemap(int x, int y)
{
    //**bmmatrix
    // Set up sizes. (HEIGHT x WIDTH)
    int spacer_x = 0;
    int spacer_y = 0;

    bmmatrix.resize(10);
    for (int i = 0; i < 10; ++i)
      bmmatrix[i].resize(10);

    //BattlemapTile *bm = new BattlemapTile();
    for(int i = 0; i < 5; i++)
    {

        for(int j = 0; j < 10; j++)
        {
            BattlemapTile bm(spacer_x, spacer_y);
            bmmatrix[i][j] = bm;
            spacer_x += 100;
        }

        spacer_y += 100;
        spacer_x = 0;
    }
}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPen pen(Qt::black, 2, Qt::SolidLine);
  QPainter painter(this);
  BattlemapTile bm;

  painter.setPen(pen);

  for(int i = 0; i < 5; i++)
  {
      for(int j = 0; j < 10; j++)
      {
          bm = bmmatrix[i][j];

          painter.drawLine(bm.ltop, bm.rtop);
          painter.drawLine(bm.rtop, bm.rbottom);
          painter.drawLine(bm.rbottom, bm.lbottom);
          painter.drawLine(bm.lbottom, bm.ltop);

      }
  }










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
