#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    while(1){

    char ch ;
    int i ;
    printf("Enter a charter : \n");
    ch = getche();
    if(ch==-32){
        ch=getche();
        printf("\nyou entered extended char   ");
        printf("%c \n  and its hex value is : %x \n\n", ch ,ch);

    }
    else
    printf("\n\n\tyou entered %c and \n\tits hex value is : %x \n\n", ch ,ch);

    }

    char ch ;
    int i ;
    printf("Enter a charter : \n");
    ch = getche();
    if(ch==-32){
        ch=getche();
        printf("\nyou entered extended char   ");
        printf("%c \n  and its hex value is : %x \n\n", ch ,ch);

    }
    else
    printf("\n\n\tyou entered %c and \n\tits hex value is : %x \n\n", ch ,ch);

    return 0;
}
// Enter 0x0d
//Esc 0x1b
// up 0x48
// down 0x50
// home 0x47
// end  0x4f
// pageup 0x49
// pagedown 0x51
