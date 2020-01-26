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

    int i=0 , s=0 ;
    struct Employee *Earr;
    char *lineEditorCH;


char* lineEditor(int size , int xpos , int ypos , char sRange , char eRange)
{
    int i , col=0 , cond = xpos+size , start = xpos;
    char* pcurrent , *plast , *arr ;
    char ch ;

    arr = (char *)malloc(size*sizeof(char));
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
        //textattr(0x70);
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
                xpos+=col;
                gotoxy(xpos+col,ypos);
                pcurrent = arr+col;
            break;
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

int printForm(){

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
}

int addEmplyee()
{
    _flushall();
    lineEditorCH = lineEditor(1,15,3 , 0 , 127);
    Earr[s].id = atoi(lineEditorCH);
    lineEditorCH = lineEditor(15,50,3 , 0 , 127);
    _flushall();
     strcpy(Earr[s].name,lineEditorCH);
   // scanf("%s" , Earr[i].name);
    lineEditorCH = lineEditor(2,15,7 , 0 ,127);
    Earr[s].age = atoi(lineEditorCH);
    gotoxy(50,7);
    Earr[s].gender = getche();
    lineEditorCH = lineEditor(4,15,11,0,127);
    Earr[s].salary = atof(lineEditorCH);
    gotoxy(50,11);
    scanf("%f" , &Earr[s].oTime);
    gotoxy(18,15);
    scanf("%f" , &Earr[s].deduct);
    gotoxy(18,19);
    //gets(E1.address);
    scanf("%s" , Earr[s].address);
    system("cls");
    s++;
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
        printf("\n" );
        printf("******************************************************************\n");
       }
    }
}

void viewMenu()
{
    int current =0 , exitFlag = 0 , Eindex  , n;
    char menu[4][15] = {"New" , "DisplayId" , "DisplayAll" , "Exit"} , ch;
    printf("Enter Number of Employees : ");
    scanf("%i" , &n);
    Earr = (struct Employee *)malloc( n * sizeof(struct Employee));

    do
    {
        textattr(0x07);
        system("cls");
        for(i=0;i<4;i++)
        {
            gotoxy(15 , 10+i*4);
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
                    if(current<0) current = 3;
                break;

                case 0x50:
                    current++ ;
                    if(current>3) current=0;
                break;

                case 0x47:
                    current=0 ;
                break;

                case 0x4F:
                    current=3;
                break;
            }
        break;
        case 0x0D:
            switch (current)
            {
                case 0:
                    if(s < n){
                     system("cls");
                     printForm();
                     addEmplyee(i++);

                    }
                    else
                    {
                    system("cls");
                    printf("press Any Key To go back to Menu.");
                    ch=getch();
                    }


                break;
                case 1:
                    system("cls");
                    printf("Enter Index: ");
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
                case 3:exitFlag=1; break;
            }
        break;
        case 0x1B:
                exitFlag = 1;
        break;

        }
    }
    while(!exitFlag);
}

int main()
{

    viewMenu();
}
