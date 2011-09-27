#include "selectedtile.h"


const int NOT_SELECTED = -1;

SelectedTile::SelectedTile()
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
