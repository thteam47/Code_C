#include <stdio.h>
#include <stdlib.h>
void nhap (int *a, int n) {
    for (int i=0; i<n; i++) {
        printf("a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
}
void xuat (int *a, int n) {
    for (int i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
}
int main() {
    int n,m;
    printf("Nhap So Phan Tu Mang A: ");
    scanf("%d",&n);
    int *a= (int*)malloc(n*sizeof(a));
    printf("\nNhap phan tu:\n");
    nhap(a,n);
    printf("Nhap So Phan Tu Mang B: ");
    scanf("%d",&m);
    int *b= (int*)malloc(m*sizeof(b));
    printf("\nNhap phan tu:\n");
    nhap(b,m);
    int k=m+n;
    int *c= (int*)malloc(k*sizeof(c));
    int i=0,j=0,p=0;
    while (i<=n&&j<=m){
        if (a[i]<b[j]) {
            c[p++]= a[i];
            i++;
        }
        else {
            c[p++]=b[j];
            j++;
        }
    }
    printf("\nMang sau khi sap xep: ");
    xuat(c,k);
    return 0;
}
