#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int total = 0;
    for (int i=1;i<=n;i++){
        total += pow(i,i);
    }
    printf("\ntong: %d",total);
    return 0;
}
