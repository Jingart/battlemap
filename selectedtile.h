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
    void setSelected(int row, int column);
    void setDeselected();
};

#endif // CLICKSTATUS_H
