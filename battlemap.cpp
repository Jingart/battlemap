#include "battlemap.h"
#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>
#include <vector>
#include <QDesktopWidget>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//BattlemapTile ***bmmatrix;
vector<vector<BattlemapTile> > bmmatrix;
int bmmatrix_rows = 5;
int bmmatrix_columns = 5;
const int tiledim = 100;

battlemap::battlemap(QWidget *parent)
                    : QWidget(parent)
{
    InitializeMatrix();
}

battlemap::battlemap(QWidget *parent, int rows, int columns)
: QWidget(parent)
{

    InitializeMatrix();
}

battlemap::battlemap(int rows, int columns)
{

    InitializeMatrix();
}

void battlemap::InitializeMatrix()
{

    QPoint center = WindowCenter();
    bool shiftrow = false;

    // Create new tiles and set relative position between each tile column and row
    int pos_x = 50;
    int pos_y = 50;

    int tile_width = 100;

    bmmatrix.resize(bmmatrix_rows);
    for (int i = 0; i < bmmatrix_rows; ++i)
      bmmatrix[i].resize(bmmatrix_columns);

    for(int i = 0; i < bmmatrix_rows; i++)
    {

        for(int j = 0; j < bmmatrix_columns; j++)
        {
            BattlemapTile bm(pos_x, pos_y);
            bmmatrix[i][j] = bm;
            pos_x += tiledim;
        }

        pos_y += tile_width/2 * 1.6;//tiledim - (tiledim / 3);

        if (shiftrow == false)
        {
            pos_x = 100;
            shiftrow = true;

        }else
        {
            pos_x = 50;
            shiftrow = false;
        }
    }
}

void battlemap::resizeEvent(QResizeEvent * event)
{


}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPen pen(Qt::black, 2, Qt::SolidLine);
  QPainter painter(this);
  BattlemapTile bm;
  char buff[30];

  QPoint center = WindowCenter();

  painter.setPen(pen);

  painter.drawEllipse(center,10, 10);

  for(int i = 0; i < bmmatrix_rows; i++)
  {
      for(int j = 0; j < bmmatrix_columns; j++)
      {
          /*
          bm = bmmatrix[i][j];
          //bm.AddToPosition(center.x() - (bmmatrix_rows / 2 * tiledim), center.y() - (bmmatrix_columns / 2 * tiledim));
          //bm.AddToPosition(center.x(), center.y());
          painter.drawLine(bm.ltop, bm.rtop);
          painter.drawLine(bm.rtop, bm.rbottom);
          painter.drawLine(bm.rbottom, bm.lbottom);
          painter.drawLine(bm.lbottom, bm.ltop);
          */

          bm = bmmatrix[i][j];
          painter.drawLine(bm.p1, bm.p2);
          painter.drawLine(bm.p2, bm.p3);
          painter.drawLine(bm.p3, bm.p4);
          painter.drawLine(bm.p4, bm.p5);
          painter.drawLine(bm.p5, bm.p6);
          painter.drawLine(bm.p6, bm.p1);


      }
  }

  // Write coords to window, debug
  /*
  itoa (bmmatrix[0][0].ltop.x(),buff,10);
  painter.drawText(400,100, buff);

  itoa (bmmatrix[0][0].ltop.y(),buff,10);
  painter.drawText(400,120, buff);

  itoa (center.x(),buff,10);
  painter.drawText(430,100, buff);

  itoa (center.y(),buff,10);
  painter.drawText(430,120, buff);


  itoa (bm.p2.x(),buff,10);
  painter.drawText(470,100, buff);

  itoa (bm.p2.y(),buff,10);
  painter.drawText(470,120, buff);

  itoa (bm.p3.x(),buff,10);
  painter.drawText(510,100, buff);

  itoa (bm.p3.y(),buff,10);
  painter.drawText(510,120, buff);


  itoa (bm.p4.x(),buff,10);
  painter.drawText(550,100, buff);

  itoa (bm.p4.y(),buff,10);
  painter.drawText(550,120, buff);
*/

  //drawMapWindow();
  /*
  painter.setPen(pen);
  painter.drawLine(20, 40, 250, 40);

  pen.setStyle(Qt::DashLine);
  painter.setPen(pen);
  painter.drawLine(20, 80, 250, 80);

  QVector<qreal> dashes;
  qreal space = 4;

  dashes << 1 << space << 5 << space;

  pen.setStyle(Qt::CustomDashLine);
  pen.setDashPattern(dashes);
  painter.setPen(pen);
  painter.drawLine(20, 240, 250, 240);
  */
}

QPoint battlemap::WindowCenter()
{
    QSize windowSize;
    windowSize = size();
    int centerx = windowSize.width() / 2;
    int centery = windowSize.height() / 2;
    return QPoint(centerx, centery);
}


void battlemap::drawMapWindow()
{


    int width = 500;
    int height = 400;
    int winwidth = 0;
    int winheight = 0;

    QPen pen_black(Qt::black, 1, Qt::SolidLine);
    QPen pen_white(Qt::white, 1, Qt::SolidLine);

    QPainter painter(this);
    BattlemapTile bm;

    painter.setPen(pen_black);

    int startx = winwidth / 3;
    int starty = winheight / 3;

    painter.drawLine(startx, starty, startx + width, starty);
    painter.drawLine(startx + width, starty, startx + width, starty + height);
    painter.setPen(pen_white);
    painter.drawLine(startx + width, starty + height, startx, starty + height);
    painter.drawLine(startx, starty + height, startx, starty);


}

void battlemap::drawBox(QPen pen, int x, int y)
{
    QPainter painter(this);
    painter.setPen(pen);

}
