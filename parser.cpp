#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
 
int main()
{
int width,height;
int i,j;
int n;
int **cords, **window ;


fstream tFile("input.txt",ios::in | ios::out | ios::ate);
tFile.close();
 
tFile.open("input.txt");
while(!tFile.eof())
{
	tFile >> width >> height;
	
	cords = (int**)malloc(width * sizeof(int*));
    for (i=0; i<width; i++ ) 
        cords[i] = (int*)malloc(height * sizeof(int)); 
	
	for(i = 0;i<width;i++)
	{
		for(j = 0;i<height;j++)
		{
			tFile >> cords[i][j];
		}
		
	}
	
	tFile >> n;
	
	window = (int**)malloc(n * sizeof(int*));
    for (i=0; i<width; i++ ) 
        window[i] = (int*)malloc(height * sizeof(int));
	
	for(i = 0;i<n;i++)
	{
		for(j = 0;i<height;j++)
		{
			tFile >> window[i][j];
		}
		
	}
	
}

cout<<width<<height;
for(i = 0;i<width;i++)
	{
		for(j = 0;i<height;j++)
		{
			cout << cords[i][j];
		}
		
	}

tFile.close();
 
system("PAUSE");
return 0;
}
