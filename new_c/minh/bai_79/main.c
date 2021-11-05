#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[100];
    printf("Nhap n [1,99]: ");
    scanf("%d",&n);
    float tong =0;
    for (int i=0; i<n;i++){
        do {
            scanf("%d",&a[i]);
            if (a[i]>100||a[i]<-100) printf("Nhap so trong khoang -100;100. Nhap lai\n");
        } while (a[i]>100||a[i]<-100);
        tong += (float)1/a[i];
    }
    printf("Tong nghich dao: %f\n",tong);
    for (int i=0;i<n;i++) {
        if (a[i]%2!=0) {
            for (int j=i+1;j<n-1;j++){
                a[j]=a[j+1];
            }
            n--;
        }
    }
    for (int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 1;
}
