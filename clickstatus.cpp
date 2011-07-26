#include "clickstatus.h"


const int NOT_SELECTED = -1;

ClickStatus::ClickStatus()
{

    isTileSelected = false;
    clickI = NOT_SELECTED;
    clickJ = NOT_SELECTED;
}

/*
bool ClickStatus::getIsTileSelected()
{
    return isTileSelected;
}

void ClickStatus::setIsTileSelected(bool value)
{
    isTileSelected = value;
}
*/
