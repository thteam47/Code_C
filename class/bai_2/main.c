#include <stdio.h>
#include <stdlib.h>
void nhapsnd(int *n)
{
    printf("Nhap so N :");
    scanf("%d",n);
}
int ktsnt(int n)
{
    if(n<2)
    {
        return 0;
    }
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int timsnt(int n)
{
    if(n==2)
    {
        printf("Khong co so nguyen to nho hon 2");
    }
    printf("Cac snt nho hon %d la :",n);
    for(int i=0; i<n; i++)
    {
        if(ktsnt(i)==1)
        {
            printf("%d\t",i);
        }
    }
}


int main()
{
    int n;
    nhapsnd(&n);
    timsnt(n);
    return 0;
}
