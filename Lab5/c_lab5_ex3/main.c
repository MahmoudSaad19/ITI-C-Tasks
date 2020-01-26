#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.c"


#define Enter 0x0d
#define Esc  0x1b
#define right 0x4d
#define left  0x4b
#define Home 0x47
#define End  0x4f

// line editor
/*
    Required :
        1-array of 10 elements
        2-user can overwrite any char
        3-keys used : left, right , home , end

*/

int main()
{
    char ch ,arr[11]={} ,*cursor,*lastPosition;
    int currentPosition = 0, ExitFlag = 1 , numberOfEntries = 0 ,i;
    cursor=arr;
    lastPosition= cursor ;
    //drawer();
    while (ExitFlag)
    {
        gotoxy(15+currentPosition,5);
        ch= getch();
        switch (ch)
        {
            case -32 :
                ch = getch();
                switch(ch)
                {
                    case right :
                        if(currentPosition < 9 && currentPosition<numberOfEntries) currentPosition++;
                        break;
                    case left :
                        if (currentPosition > 0)
                        currentPosition--;
                        break;
                    case Home:
                        currentPosition = 0;
                        break;
                    case End :
                        cursor = lastPosition ;
                        currentPosition=numberOfEntries - 1 ;
                        break;
                }
                break;
            case Enter :
                arr[numberOfEntries+1]='\0';
                gotoxy(15,10);
                textattr(15);
                puts(arr);
                ExitFlag = 0;
                break;
            case Esc :
                ExitFlag = 0;
                textattr(15);
                break;
            case '+' :
                    ch=getch();
                    if (ch>='0' && ch<='z' || ch == ' ' )
                    {
                        textattr(0x9f);
                        cprintf("%c",ch);
                        gotoxy(16+currentPosition,5);
                        for(i=currentPosition ; i<=numberOfEntries ;i++){
                            cprintf("%c",arr[i]);
                        }
                        for(i=numberOfEntries ; i<=currentPosition ;i--){
                            arr[i+1]=arr[i];
                        }
                        arr[currentPosition] = ch;
                        if (numberOfEntries<10) numberOfEntries++;
                    }

                break;
            default :
                if (ch>='0' && ch<='z' || ch == ' ')
                {
                    textattr(0x9e);
                    arr[currentPosition] = ch;
                    cprintf("%c",ch);
                    if(currentPosition < 9) currentPosition++;
                    if (numberOfEntries<10) numberOfEntries++;
                }


        }
    }

    return 0;
}

drawer()
{
    int i;
    for(i=0 ; i<10 ; i++){
            gotoxy(15+i,5);
            textattr(0x0f);
            cprintf(" ");
    }
}

// a=61
// z=7a
// A=41
// Z=5a


