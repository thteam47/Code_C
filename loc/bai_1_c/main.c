#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int total = 0;
    for (int i=1; i<=n; i++)
    {
        total += (float)1/i;
    }
    printf("\ntong: %.3d",total);
    return 0;
}
