#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // first name , last name , full name
    char fname [10] , lname [10] , fullname [20] ;
    int i;
    printf("Enter your first name : ");
    gets(fname);
    printf("Enter your last name : ");
    gets(lname);
    strcpy(fullname , fname);
    strcat(fullname , " ");
    strcat(fullname , lname);
    printf("Hello %s ",fullname);

    // reverse
    char reverseName [20] ;
    strcpy(reverseName , lname);
    strcat(reverseName , " ");
    strcat(reverseName , fname);
    printf("\n\nHello %s ",reverseName);

    return 0;
}
