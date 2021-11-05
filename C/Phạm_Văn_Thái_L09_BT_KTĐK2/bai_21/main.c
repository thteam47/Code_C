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
void swap (int *a, int *b) {
    int tg= *a;
    *a=*b;
    *b=tg;
}
void sap_xep (int *a,int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i]>a[j])
                swap(&a[i],&a[j]);
        }
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
    sap_xep(a,n);
    sap_xep(b,m);
    int k=m+n;

    int *c= (int*)malloc(k*sizeof(c));
    int i=0,j=0,p=0;
    while (i<=n&&j<=m) {
        if (a[i]<b[j]) {
            c[p++]= a[i];
            i++;
        } else {
            c[p++]=b[j];
            j++;
        }
    }
    printf("\nmang a\n");
    xuat(a,n);
    printf("\nmang b\n");
    xuat(b,m);
    printf("\nMang sau khi tron va sap xep:\n");
    xuat(c,k);
    return 0;
}
