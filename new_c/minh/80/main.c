#include <stdio.h>
#include <stdlib.h>

int checkBinA(int a[100],int n,int b[100],  int m) {
    for (int i=0; i<n&&(n-1)>m; i++) {
        if (a[i]==b[0]) {
            int h=1;
            for (; h<m; h++) {
                if (a[i+h]!=b[h])
                    break;
            }
            if (h==m) return i;
        }
    }
    return -1;
}

int main() {
    int m,n;
    int a[100], b[100];
    printf("Nhap n [1,99]: ");
    scanf("%d",&n);
    printf("Nhap %d phan tu mang A\n",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    do {
        printf("Nhap m [1,10]: ");
        scanf("%d",&m);
        if (m>n) printf("m nho hon n. Nhap lai\n");
    } while (m>n);

    printf("Nhap %d phan tu mang B\n",m);
    for (int i=0; i<m; i++) {
        scanf("%d",&b[i]);
    }
    if (checkBinA(a,n,b,m)==-1) printf("Khong co B trong A");
    else printf("B trong A tai: a[%d]",checkBinA(a,n,b,m));
    int x=10;
    for (int i=0; i<n; i++) {
        if (a[i]<0)
            x=a[i];
    }
    if (x>0) printf("\nMang A khong co so nguyen am");
    else printf("\nSo nguyen am cuoi cung trong mang A: %d",x);
}
