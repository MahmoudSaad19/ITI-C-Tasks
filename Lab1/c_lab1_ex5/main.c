#include <stdio.h>
#include <stdlib.h>

void main()
{
    int currentNumber , sum =0 ;
    while(sum<100)
    {
        printf("Enter a number \n");
        scanf("%d",&currentNumber);
        sum += currentNumber ;
        printf("\nsum = %d \n",sum);
    }

}
