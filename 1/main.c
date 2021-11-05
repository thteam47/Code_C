#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long int max=15000000, dem=0;
    int so_chu_so =0;
    long int r=0;
    while (max>0)
    {
        so_chu_so++;
        r=max%10;
        max/=10;
        if (r!=9) dem+=r*(so_chu_so-1)*powf (10,(so_chu_so-2));
        else dem= dem+ r*(so_chu_so-1)*powf (10,(so_chu_so-2)) + powf (10,(so_chu_so-1));
    }
    printf("\ndap an %d",dem);
    return 0;
}
