#include <stdio.h>
#include <stdlib.h>

int main()
{
    // enter array and display it using 2 for loops
    int size;
    printf("enter array size : ");
    scanf("%d",&size);
    int arr [size], i, max=0 ,min=0;

    for (i=0;i<size;i++){
        printf("enter %d number : ",i+1);
        scanf("%d",&arr[i]);
    }

     for (i=0;i<size;i++){
        printf("\nnumber %d = %d",i+1,arr[i]);
    }

    // find max and min of that array
    max=min=arr[0];
    for (i=0;i<size;i++){
        if (arr[i]>max)
            max = arr[i];
        else if (arr[i]<min)
            min = arr[i];
    }
    printf("\n\n\t max = %d , min = %d ",max , min );
     return 0;
}
