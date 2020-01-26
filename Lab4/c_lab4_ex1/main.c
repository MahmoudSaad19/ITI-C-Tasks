#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id,Age;
    char Gender , Name [40] , Address [200] ;
    float Salary , overTime ,deduct ;
};

int main()
{
    struct Employee e1;
    _flushall();
    float netSalary ;
    printf("Enter id : ");
    scanf("%d",&e1.id);

    printf("Enter Age : ");
    scanf("%d",&e1.Age);
    _flushall();

    printf("Enter Name : ");
    scanf("%s",e1.Name);
    _flushall();

    printf("Enter Gender : ");
    scanf("%c",&e1.Gender);
    _flushall();

    printf("Enter Address : ");
    scanf("%s",e1.Address);

    printf("Enter Salary : ");
    scanf("%f",&e1.Salary);

    printf("Enter Over Time : ");
    scanf("%f",&e1.overTime);

    printf("Enter Deductions : ");
    scanf("%f",&e1.deduct);

    netSalary = e1.Salary + e1.overTime - e1.deduct ;
    printf("\n\nNet Salary = %f ",netSalary);

    return 0;
}
