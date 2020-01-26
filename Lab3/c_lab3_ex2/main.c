#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Enter 0x0d
#define Esc  0x1b
int main()
{
    char ch[10] ,check;
    int i ;
    _flushall();
    for (i=0 ; i<10 ; i++){
        printf("\nenter char no : %d ",i);
        check = getche();
        if(check==Enter || check == Esc) {
            ch[i]='\0';
                break;
        }
        ch[i]=check ;

    }
    printf("\nyou entered :  ");

     for (i=0 ; i<5 ; i++){
            printf("%c",ch[i]);
    }

    return 0;
}
