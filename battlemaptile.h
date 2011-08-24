#ifndef BATTLEMAPTILE_H
#define BATTLEMAPTILE_H
#include <QPainter>

class BattlemapTile
{
public:
    QPoint ltop;
    QPoint rtop;
    QPoint lbottom;
    QPoint rbottom;

    BattlemapTile();
    BattlemapTile(int spacer_x, int spacer_y);
    void InitPosition();
    void InitPosition(int x, int y);
    void AddToPosition(int addx, int addy);
};

#endif // BATTLEMAPTILE_H
