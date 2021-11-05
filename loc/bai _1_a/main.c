#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int total = 0;
    for (int i=1;i<=n;i++){
        total += i*(i+1);
    }
    printf("\ntong: %d",total);
    return 0;
}
