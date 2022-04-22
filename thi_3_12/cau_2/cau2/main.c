#include <stdio.h>
#include <stdlib.h>
//ham nhap mang
void nhap_mang(float *a,int n) {
    printf("\nnhap phan tu mang:\n");
    for (int i=0; i<n; i++) {
        printf("a[%d] = ",i);
        scanf("%f",&a[i]);
    }
}
//ham xuat mang
void xuat_mang(float *a,int n) {
    printf("\ncac phan tu cua mang la: \n");
    for (int i=0; i<n; i++) {
        printf("%8.3f\t",a[i]);
    }
}
int main()
{
    int n;
    do {
        printf("\nnhap n = ");
        scanf("%d",&n);
        if (n<=0)
            printf("\nn la so nguyen duong. Nhap lai\n");
    } while (n<=0);
    float *a= (float*)malloc(n*sizeof(float));
    printf("phan a \n");
    nhap_mang(a,n);
    printf("\nphan b \n");
    xuat_mang(a,n);
    printf("\nphan c \n");
    float sum =0;
    printf("\nTong cac so duong la: \n");
    for (int i=0; i<n;i++){
        if (a[i]>0){
            sum += a[i];
        }
    }
    printf("%8.3f",sum);
    return 0;
}
