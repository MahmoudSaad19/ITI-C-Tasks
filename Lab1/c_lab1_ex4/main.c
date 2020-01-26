#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int rowNumber , columnNumber , counter , size ;

void main()
{
    printf("Enter the size : \n");
    scanf("%d",&size);
    if (size%2 !=0 )
        magicBox(size);
    else
        printf("sorry the size should be odd");
}

void magicBox (int sizeNumber)
{
    int numberOfBlocks ;
    size = sizeNumber ;
    numberOfBlocks = size * size ;
    rowNumber = 1;
    columnNumber = size/2 + 1 ;
    for(counter = 1 ; counter <= numberOfBlocks ; counter++)
    {
        gotoxy(columnNumber*4,rowNumber*4);
        printf("%d",counter);
        if (counter%size==0)
        {
            increaseRow();
        }
        else
        {
            decreaseBoth();
        }
    }
}

void increaseRow ()
{
    rowNumber++;

    if (rowNumber > size)
        rowNumber=1;

}


void decreaseBoth ()
{
    rowNumber--;
    columnNumber--;
    if (rowNumber <1)
        rowNumber=size;


    if (columnNumber <1)
        columnNumber=size;

}

void gotoxy(int x, int y)
{
  COORD c;

  c.X =  x - 1;
  c.Y =  y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
