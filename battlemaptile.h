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

    QPoint p1;
    QPoint p2;
    QPoint p3;
    QPoint p4;
    QPoint p5;
    QPoint p6;

    BattlemapTile();
    BattlemapTile(int spacer_x, int spacer_y);
    void InitPosition();
    void InitPosition(int x, int y);
    void AddToPosition(int addx, int addy);
    void UpdatePosition(int x, int y);

private:
    void SetInitPosition(int x, int y);
};

#endif // BATTLEMAPTILE_H
