#include "tileposition.h"

TilePosition::TilePosition()
{
}

TilePosition::TilePosition(int row, int column)
{
    this->row = row;
    this->column = column;
}

bool TilePosition::found()
{
    bool result = false;
    if(row != -1 || column != -1)
        result = true;

    return result;
}
