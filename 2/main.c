#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long int max=15000000, dem=0;
    long int r=0,d;
    for (int i=1; i<=max; i++)
    {
        d=i;
        while (d>0)
        {
            r=d%10;
            d/=10;
            if (r==9)
                dem++;
        }
    }
    printf("gia tri = %d",dem);
    return 0;
}
