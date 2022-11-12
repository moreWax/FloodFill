/**
* Thomas Whitworth
* OrderedPair.cpp
**/

#include "OrderedPair.h"

OrderedPair::OrderedPair() : row(0), column(0)
{}

OrderedPair::OrderedPair(int aRow, int aColumn) : row(aRow), column(aColumn)
{}

int OrderedPair::getRow() const
{
    return row;
}

int OrderedPair::getCol() const
{
    return column;
}