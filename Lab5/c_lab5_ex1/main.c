#include <stdio.h>
#include <stdlib.h>

// input and output array using pointers

int main()
{
    int size;
    printf("enter array size : ");
    scanf("%d", &size);
    int arr[size], i, *ptr;
    ptr = arr;

    for (i = 0; i < size; i++, ptr++) {
        printf("enter %d number : ", i + 1);
        scanf("%d", ptr);
    }
    ptr = arr;

    for (i = 0; i < size; i++, ptr++) {
        printf("\nnumber %d = %d", i + 1, *ptr);
    }

    return 0;
}
