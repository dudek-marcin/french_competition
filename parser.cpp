#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
 
int main()
{
unsigned int width,height;
unsigned int i,j;
unsigned int n;
unsigned short int **cords, **window ;


fstream tFile("input.txt",ios::in | ios::out | ios::ate);
tFile.close();
 
tFile.open("input.txt");
if (tFile.good())
{
	tFile >> width >> height;

    cords = new unsigned short int * [width]; 
    for (i = 0; i<width; i++)
        cords[i] = new unsigned short int [height];
	
	for(i = 0;i<height;i++)
	{
		for(j = 0;j<width;j++)
		{
			tFile >> cords[i][j];
				
		}
		
	
	}
	
	tFile >> n;
	
	window = new unsigned short int * [n]; 
    for (i = 0; i<n; i++)
        window[i] = new unsigned short int [4];
	
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<4;j++)
		{
			tFile >> window[i][j];
		}
	}
	
}
tFile.close();

system("PAUSE");
return 0;
}
