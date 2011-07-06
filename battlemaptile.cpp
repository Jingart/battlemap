#include "battlemaptile.h"
#include <QApplication>
#include <QPainter>
#include <math.h>

int top = 0;
int left = 0;
int right = 100;
int bottom = 100;
//double a;
int hex_baselength = 100;


/*TODO*/
// eventuell armystatus
// objectivs
// terrengtype
// eventuelle bitmaps


BattlemapTile::BattlemapTile()
{
    //InitPosition();
    //SetInitPosition();
}


BattlemapTile::BattlemapTile(int tile_x, int tile_y)
{
    //InitPosition(spacer_x, spacer_y);
    SetInitPosition(tile_x, tile_y);
    borderColor = Qt::black;
    slopeDegree = (double)(p2.y() - p1.y()) / ((p2.x() - p1.x()) - 0);
}


// Set initial postition for Square
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


// Set initial postition for Hexagon
void BattlemapTile::SetInitPosition(int x, int y)
{
    int w = hex_baselength / 2;
    int r = hex_baselength / 4;
    double h = sqrt(pow(double(w),2) + pow(double(r),2));

    p1.setX(x);
    p1.setY(y);

    p2.setX(p1.x() + w);
    p2.setY(p1.y() - r);

    p3.setX(p2.x() + w);
    p3.setY(p2.y() + r);

    p4.setX(p3.x());
    p4.setY(p3.y() + (int)h);

    p5.setX(p4.x() - w);
    p5.setY(p4.y() + r);

    p6.setX(p5.x() - w);
    p6.setY(p5.y() - r);


}


void BattlemapTile::InitPosition()
{
    InitPosition(0, 0);
}


bool BattlemapTile::IsTileAt(QPoint point)
{
    bool result = false;

    // If point is inside vertical sides of tile
    if (point.x() < p3.x() && point.x() > p1.x())
    {
        // If point is inside horisontal sides of tile
        if (point.y() > p2.y() && point.y() < p5.y())
        {
            // If point inside left side of tile
            if (point.x() < p2.x())
            {
                int yUpper = slopeDegree * (point.x() - p1.x());
                int yLower = -slopeDegree * (point.x() - p6.x());

                // If inside left upper tileslope and inside left lower tileslope
                if (point.y() > yUpper + p1.y() && point.y() < yLower + p6.y())
                    result = true;

            }// If point inside right side of tile
            else
            {
                int yUpper = -slopeDegree * (point.x() - p2.x());
                int yLower = slopeDegree * (point.x() - p4.x());

                // If inside right upper tileslope and inside right lower tileslope
                if (point.y() > yUpper + p2.y() && point.y() < yLower + p4.y())
                    result = true;
            }
        }
    }

    return result;
}


// update
void BattlemapTile::UpdatePosition(int x, int y)
{

}


double BattlemapTile::GetSlopeDegree()
{
    return slopeDegree;
}


QColor BattlemapTile::GetBorderColor()
{
    return borderColor;
}


void BattlemapTile::SetBorderColor(QColor color)
{
    borderColor = color;
}


