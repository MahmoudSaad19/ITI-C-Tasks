#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **marks , *sum , stdN , *avg ,i ,j ,subN ;
    printf("Enter Student Num : ");
    scanf("%i",&stdN);
    marks = (int **) malloc(stdN * sizeof(int *));
    sum = (int *) malloc(stdN * sizeof(int));
    printf("Enter subject NO : ");
    scanf("%i",&subN);
    for (i=0 ; i<subN ; i++)
        marks[i] = (int *) malloc(subN*sizeof(int));
    avg = (int *) malloc(subN * sizeof (int));

    for (i=0 ; i<stdN ; i++){
        for (j=0 ; j<subN ; j++){
            printf("student %i  ,subject %i  ",i+1,j+1);
            scanf("%i",&marks[i][j]);
            sum[i] += marks[i][j];
            avg[j] += marks[i][j];
        }
    }

    for (i=0 ; i<subN ; i++)
        avg[i] /= stdN;
    for (i=0 ; i<subN ; i++)
        free(marks[i]);
    free(marks);
    free(avg);
    free(sum);


    return 0;
}
