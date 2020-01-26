#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "conio.c"

struct Employee {
    int id , age;
    char gender , name[40] , address[150];
    float salary , oTime , deduct;
};

    int i;
    float nSalary[10];
    struct Employee Earr[10];

int addEmployee(){

    system("cls");
    gotoxy(5,3);
    printf("ID :");
    gotoxy(40,3);
    printf("Name :");
    gotoxy(5,7);
    printf("Age :");
    gotoxy(40,7);
    printf("Gender :");
    gotoxy(5,11);
    printf("Salary :");
    gotoxy(40,11);
    printf("OverTime :");
    gotoxy(5,15);
    printf("Deduction :");
    gotoxy(5,19);
    printf("Address :");

    gotoxy(15,3);
    scanf("%i" , &Earr[i].id);
    gotoxy(50,3);
    //gets(E1.name);
    _flushall();
    scanf("%s" , Earr[i].name);
    gotoxy(15,7);
    scanf("%i" , &Earr[i].age);
    gotoxy(50,7);
    Earr[i].gender = getche();
    gotoxy(15,11);
    scanf("%f" , &Earr[i].salary);
    gotoxy(50,11);
    scanf("%f" , &Earr[i].oTime);
    gotoxy(18,15);
    scanf("%f" , &Earr[i].deduct);
    gotoxy(18,19);
    //gets(E1.address);
    scanf("%s" , Earr[i].address);
    system("cls");
    i++;
}

int displayID(int i){

        gotoxy(5,3);
        printf("ID : %i" , Earr[i].id);
        gotoxy(40,3);
        printf("Name : %s" , Earr[i].name);
        gotoxy(5,7);
        printf("Age : %i" , Earr[i].age);
        gotoxy(40,7);
        printf("Gender : %c" , Earr[i].gender);
        gotoxy(5,11);
        printf("Salary : %f" , Earr[i].salary);
        gotoxy(40,11);
        printf("OverTime : %f" , Earr[i].oTime);
        gotoxy(5,15);
        printf("Deduction : %f" , Earr[i].deduct);
        gotoxy(5,19);
        printf("Address : %s \n" , Earr[i].address);
        gotoxy(40,19);
}


void displayAll(){

    for (i=0;i<10;i++)
    {
       if (Earr[i].id != 0)
       {
        gotoxy(5,3+20*i);
        printf("ID : %i" , Earr[i].id);
        gotoxy(40,3+20*i);
        printf("Name : %s" , Earr[i].name);
        gotoxy(5,7+20*i);
        printf("Age : %i" , Earr[i].age);
        gotoxy(40,7+20*i);
        printf("Gender : %c" , Earr[i].gender);
        gotoxy(5,11+20*i);
        printf("Salary : %f" , Earr[i].salary);
        gotoxy(40,11+20*i);
        printf("OverTime : %f" , Earr[i].oTime);
        gotoxy(5,15+20*i);
        printf("Deduction : %f" , Earr[i].deduct);
        gotoxy(5,19+20*i);
        printf("Address : %s" , Earr[i].address);
        gotoxy(40,19+20*i);
        nSalary[i] = Earr[i].salary + Earr[i].oTime - Earr[i].deduct;
        printf("Net Salary = %f \n" , nSalary[i]);
        printf("******************************************************************\n");
       }
    }
}

int main()
{
    int i , current =0 , exitFlag = 0 , Eindex , fileNumber;
    FILE *fptr;
    char menu[6][15] = {"New" , "DisplayId" , "DisplayAll" , "Save" , "Load", "Exit"} , ch;
    do
    {
        textattr(0x07);
        system("cls");
        for(i=0;i<6;i++)
        {
            gotoxy(15 , 10+i*2);
            if(i==current) textattr(0x70);
            else textattr(0x07);
            cprintf("%s" , menu[i]);
        }
        ch=getch();
        switch(ch)
        {
        case -32:
            ch = getch();
            switch (ch)
            {
                case 0x48:
                    current--;
                    if(current<0) current = 5;
                break;

                case 0x50:
                    current++ ;
                    if(current>5) current=0;
                break;

                case 0x47:
                    current=0 ;
                break;

                case 0x4F:
                    current=5;
                break;
            }
        break;
        case 0x0D:
            switch (current)
            {
                case 0:
                    system("cls");
                    addEmployee();
                    printf("press Any Key To go back to Menu.");
                    ch=getch();
                break;
                case 1:
                    system("cls");
                    printf("Enter ID: ");
                    scanf("%i" , &Eindex);
                    displayID(Eindex);
                    printf("press Any Key To go back to Menu.");
                    ch=getch();
                break;
                case 2:
                    system("cls");
                    displayAll();
                    printf("press Any Key To go back to Menu.");
                    ch=getch();
                break;
                case 3:
                   fptr = fopen("Emp.txt" , "w");
                   for (i=0;i<10;i++)
                    {
                        if (Earr[i].id != 0)
                            {
                                fprintf(fptr ,"ID : %i  " , Earr[i].id);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"Name : %s  " , Earr[i].name);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"Age : %i  " , Earr[i].age);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"Gender : %c  " , Earr[i].gender);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"Salary : %f  " , Earr[i].salary);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"OverTime : %f  " , Earr[i].oTime);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"Deduction : %f  " , Earr[i].deduct);
                                fputs("*  " , fptr);
                                fprintf(fptr ,"Address : %s  " , Earr[i].address);
                                fputs("*  " , fptr);
                                nSalary[i] = Earr[i].salary + Earr[i].oTime - Earr[i].deduct;
                                fprintf(fptr ,"Net Salary = %f \n" , nSalary[i]);
                            }
                    }
                   fclose(fptr);
                break;
                case 4:
                    fptr = fopen("Emp.txt" , "r");
                    system("cls");
                    while ((ch=getc(fptr)) != EOF) printf("%c" , ch);
                    fclose(fptr);
                    printf("\n");
                    printf("press Any Key To go back to Menu.");
                    ch=getch();
                break;
                case 5:exitFlag=1;
                break;
            }
        break;
        case 0x1B:
                exitFlag = 1;
        break;

        }
    }
    while(!exitFlag);
}

