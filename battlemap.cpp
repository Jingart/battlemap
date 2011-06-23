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
    //QDesktopWidget *desktop = QApplication::desktop();
    //int screenWidth = desktop->width();
    //int screenHeight = desktop->height();
    QPoint center = WindowCenter();

    int startpos_x = center.x();// - (bmmatrix_rows * tiledim);;
    int startpos_y = center.y();// - (bmmatrix_columns * tiledim);;
    int spacer_x = startpos_x;
    int spacer_y = startpos_y;

    bmmatrix.resize(bmmatrix_rows);
    for (int i = 0; i < bmmatrix_rows; ++i)
      bmmatrix[i].resize(bmmatrix_columns);

    for(int i = 0; i < bmmatrix_rows; i++)
    {

        for(int j = 0; j < bmmatrix_columns; j++)
        {
            BattlemapTile bm(spacer_x, spacer_y);
            bmmatrix[i][j] = bm;
            spacer_x += tiledim;
        }

        spacer_y += tiledim;
        spacer_x = startpos_x;
    }
}

void battlemap::paintEvent(QPaintEvent *event)
{

  QPen pen(Qt::black, 2, Qt::SolidLine);
  QPainter painter(this);
  BattlemapTile bm;

  QPoint center = WindowCenter();

  painter.setPen(pen);

  painter.drawEllipse(center,10, 10);

  for(int i = 0; i < bmmatrix_rows; i++)
  {
      for(int j = 0; j < bmmatrix_columns; j++)
      {
          bm = bmmatrix[i][j];
          //bm.AddToPosition(center.x() - (bmmatrix_rows * tiledim), center.y() - (bmmatrix_columns * tiledim));
          bm.AddToPosition(center.x() - 400, center.y() - 400);
          painter.drawLine(bm.ltop, bm.rtop);
          painter.drawLine(bm.rtop, bm.rbottom);
          painter.drawLine(bm.rbottom, bm.lbottom);
          painter.drawLine(bm.lbottom, bm.ltop);

      }
  }


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
