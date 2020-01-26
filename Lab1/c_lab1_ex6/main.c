#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void main()
{
    char input ;
    while (1)
    {
         system("cls");
        printf("\n\nDisplay d \nEnter e \nExit x \n");
        scanf(" %c",&input);

    if (input == 'd')
    {
        system("cls");
        printf("Hello C World");
        getchar();
    }
    else if (input == 'e')
    {
        system("cls");
        printf("Welcome to C");
        getchar();
    }
    else if (input == 'x')
    {
        system("cls");
        printf("Good Bye");
        break;
    }
    else
    {
        system("cls");
        printf("sorry invalid input");
        getchar();
    }
getchar();
    }

}

