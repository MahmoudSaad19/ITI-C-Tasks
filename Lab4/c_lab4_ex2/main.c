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

struct Employee
{
    int id,Age;
    char Gender , Name [40] , Address [200] ;
    float Salary , overTime ,deduct ;
};

struct Employee emp[3];
float netSalary[3] ;


int main()
{
   int i , currentPosition = 0,ExitFlag =0 ;
    char menu [3][8] = {"New " , "Display" , "Exit" } ,ch ;
    do
    {
        textattr(0x07);
        system("cls");

        /////// drawer for loop //////////
        for(i=0 ; i<3 ; i++){
            gotoxy(15,10+i*5);
            if(i==currentPosition)  textattr(0xf0);
            else textattr(0x0f);
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
                form();
                printf("Creating New File ...\nLoading......");
                getch();
                break;
            case 1 :
                system("cls");
                printf("Displaying All data ......\nLoading..........\n");
                getch();
                system("cls");
                displayAll();
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

void displayAll ()
{
    int i,j;

    for (i=0 ; i<3 ; i++)
    {
/////////////printing form //////////////
    printf("Displaying Employee %d data : \n\n",i+1);
    //printf("----------------------------");

    gotoxy(5 ,3+i*25);
    printf("id : %d",emp[i].id);

    gotoxy(40 ,3+i*25);
    printf("Age : %d",emp[i].Age);

    gotoxy(5 ,7+i*25);
    printf("Name : %s",emp[i].Name);

    gotoxy(40 , 7+i*25);
    printf("Gender : %c",emp[i].Gender);

    gotoxy(40,11+i*25);
    printf("Address : %s",emp[i].Address);

    gotoxy(5,11+i*25);
    printf("Salary : %f",emp[i].Salary);

    gotoxy(5,15+i*25);
    printf("Over Time : %f",emp[i].overTime);

    gotoxy(5,19+i*25);
    printf("Deductions : %f\n",emp[i].deduct);

    printf("_________________________________________________\n\n");

    }

}

void calcNet ()
{
    int i;
    gotoxy(30,20);
    for(i=0 ; i<3 ; i++)
    {
        netSalary [i]= emp[i].Salary + emp[i].overTime - emp[i].deduct ;
        printf("\n\nNet Salary of employee %d = %f ",i+1,netSalary[i]);
    }
}

void form ()
{
    int i;

    for (i=0 ; i<3 ; i++)
    {
/////////////printing form //////////////
    system("cls");
    printf("Enter Employee %d data : \n\n",i+1);

    gotoxy(5 ,3);
    printf("id : ");

    gotoxy(40 ,3);
    printf("Age : ");

    gotoxy(5 ,7);
    printf("Name : ");

    gotoxy(40 , 7);
    printf("Gender : ");

    gotoxy(40,11);
    printf("Address : ");

    gotoxy(5,11);
    printf("Salary : ");

    gotoxy(5,15);
    printf("Over Time : ");

    gotoxy(5,19);
    printf("Deductions : ");
//////////data collection ///////////
    gotoxy(15,3);
    _flushall();
    scanf("%d",&emp[i].id);

    gotoxy(50 ,3);
    _flushall();
    scanf("%d",&emp[i].Age);

    gotoxy(15 ,7);
    _flushall();
    scanf("%s",emp[i].Name);

    gotoxy(50 , 7);
    _flushall();
    scanf("%c",&emp[i].Gender);

    gotoxy(50,11);
    _flushall();
    scanf("%s",emp[i].Address);

    gotoxy(15,11);
    _flushall();
    scanf("%f",&emp[i].Salary);

    gotoxy(20,15);
    _flushall();
    scanf("%f",&emp[i].overTime);

    gotoxy(20,19);
    _flushall();
    scanf("%f",&emp[i].deduct);

    }

}
