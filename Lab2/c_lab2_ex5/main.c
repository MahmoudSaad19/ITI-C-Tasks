#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        00   01       00   01   02
        10   11       10   11   12
        20   21


        00*00+01*10     00*01+01*11     00*02+01*12
        10*00+11*10     10*01+11*11     10*02+11*12
        20*00+21*10     10*01+11*11     20*02+21*12
    */
    int arr1 [3][2]={{5,7},{6,4},{8,2}},arr2 [2][3] = { {1,5,8} , {9,4,0} },i,j,k,item =0,result[3][3]={};
    for (i=0 ; i<3 ; i++){
        for(j=0;j<3;j++){
            for(k=0;k<2;k++){
                item += arr1[j][k]*arr2[k][i];
            }
            result[i][j]=item;
            item =0;
        }
    }
    for(j=0;j<3;j++){
        for(k=0;k<3;k++){
                printf("\t\t%d",result[k][j]);
        }
        printf("\n");
    }
        printf("\n\n\n\n");


    return 0;
}

