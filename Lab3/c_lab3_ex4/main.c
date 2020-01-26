#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.c"

#define Enter 0x0d
#define Esc  0x1b
#define up 0x48
#define down 0x50
#define Home 0x47
#define End  0x4f
#define PageUp 0x49
#define PageDown 0x51



// Enter 0x0d
//Esc 0x1b
// up 0x48
// down 0x50
// home 0x47
// end  0x4f
// pageup 0x49
// pagedown 0x51

int main()
{
    int i , currentPosition = 0,ExitFlag =0 ;
    char menu [3][5] = {"New " , "Save" , "Exit" } ,ch ;
    do
    {
        textattr(0x07);
        system("cls");

        for(i=0 ; i<3 ; i++){
            gotoxy(15,10+i*5);
            if(i==currentPosition)  textattr(0x70);
            else textattr(0x09);
            cprintf("%s",menu[i]);
        }

        ch = getch();

        switch(ch)
        {
        case -32 :
            ch = getch();
            switch(ch)
            {
            case up :
            case PageUp :
                currentPosition--;
                if(currentPosition<0) currentPosition = 2;
                break;
            case down :
            case PageDown :
                currentPosition++;
                if(currentPosition>2) currentPosition = 0;
                break;
            case Home:
                currentPosition = 0;
                break;
            case End :
                currentPosition = 2 ;
                break;
            }
            break;
        case Enter :
            switch (currentPosition)
            {
            case 0 :
                system("cls");
                printf("Creating New File ...\nLoading......");
                getch();
                break;
            case 1 :
                system("cls");
                printf("Saving File ......\nLoading..........");
                getch();
                break;
            case 2 :
                ExitFlag=1;
                break;
            }
            break;
        case Esc :
                ExitFlag = 1;
                break;
        }


    }while(!ExitFlag);

    return 0;
}


