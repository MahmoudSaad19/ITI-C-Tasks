#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        00   01       00
        10   11       10
        20   21


        00*00+01*10
        10*00+11*10
        20*00+21*10
    */
    int arr3 [3][2]={{5,7},{6,4},{8,2}} , arr4[2] = {1,1},res[3]={},i=0,j,k;
    for(j=0;j<3;j++){
        for(k=0;k<2;k++){
                i+= arr3[j][k]*arr4[k];
            }
            res[j]=i;
            i =0;
        }

    for(j=0;j<3;j++){
                printf("\t\t%d",res[j]);
                printf("\n");
        }




    return 0;
}
