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

    QColor borderColor;

    BattlemapTile();
    BattlemapTile(int spacer_x, int spacer_y);
    bool IsTileAt(QPoint point);

    void InitPosition();
    void InitPosition(int x, int y);
    void AddToPosition(int addx, int addy);
    void UpdatePosition(int x, int y);

    double GetSlopeDegree();
    QColor GetBorderColor();
    void SetBorderColor(QColor color);

private:
    double slopeDegree;
    void SetInitPosition(int x, int y);
    bool IsInsideVerticalTileSide(QPoint point);
    bool IsInsideHorizontalTileSide(QPoint point);
    bool IsInsideLeftTileSide(QPoint point);
    bool IsInsideLeftAndUpperLowerSlope(QPoint point);
    bool IsInsideRightUpperLowerSlope(QPoint point);
};

#endif // BATTLEMAPTILE_H
