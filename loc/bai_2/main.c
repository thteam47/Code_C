#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int giai_thua (int t)
{
    if (t<=1)
        return 1;
    else
        return giai_thua(t-1)*t;
}

int main()
{
    float x;
    printf("nhap x: ");
    scanf("%f",&x);
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    float total = 0;
    for (int i=0; i<=n; i++)
    {
        total += pow(-1,i)*(pow(x,(2*i+1))/(float)giai_thua(2*i+1));
    }
    printf("\ntong: %.4f",total);
    return 0;
}
