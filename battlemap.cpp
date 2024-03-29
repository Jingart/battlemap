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
#include <QtDebug>

using namespace std;

vector<vector<BattlemapTile> > bmmatrix;
int bmRows_ = 3;
int bmColumns_ = 5;
int tileLength = 100;
int initpos_x = 150;
int initpos_y = 100;

const int NOT_SELECTED = -1;
const int NO_VALUE= -1;
const int VERTICAL_SPACING = 5;
const double HORIZONTAL_SPACING = 1.7;
const double SHIFTROW_SPACING = 2.5;
const double HALF_TILELENGTH = tileLength / 2;


Battlemap::Battlemap(QWidget *parent)
                    : QWidget(parent)
{
    InitializeMatrix();
}

/*
battlemap::battlemap(QWidget *parent, int rows, int columns)
: QWidget(parent)
{
    bmRows_ = rows;
    bmColumns_ = columns;
    InitializeMatrix();
}
*/

Battlemap::Battlemap(int rows, int columns)
{
    bmRows_ = rows;
    bmColumns_ = columns;
    clickStatus = new SelectedTile();
    destinationStatus = new SelectedTile();
    InitializeMatrix();
}

//destructor
//clickStatus
//bmmatrix
//BattlemapTile

void Battlemap::InitializeMatrix()
{

    bmmatrix.resize(bmRows_);
    for (int i = 0; i < bmRows_; ++i)
      bmmatrix[i].resize(bmColumns_);

    setupTile();

}

void Battlemap::setupTile()
{
    bool shiftrow = false;
    int tile_x = initpos_x;
    int tile_y = initpos_y;

    for(int i = 0; i < bmRows_; i++)
    {
        for(int j = 0; j < bmColumns_; j++)
        {
            BattlemapTile bm(tile_x, tile_y);
            bmmatrix[i][j] = bm;
            tile_x += tileLength + VERTICAL_SPACING;
        }

        tile_y += HALF_TILELENGTH * HORIZONTAL_SPACING;

        if (shiftrow == false)
        {
            tile_x = initpos_x;
            tile_x = tile_x - (HALF_TILELENGTH + SHIFTROW_SPACING);
            shiftrow = true;

        }else
        {
            tile_x = initpos_x;
            shiftrow = false;
        }
    }
}

void Battlemap::mousePressEvent(QMouseEvent *event)
{
    TilePosition tilePos;

    clickStatus->clickPoint = event->pos();
    resetTileSelect(clickStatus);

    if(event->button() == Qt::LeftButton)
    {
        tilePos = findTileAt(clickStatus->clickPoint);

        if(tilePos.found())
            setTileSelect(clickStatus, tilePos.row, tilePos.column, Qt::red);
    }

    repaint();
}

void Battlemap::resetTileSelect(SelectedTile *tileSelect)
{
    if(tileSelect->isTileSelected)
    {
        bmmatrix[tileSelect->clickI][tileSelect->clickJ].SetBorderColor(Qt::black);
        tileSelect->setDeselected();
    }
}

void Battlemap::setTileSelect(SelectedTile *tileSelect, int row, int column, QColor color)
{
        tileSelect->setSelected(row, column);
        bmmatrix[tileSelect->clickI][tileSelect->clickJ].SetBorderColor(color);
}



void Battlemap::resizeEvent(QResizeEvent *event)
{

    //QMessageBox msgBox;
    //itoa(event->pos().x(),buff,10);
    //msgBox.setText("The document has been modified.");
    //msgBox.exec();
}

void Battlemap::mouseMoveEvent(QMouseEvent *event)
{
    TilePosition tilePos;
    if(clickStatus->isTileSelected)
    {
        tilePos = findTileAt(event->pos());
        if((tilePos.row == NO_VALUE && tilePos.column == NO_VALUE) || (tilePos.row == clickStatus->clickI && tilePos.column == clickStatus->clickJ))
        {
            qDebug() << "no tile";
            //deselectTile2();
        }
        else
        {
            qDebug() << "tile found";
            //setTileSelected2(tilePos.row - 1, tilePos.column -1);
        }

        repaint();
    }


}

TilePosition Battlemap::findTileAt(QPoint point)
{
    TilePosition tilePos(NO_VALUE, NO_VALUE);

    for(int i = 0; i < bmRows_; i++)
    {
        for(int j = 0; j < bmColumns_; j++)
        {
            if(bmmatrix[i][j].IsTileAt(point))
            {
                tilePos.row = i;
                tilePos.column = j;
                break;
            }
        }
    }

    return tilePos;
}


void Battlemap::paintEvent(QPaintEvent *event)
{

  QPainter painter(this);
  BattlemapTile bm;
  char buff[30];

  //QPoint center = WindowCenter();

  QPen peny(bm.GetBorderColor(), 2, Qt::SolidLine);
  painter.setPen(peny);
  painter.drawEllipse(clickStatus->clickPoint,10, 10);

  //painter.setPen(pen);
  //painter.drawEllipse(center,10, 10);

  for(int i = 0; i < bmRows_; i++)
  {
      for(int j = 0; j < bmColumns_; j++)
      {
          bm = bmmatrix[i][j];
          QPen pen(bm.GetBorderColor(), 2, Qt::SolidLine);
          painter.setPen(pen);
          painter.drawLine(bm.p1, bm.p2);
          painter.drawLine(bm.p2, bm.p3);
          painter.drawLine(bm.p3, bm.p4);
          painter.drawLine(bm.p4, bm.p5);
          painter.drawLine(bm.p5, bm.p6);
          painter.drawLine(bm.p6, bm.p1);


      }
  }

  /*

  // Write coords to window, debug
  itoa (click.x(),buff,10);
  painter.drawText(400,400, buff);

  itoa (click.y(),buff,10);
  painter.drawText(420,400, buff);

  itoa (bmmatrix[1][1].p3.x(),buff,10);
  painter.drawText(400,420, buff);

  itoa (bmmatrix[1][1].p3.y(),buff,10);
  painter.drawText(420,420, buff);

  int y1 = bmmatrix[1][1].p2.y();
  int y2 = bmmatrix[1][1].p3.y();
  int x1 = 0;
  int x2 = bmmatrix[1][1].p3.x() - bmmatrix[1][1].p2.x();

  double t1 = (y2 - y1);
  double t2 = (x2 - x1);
  double a =  (double)t1 / t2;

  //int y = a*(x2 / 2);
  int y = -bmmatrix[1][1].GetSlopeDegree() * (x2 / 2);

  int yUpper = -bmmatrix[1][1].GetSlopeDegree() * (click.x() - bmmatrix[1][1].p2.x());

  itoa (yUpper + bmmatrix[1][1].p2.y(),buff,10);
  painter.drawText(440,420, buff);

  QPen pentest(Qt::red, 2, Qt::SolidLine);
  painter.setPen(pentest);
  painter.drawEllipse(bmmatrix[1][1].p2.x() + 25, y1 + y ,5, 5);
  */
}


QPoint Battlemap::findWindowCenter()
{
    QSize windowSize;
    windowSize = size();
    int centerx = windowSize.width() / 2;
    int centery = windowSize.height() / 2;
    return QPoint(centerx, centery);
}


void Battlemap::drawMapWindow()
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


void Battlemap::drawBox(QPen pen, int x, int y)
{
    QPainter painter(this);
    painter.setPen(pen);

}
