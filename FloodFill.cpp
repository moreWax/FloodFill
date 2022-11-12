/**
* Thomas Whitworth
* FloodFill.cpp
**/

#include <iostream>
#include <queue>
#include <memory>
#include "FloodFill.h"
#include "OrderedPair.h"

void displayColumnNumbers(int imageSize);
void displayRowNumber(int rowNumber);

FloodFill::FloodFill(int size)
{
    // Guard against negative integers being placed into imageSize
    assert(size >= 0);

    imageSize = size;

    imagePtr = std::make_unique<std::unique_ptr<char[]>[]>(imageSize);
    for (int i = 0; i < imageSize; i++)
    {
        imagePtr[i] = std::make_unique<char[]>(imageSize);
    }
}

void FloodFill::generateImage(int size)
{
    assert(size >= 0);

    // resize image if needed
    if (size != imageSize)
    {
        imageSize = size;

        imagePtr = std::make_unique<std::unique_ptr<char[]>[]>(imageSize);

        for (int i = 0; i < imageSize; i++)
        {
            imagePtr[i] = std::make_unique<char[]>(imageSize);
        }

    }

    // seed random number generator
    srand((unsigned) time(nullptr));

    for (int i = 0; i < imageSize; i++)
    {
        for (int j = 0; j < imageSize; j++)
        {
            // random number between 0 and 3
            int random = 0 + (rand() % 4);

            switch (random)
            {
                case 0:
                    imagePtr[i][j] = color::coal;
                    break;
                case 1:
                    imagePtr[i][j] = color::mahogany;
                    break;
                case 2:
                    imagePtr[i][j] = color::yellow;
                    break;
                case 3:
                    imagePtr[i][j] = color::kaliBlue;
                    break;
                default:
                    imagePtr[i][j] = color::blank;
            }
        }
    }
}

void displayColumnNumbers(int imageSize)
{
    std::cout << "  ";
    for (int i = 0; i < imageSize; i++)
    {
        // wraps number line so colNumber is always 1 - 9.
        int colNumber = i;
        if (colNumber > 9) { colNumber %= 10; }
        std::cout << colNumber << ' ';
    }
    std::cout << std::endl;
}

void displayRowNumber(int rowNumber)
{
    // wraps number line so rowNumber is always 1 - 9.
    if (rowNumber > 9) { rowNumber %= 10; }
    std::cout << rowNumber << ' ';
}

void FloodFill::displayImage()
{
    displayColumnNumbers(imageSize);

    for (int i = 0; i < imageSize; i++)
    {
        // display row number
        displayRowNumber(i);

        // display color
        for (int j = 0; j < imageSize; j++)
            std::cout << imagePtr[i][j] << ' ';
        std::cout << std::endl;
    }
}

void FloodFill::fill(int row, int col, char newColor)
{
    std::queue<OrderedPair> queue;

    // original pixel color at indicated [row, col] where fill begins.
    char matchColor = imagePtr[row][col];

    OrderedPair oP(row, col);

    // enqueue the pixel at position [row][col] for processing.
    queue.push(oP);

    // while queue is not empty:
    while (!queue.empty())
    {
        // peek the front of queue to retain the value locally.
        OrderedPair currentPixel = queue.front();

        // dequeue the pixel off the queue
        queue.pop();

        // if currentPixel's color doesn't match, matchColor, don't do anything.
        if (imagePtr[currentPixel.getRow()][currentPixel.getCol()] != matchColor)
        {
            continue;
        }
        else
        {
            // if currentPixel's color does match, matchColor process currentPixel:

            // set currentPixel's to newColor
            imagePtr[currentPixel.getRow()][currentPixel.getCol()] = newColor;

            // check square directly to the right of currentPixel, and start recursively processing in that direction.
            queue.push(OrderedPair(currentPixel.getRow() + 1, currentPixel.getCol()));

            // check square directly to the left of currentPixel, and start recursively processing in that direction.
            queue.push(OrderedPair(currentPixel.getRow() - 1, currentPixel.getCol()));

            // check square directly below currentPixel, and start recursively processing in that direction.
            queue.push(OrderedPair(currentPixel.getRow(), currentPixel.getCol() + 1));

            // check square directly above currentPixel, and start recursively processing in that direction.
            queue.push(OrderedPair(currentPixel.getRow(), currentPixel.getCol() - 1));
        }
    }
}
