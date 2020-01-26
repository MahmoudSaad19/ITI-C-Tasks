#include <stdio.h>
#include <stdlib.h>

// swap 2 integers


void swap(int *a, int *i);

int main() {

    int a , b ;

    printf("before swap \na = %d  \nb = %d ",a,b);
    swap(&a,&b);
    printf("\nafter swap \na = %d  \nb = %d ",a,b);

    return 0;
}

void swap(int *x, int *y) {
    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;
}
