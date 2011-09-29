#include "selectedtile.h"


const int NOT_SELECTED = -1;

SelectedTile::SelectedTile()
{

    isTileSelected = false;
    clickI = NOT_SELECTED;
    clickJ = NOT_SELECTED;
}

void SelectedTile::setSelected(int row, int column)
{
    clickI = row;
    clickJ = column;
    isTileSelected = true;
}

void SelectedTile::setDeselected()
{

    if(isTileSelected)
    {
        clickI = NOT_SELECTED;
        clickJ = NOT_SELECTED;
        isTileSelected = false;
    }
}

