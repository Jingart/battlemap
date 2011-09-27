#ifndef SELECTEDTILE_H
#define SELECTEDTILE_H
#include <QPoint>

class SelectedTile
{
public:
    SelectedTile();
    bool isTileSelected;
    int clickI;
    int clickJ;
    QPoint clickPoint;
    //void getIsTileSelected();
};

#endif // CLICKSTATUS_H
