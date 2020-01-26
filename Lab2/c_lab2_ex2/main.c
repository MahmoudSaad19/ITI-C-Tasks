#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width,height;
    printf("\nenter array width : ");
    scanf("%d",&width);
    printf("\nenter array height : ");
    scanf("%d",&height);
    /////////////////////////////////////////////////////////////////////
    int arr[width][height],sum[width] = {} , avg[width] = {} ,r , c ;

   /* for (r=0;r<width;r++){
        sum [r] = 0;
        avg [r] = 0;
    }*/
    for (r=0;r<width;r++){
        for(c=0; c < height ; c++){
            printf("\nenter item in row = [%d] column = [%d] ",r+1,c+1);
            scanf("%d",&arr[r][c]);
            sum [r] += arr[r][c];
            avg [r] += arr[r][c];
        }
    }
    for (r=0;r<width;r++){
        printf("\nsum for row %d = %d",r+1,sum[r]);
        printf("\naverage for row %d = %d",r+1,avg[r]/height);
    }


    return 0;
}
