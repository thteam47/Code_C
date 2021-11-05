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
void in_am_d (int *a, int n) {
    for (int i=0; i<n; i++)
        if (a[i]<0)
            printf("%d",a[i]);
    printf("\n");
    for (int i=0; i<n; i++)
        if (a[i]>0)
            printf("%d",a[i]);

}
void am_cuoi (int *a,int n) {
    int dem=0;
    for (int i=n-1; i>=0; i--)
        if (a[i]<0) {
            dem++;
            printf("\nam cuoi la: %d",a[i]);
            break;
        }
    if (dem==0)
        printf("\nKhong co phan tu am");
}
void swap (int *a, int *b) {
    int tg=*a;
    *a=*b;
    *b=tg;
}
void sort (int *a, int n) {
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]>a[j])
                swap(&a[i],&a[j]);
    printf("\nDay sau khi sap xep la: \n");
    for (int i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
}
void sort_t (int *a, int n) {
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]>a[j])
                swap(&a[i],&a[j]);
    xuat(a,n);
}
void sort_g (int *a, int n) {
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]<a[j])
                swap(&a[i],&a[j]);
    xuat(a,n);
}
int dem_am (int *a, int n) {
    int dem=0;
    for (int i=0; i<n; i++) {
        if (a[i]<0)
            dem++;
    }
    return dem;
}
int dem_duong (int *a,int n) {
    int dem=0;
    for (int i=0; i<n; i++) {
        if (a[i]>0)
            dem++;
    }
    return dem;
}
void tach_1 (int *a, int n,int *b, int *c) {

    int m=0,k=0;
    for (int i=0; i<n; i++) {
        if (a[i]>0)
            b[m++]=a[i];
    }
    printf("\nhien thi:\n ");
    for (int i=0; i<m; i++) {
        printf("%d\t",b[i]);
    }
    for (int j=0; j<n; j++) {
        if (a[j]<0)
            c[k++]=a[j];
    }
    printf("\n");
    for (int j=0; j<k; j++) {
        printf("%d\t",c[j]);
    }
}
void swap_am_duong (int *a, int n, int *b, int *c) {
    sort_t(c,dem_am(a,n));
    sort_g(b,dem_duong(a,n));
}
void tach (int *a, int n,int *b, int *c) {

    printf("\nMang b: ");
    for (int i=0; i<dem_duong(a,n); i++) {
        printf("%d\t",b[i]);
    }

    printf("\nMang c: ");
    for (int j=0; j<dem_am(a,n); j++) {
        printf("%d\t",c[j]);
    }
}
int main() {
    int n;
    printf("Nhap So Phan Tu Mang: ");
    scanf("%d",&n);
    int *a= (int*)malloc(n*sizeof(a));
    int *b= (int*)malloc(dem_duong(a,n)*sizeof(b));
    int *c= (int*)malloc(dem_am(a,n)*sizeof(c));
    nhap(a,n);
    printf("\nmang la: ");
    xuat(a,n);
    printf("\nAm, duong:\n");
    tach_1(a,n,b,c);
    printf("\nsap xep am tang, duong giam: \n");
    swap_am_duong(a,n,b,c);
    am_cuoi(a,n);
    sort(a,n);
    tach(a,n,b,c);
    return 0;
}
