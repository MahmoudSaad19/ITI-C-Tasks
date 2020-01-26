#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///////factorial//////////
    _flushall();
    printf("fact 5 = %d \n",fact(3));
    return 0;
}

int fact (int num)
{
    if (num == 0 )

        return 1;

    return num*fact(num-1);
}
