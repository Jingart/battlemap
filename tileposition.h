#ifndef TILEPOSITION_H
#define TILEPOSITION_H

class TilePosition
{
public:
    TilePosition();   
    TilePosition(int row, int column);
    int row;
    int column;
    bool found();
};

#endif // TILEPOSITION_H
