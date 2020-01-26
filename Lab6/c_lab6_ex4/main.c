#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "conio.c"

char* MlineEditor(int ySize ,int size , int xpos , int ypos , char sRange , char eRange)
{
    int i , col=0 , cond = xpos+size , start = xpos , starty = ypos , endY = ypos+ySize;
    char* pcurrent , *plast , *arr ;
    char ch ;

    arr = (char *)malloc(ySize*sizeof(char));
    pcurrent = arr;
    plast = arr+size;
    int Flag=0;

    gotoxy(xpos,ypos);
    textattr(0x70);

    for(i=0;i<size;i++)
    {
        cprintf(" ");
    }

    do
    {
        gotoxy(xpos , ypos);
        textattr(0x70);
        ch=getch();
        switch(ch)
        {
        case -32:
            ch = getch();
            switch(ch)
            {

            case 0x4B :   //Left
                if(pcurrent>arr)
                {
                    gotoxy(--xpos,ypos);
                    pcurrent--;
                    //col--;
                }
            break;
            case 0x48 :   //up
                xpos = start;
                if(ypos>starty)
                    {
                        gotoxy(xpos,--ypos);
                    }
            break;
            case 0x50 :   //down
                xpos = start;
                if(ypos<endY-1)
                    {
                        gotoxy(xpos,ypos++);
                    }
            break;
            case 0x4D :   //Right
                if(pcurrent<plast)
                {
                    gotoxy(++xpos,ypos);
                    pcurrent++;
                   // col++;
                }
            break;
            case 0x47 :   //home
                xpos = start;
                gotoxy(xpos,ypos);
                pcurrent = arr;
            break;
            case 0x4F :   //end
                start+=col;
                gotoxy(start,ypos);
                pcurrent = arr+col;
            break;
            }
        break;
        case 0x09 :   //tab
            xpos = start;
            if(ypos<endY-1)
                {
                    gotoxy(xpos,ypos++);
                }
        break;

        case 0x0D:
            arr[col] = '\0';
            Flag=1;
        break;

        case 0x1B:
            arr[0] = '\0';
            Flag=1;
        break;

        default:
                if(ch>=sRange && ch<=eRange)
                {

                    if(xpos<(cond))
                    {
                        *pcurrent = ch;
                        cprintf("%c" , ch);
                        pcurrent++;
                        xpos+=1;
                        col++;
                    }
                }
        }
    }
    while(Flag==0);
    textattr(0x07);
 return arr;
}

int main()
{
    int size , ySize , xpos , ypos ;
    char sRange , eRange , *arr;

    printf("Enter size of line : "); scanf("%i" , &size);
    printf("Enter number of lines : "); scanf("%i" , &ySize);
    printf("Enter xPos of line : "); scanf("%i" , &xpos);
    printf("Enter Ypos of line : "); scanf("%i" , &ypos);
    printf("Enter StartRange of Characters : "); sRange = getche(); printf("\n");
    printf("Enter EndRange of Characters : "); eRange = getche();
    system("cls");
    arr = MlineEditor(ySize,size,xpos,ypos,sRange,eRange);
    system("cls");
    printf("%s" , arr);
    free(arr);
}
