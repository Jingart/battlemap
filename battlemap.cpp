#include "battlemap.h"
#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>
#include <vector>
#include <QDesktopWidget>

using namespace std;

//BattlemapTile ***bmmatrix;
vector<vector<BattlemapTile> > bmmatrix;
int bmmatrix_rows = 3;
int bmmatrix_columns = 3;

battlemap::battlemap(QWidget *parent)
                    : QWidget(parent)
{

}

battlemap::battlemap(int rows, int columns)
{

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int startpos_x = 200;
    int startpos_y = 200;
    int spacer_x = startpos_x;
    int spacer_y = startpos_y;
    const int tiledimension = 100;

    bmmatrix.resize(bmmatrix_rows);
    for (int i = 0; i < bmmatrix_rows; ++i)
      bmmatrix[i].resize(bmmatrix_columns);

    //BattlemapTile *bm = new BattlemapTile();
    for(int i = 0; i < bmmatrix_rows; i++)
    {

        for(int j = 0; j < bmmatrix_columns; j++)
        {
            BattlemapTile bm(spacer_x, spacer_y);
            bmmatrix[i][j] = bm;
            spacer_x += tiledimension;
        }

        spacer_y += tiledimension;
        spacer_x = startpos_x;
    }
}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPen pen(Qt::black, 2, Qt::SolidLine);
  QPainter painter(this);
  BattlemapTile bm;

  painter.setPen(pen);

  for(int i = 0; i < bmmatrix_rows; i++)
  {
      for(int j = 0; j < bmmatrix_columns; j++)
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
