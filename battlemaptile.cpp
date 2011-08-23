#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>

int top = 0;
int left = 0;
int right = 100;
int bottom = 100;

/*
QPoint ltop;
QPoint rtop;
QPoint lbottom;
QPoint rbottom;*/

/*TODO*/
// eventuell armystatus
// objectivs
// terrengtype
// eventuelle bitmaps

BattlemapTile::BattlemapTile()
{
    InitPosition();
}

BattlemapTile::BattlemapTile(int spacer_x, int spacer_y)
{
    InitPosition(spacer_x, spacer_y);
}

void BattlemapTile::InitPosition(int x, int y)
{
    ltop.setX(left + x);
    ltop.setY(top + y);

    rtop.setX(right + x);
    rtop.setY(top + y);

    lbottom.setX(left + x);
    lbottom.setY(bottom + y);

    rbottom.setX(right + x);
    rbottom.setY(bottom + y);
}

void BattlemapTile::InitPosition()
{
    InitPosition(0, 0);
}
