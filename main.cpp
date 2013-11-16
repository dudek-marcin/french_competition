#include <iostream>
#include <fstream>

using namespace std;

#include "src/parser.h"

int main()
{
    USI nWidth;
    USI nHeight;
    USI *nWindow = NULL;
    USI nNbVal;
    USI *nCoord = NULL;
    unsigned int x;
    unsigned int y;
    int nNbValues;
    int nSum;
    int nResult;
    std::filebuf fb;
    fb.open ("output.txt",std::ios::out);
    std::ostream os(&fb);

    readTable(&nCoord,&nWindow,&nWidth,&nHeight,&nNbVal);

// PRINT WHAT YOU GET
/*    std::cout << "Width:" << nWidth << std::endl;
    std::cout << "Height:" << nHeight << std::endl;
    std::cout << "Number of Windows:" << nNbVal << std::endl;
    getchar();
*/
// END OF PRINT

    for(int i=0;i < nNbVal ;i++)
    {
        nSum = 0;
        nNbValues = 0;
        for(x = nWindow[i*4 + 0] ; x <= nWindow[i*4 + 2] ; x++)
        {
            for(y = nWindow[i*4 + 1] ;y <= nWindow[i*4 + 3] ; y++)
            {
                nSum += nCoord[y *4 + x];
                nNbValues++;
            }
        }
        nResult = (float) nSum/ (float) nNbValues + 0.5;
        os << nResult  << "\n";
    }
    fb.close();
    return 0;
}
