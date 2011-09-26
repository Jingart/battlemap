#ifndef CLICKSTATUS_H
#define CLICKSTATUS_H
#include <QPoint>

class ClickStatus
{
public:
    ClickStatus();
    bool isTileSelected;
    int clickI;
    int clickJ;
    QPoint clickPoint;
    //void getIsTileSelected();
};

#endif // CLICKSTATUS_H
