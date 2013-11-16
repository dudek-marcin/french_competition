#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "parser.h"
using namespace std;

void readTable(USI **ppnCoord,USI **pnWindow, USI *pnWidth,USI *pnHeight,USI *pnNbWindow)
{
    USI i,j;
    USI *pCoord = NULL;

    fstream tFile("input2.txt",ios::in);
    if (tFile.good())
    {
        // Get the size of the array
        tFile >> *pnWidth >> *pnHeight;
        // Allocate thearray  to store the values
        pCoord = new USI[(*pnHeight) * (*pnWidth)];

        for(i = 0;i<(*pnHeight);i++)
        {
            for(j = 0;j<(*pnWidth);j++)
            {
                USI abc;
                tFile >> abc;
                pCoord[i*(*pnWidth) + j] = abc;
            }
        }
        // Read the number of windows
        tFile >> (*pnNbWindow);
        // Allocate the array of windows
        *pnWindow = new USI[(*pnNbWindow)*4];

        for(i = 0;i<(*pnNbWindow);i++)
        {
            for(j = 0;j<4;j++)
            {
                tFile >> (*pnWindow)[i*4 + j];
            }
        }
    }
    tFile.close();
    *ppnCoord = pCoord;
}
