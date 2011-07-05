#include "battlemap.h"
#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>
#include <vector>
#include <QDesktopWidget>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <QMessageBox>

using namespace std;

vector<vector<BattlemapTile> > bmmatrix;
int bmRows_ = 3;
int bmColumns_ = 5;
const int tiledim = 100;

// Clicked tile vars, class?
bool isTileSelected = false;
int clickI_ = -1;
int clickJ_ = -1;
QPoint click;

battlemap::battlemap(QWidget *parent)
                    : QWidget(parent)
{
    InitializeMatrix();
}

battlemap::battlemap(QWidget *parent, int rows, int columns)
: QWidget(parent)
{
    bmRows_ = rows;
    bmColumns_ = columns;
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
    int pos_x = 0;
    int pos_y = 0;

    int tile_width = 100;

    bmmatrix.resize(bmRows_);
    for (int i = 0; i < bmRows_; ++i)
      bmmatrix[i].resize(bmColumns_);

    for(int i = 0; i < bmRows_; i++)
    {

        for(int j = 0; j < bmColumns_; j++)
        {
            BattlemapTile bm(pos_x, pos_y);
            bmmatrix[i][j] = bm;
            pos_x += tiledim + 5;
        }

        pos_y += tile_width/2 * 1.7;//tiledim - (tiledim / 3);

        if (shiftrow == false)
        {
            pos_x = 52.5;
            shiftrow = true;

        }else
        {
            pos_x = 0;
            shiftrow = false;
        }
    }
}

void battlemap::mousePressEvent(QMouseEvent *event)
{
    click = event->pos();
    BattlemapTile bm;

    // Deselect if tile is selected
    if(isTileSelected)
    {
        bmmatrix[clickI_][clickJ_].bordercolor = Qt::black;
        clickI_ = -1;
        clickJ_ = -1;
        isTileSelected = false;
    }

    // Set color on clicked tile
    if(event->button() == Qt::LeftButton)
    {
        for(int i = 0; i < bmRows_; i++)
        {
            for(int j = 0; j < bmColumns_; j++)
            {

                bm = bmmatrix[i][j];
                if(bm.IsTileAt(event->pos()))
                {
                    clickI_ = i;
                    clickJ_ = j;
                    bm.bordercolor = Qt::red;
                    bmmatrix[clickI_][clickJ_].bordercolor = Qt::red;
                    isTileSelected = true;
                    break;
                }
            }
        }
    }

    repaint();
}

void battlemap::resizeEvent(QResizeEvent *event)
{

    //QMessageBox msgBox;
    //itoa(event->pos().x(),buff,10);
    //msgBox.setText("The document has been modified.");
    //msgBox.exec();
}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPainter painter(this);
  BattlemapTile bm;

  QPoint center = WindowCenter();

  QPen peny(bm.bordercolor, 2, Qt::SolidLine);
  painter.setPen(peny);
  painter.drawEllipse(click,10, 10);

  //painter.setPen(pen);
  //painter.drawEllipse(center,10, 10);

  for(int i = 0; i < bmRows_; i++)
  {
      for(int j = 0; j < bmColumns_; j++)
      {
          bm = bmmatrix[i][j];
          QPen pen(bm.bordercolor, 2, Qt::SolidLine);
          painter.setPen(pen);
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
