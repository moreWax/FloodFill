/**
* Thomas Whitworth
* FloodFill.h
**/

#include <memory>
#ifndef FLOODFILL_FLOODFILL_H
#define FLOODFILL_FLOODFILL_H


class FloodFill
{

    /**
    * @member_variable imagePtr (std::unique_ptr<std::unique_ptr<char[]>[]>)
    *
    *     Managed pointer to a 2-dimensional character
    *     array on the heap which makes up the image.
    **/
    std::unique_ptr<std::unique_ptr<char[]>[]> imagePtr;

    /**
    * @member_variable imageSize (int)      Holds the size of the image;
    **/
    int imageSize;

    /**
    * @member_variable color (abstract type: color), (concrete type: char)
    *
    *      Enumerated type that holds four color
    *      values along with a blank value.
    **/
    enum color
    {
        coal = 'c',
        mahogany = 'm',
        yellow = 'y',
        kaliBlue = 'k',
        blank = ' '
    };

public:

    /**
    * FloodFill(int) \n\n                   Parameterized constructor; Allocates memory for
    *                                       the new image of your chosen size.
    *
    * @param size: (int)                    size of the image being constructed
    * @pre size > 0:                        size needs to be greater than or equal to 0.
    **/
    FloodFill(int size);

    /**
    * generateImage(int): void \n\n         Creates a new array pointed to by imagePtr of size int.
    *                                       Randomly populates imagePtr with a single character
    *                                       there are 4 different character values.
    *
    * @param size: (int)                    size of the image being generated.
    * @pre if size > 0:                     size needs to be greater than or equal to 0.
    * @pre if size != imageSize:            imagePtr will resize image to the new size.
    * @return (void)
    **/
    void generateImage(int size);

    /**
    * displayImage(): void \n\n             Displays the current chars in the array pointed to by imagePtr.
    *                                       Method also displays numbered X and Y axis.
    *
    * @param size: (int)                    size of the image being generated.
    * @pre size > 0:                        size needs to be greater than or equal to 0.
    * @pre size > 0:                        size needs to be greater than or equal to 0.
    * @return (void)
    **/
    void displayImage();

    /**
    * fill(int, int, char): void \n\n       Flood fills beginning at [row][col] and replacing color
    *                                       there with newColor.
    *
    *                                       Beginning at [row][col] I will flood fill and replace
    *                                       (whatever color is currently at [row[col]) with newColor.
    *
    * @param row: (int)                     row of the OrderedPair that is being operated on.
    * @param col: (int)                     col of the OrderedPair that is being operated on.
    * @param newColor: (char)               color that will replace matchColor if condition are met.
    * @member_variable: matchColor (char)   color of the square where fill begins.
    * @return (void)
    **/
    void fill(int row, int col, char newColor);

};


#endif //FLOODFILL_FLOODFILL_H
