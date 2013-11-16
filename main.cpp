#include <iostream>
#include <fstream>

using namespace std;

#include "src/parser.h"

int main()
{
    int nWidth = 4;
    int nHeight = 4;
    unsigned short int **nWindow = NULL;

    int nNbVal = 3;
    unsigned short int **nCoord = NULL;

    readTable(&nCoord,&nWindow,&nWidth,&nHeight,&nNbVal);

// PRINT WHAT YOU GET
    std::cout << "Width:" << nWidth << std::endl;
    std::cout << "Height:" << nHeight << std::endl;
    std::cout << "Number of Windows:" << nNbVal << std::endl;
    for(int i = 0;i<nWidth;i++)
        {
            for(int j = 0;j<nHeight;j++)
            {
                std::cout << nCoord[i][j] << " ";
            }
            std::cout << std::endl;
        }

     for(int i = 0;i<nNbVal;i++)
        {
            for(int j = 0;j<4;j++)
            {
                std::cout << nWindow[i][j] << " ";
            }
            std::cout << std::endl;
        }
    getchar();
// END OF PRINT
    int nResult[3];
    unsigned int x;
    unsigned int y;
    int nNbValues;
    int nSum;
    std::filebuf fb;
    fb.open ("output.txt",std::ios::out);
    std::ostream os(&fb);

    for(int i=0;i < nNbVal ;i++)
    {
        nSum = 0;
        nNbValues = 0;
        for(x = nWindow[i][0] ; x <= nWindow[i][2] ; x++)
        {
            for(y = nWindow[i][1] ;y <= nWindow[i][3] ; y++)
            {
                nSum += nCoord[y][x];
                nNbValues++;
            }
        }
        nResult[i] = (float) nSum/ (float) nNbValues + 0.5;
        os << nResult[i] << "\n";
        std::cout << nResult[i] << "\n";
        getchar();
    }

    fb.close();
    return 0;
}
