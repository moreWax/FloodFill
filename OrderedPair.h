/**
* Thomas Whitworth
* OrderedPair.h
**/

#ifndef FLOODFILL_ORDEREDPAIR_H
#define FLOODFILL_ORDEREDPAIR_H

class OrderedPair
{
private:

    /**
    * @member_variable row: (int)           Represents the row index for OrderedPair
    **/
    int row;

    /**
    * @member_variable column: (int)        Represents the column index for OrderedPair
    **/
    int column;

public:

    /**
    * OrderedPair()                         Default constructor; sets row, and column to zero.
    **/
    OrderedPair();

    /**
    * OrderedPair(int, int) \n\n            Parameterized constructor; Initializes a new OrderedPair
    *                                       with parameterized values aRow, aCol.
    *
    * @param aRow: (int)                    Row index in the OrderedPair.
    * @param aColumn: (int)                 Column index in the OrderedPair.
    **/
    OrderedPair(int aRow, int aColumn);

    /**
    * getRow(): int \n\n                    Returns the row index of the OrderedPair
    * @return OrderedPair.row (int)
    **/
    int getRow() const;

    /**
    * getCol(): int \n\n                    Returns the column index of the OrderedPair
    * @return OrderedPair.column (int)
    **/
    int getCol() const;

};


#endif //FLOODFILL_ORDEREDPAIR_H
