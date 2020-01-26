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


// line editor function

char *lineEditor(int size, int xpos, int ypos, char startRange, char endRange);

int main() {
    char *line;
    line = lineEditor(11, 15, 5, '0', 'z');
    gotoxy(15, 10);
    printf("%s", line);


    return 0;
}


char * lineEditor(int size, int xpos, int ypos, char startRange, char endRange) {
    char ch, arr[size], *cursor, *lastPosition;
    int currentPosition = 0, ExitFlag = 1, numberOfEntries = 0, i;
    cursor = arr;
    lastPosition = cursor;
    //arr[size]={""};
    while (ExitFlag) {
        gotoxy(xpos + currentPosition, ypos);
        ch = getch();
        switch (ch) {
            case -32 :
                ch = getch();
                switch (ch) {
                    case right :
                        if (currentPosition < (size - 2)) currentPosition++;
                        break;
                    case left :
                        if (currentPosition > 0)
                            currentPosition--;
                        break;
                    case Home:
                        currentPosition = 0;
                        break;
                    case End :
                        cursor = lastPosition;
                        currentPosition = numberOfEntries - 1;
                        break;
                }
                break;
            case Enter :
                arr[numberOfEntries + 1] = '\0';
                gotoxy(xpos, ypos * 2);
                textattr(15);
                puts(arr);
                ExitFlag = 0;
                return cursor;
                break;
            case Esc :
                ExitFlag = 0;
                textattr(15);
                break;
            case '+' :
                ch = getch();
                if (ch >= startRange && ch <= endRange || ch == ' ') {
                    textattr(0x9f);
                    cprintf("%c", ch);
                    gotoxy(xpos + 1 + currentPosition, ypos);
                    for (i = currentPosition; i <= numberOfEntries; i++) {
                        cprintf("%c", arr[i]);
                    }
                    for (i = numberOfEntries; i <= currentPosition; i--) {
                        arr[i + 1] = arr[i];
                    }
                    arr[currentPosition] = ch;
                    if (numberOfEntries < (size - 1)) numberOfEntries++;
                }
                break;
            default :
                if (ch >= startRange && ch <= endRange || ch == ' ') {
                    textattr(0x9e);
                    arr[currentPosition] = ch;
                    cprintf("%c", ch);
                    if (currentPosition < (size - 2)) currentPosition++;
                    if (numberOfEntries < (size - 1)) numberOfEntries++;
                }

        }
    }

}
