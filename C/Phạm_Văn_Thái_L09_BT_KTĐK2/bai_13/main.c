#include <stdio.h>
#include <stdlib.h>
int check_mt_donvi (int a[][20],int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((i==j&&a[i][j]!=1)||(i!=j&&a[i][j]!=0))
                return 0;
        }
    }
    return 1;
}
int ktsonguyento(int n) {
    if (n>1) {
        int dem = 0;
        for(int i = 2; i <= sqrt(n); i++) {
            if (n%i==0) {
                return 0;
                dem++;
                break;
            }
        }
        if (dem==0||n==2||n==3)
            return 1;
    } else
        return 0;
}
int main() {
    int a[20][20],n;
    printf("nhap cap n: ");
    scanf("%d",&n);
    printf("nhap ma tran:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nma tran da nhap:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    if (check_mt_donvi(a,n))
        printf("\nma tran la ma tran don vi");
    else
        printf("\nma tran khong phai la ma tran don vi");
    printf("\n\nTinh tong cac phan tu tren hang i");
    int x;
    do {
        printf("\nnhap hang can tinh: ");
        scanf("%d",&x);
        if (x>n)
            printf("\nhang toi da la %d. Nhap lai.",n);
    } while (x>n);
    int sum=0;
    for (int i=0; i<n; i++) {
        sum+=a[x-1][i];
    }
    printf("\ntong cac phan tu tren hang %d la: %d",x,sum );
    printf("\n\nTinh tich cac phan tu tren cot j");
    int k;
    do {
        printf("\nnhap cot can tinh: ");
        scanf("%d",&k);
        if (k>n)
            printf("\ncot toi da la %d. Nhap lai.",n);
    } while (k>n);
    int t=1;
    for (int i=0; i<n; i++) {
        t*=a[i][k-1];
    }
    printf("\ntich cac phan tu tren cot %d la: %d",k,t );
    printf("\nkiem tra hang co so nguyen to khong");
    int b;
    do {
        printf("\nnhap hang can kiem tra: ");
        scanf("%d",&b);
        if (b>n)
            printf("\nhang toi da la %d. Nhap lai.",n);
    } while (b>n);
    int dem1=0;
    for (int i=0; i<n; i++) {
        if (ktsonguyento(a[b-1][i]))
            dem1++;
    }
    if (dem1==0)
        printf("\nhang %d khong co so nguyen to",b);
    else
        printf("\nhang %d co %d so nguyen to",b,dem1);
    printf("\n\nhang co nhieu so nguyen to nhat: ");
    int max=0;
    for (int i=0; i<n; i++) {
        int dem=0;
        for (int j=0; j<n; j++) {
            if (ktsonguyento(a[i][j]))
                dem++;
        }
        if (dem>max) {
            max =dem;
        }
    }
    if (max==0)
        printf("\nkhong co so nguyen to trong ma tran");
    else {
        for (int i=0; i<n; i++) {
            int dem=0;
            for (int j=0; j<n; j++) {
                if (ktsonguyento(a[i][j]))
                    dem++;
            }
            if (dem==max) {
                printf("%d\t",i+1);
            }
        }
    }

    return 0;
}
