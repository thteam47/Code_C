#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void nhap (int a[][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
}
void xuat (int a[][MAX],int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void tong_pt (int a[][MAX],int n, int m) {
    int sum=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            sum+=a[i][j];
        }
    }
    printf("\nTong phan tu cua ma tran: %d",sum);
}
void pt_chia7 (int a[][MAX],int n, int m) {
    int dem=0;
    printf("\nPhan tu chia het cho 7 la: ");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j]%7==0) {
                printf("%d\t",a[i][j]);
                dem++;
            }
        }
    }
    if (dem==0)
        printf("khong co");
}
void tong_vien (int a[][MAX],int n, int m) {
    int s=0;
    for(int i=0; i<m; i++) {
        s+=a[0][i];
    }
    for(int i=1; i<n; i++) {
        s+=a[i][0];
    }
    for(int i=1; i<m; i++) {
        s+=a[n-1][i];
    }
    for(int i=1; i<n-1; i++) {
        s+=a[i][m-1];
    }
    printf("\ntong vien: %d",s);
}
void tong_tg (int a[][MAX],int n, int m) {
    int sum=0;
    if (m==n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i<j)
                    sum+=a[i][j];
            }
        }
        printf("\ntonf phan tu nam tren tam giac tren la: %d",sum);
    } else
        printf("\nkhong ton tai tam giac tren");
}
void cot_tich_max (int a[][MAX],int n, int m) {
    int h=1;
    int max=1;
    for (int i=0; i<n; i++) {
        max*=a[i][0];
    }
    for (int j=1; j<m; j++) {
        int max1=1;
        for (int i=0; i<n; i++) {
            max1*=a[i][j];
        }
        if (max1>max) {
            max=max1;
            h=j+1;
        }
    }
    printf("\ncot co tich max la: %d",h);
}
void max_spc_dong (int a[][MAX],int n, int m) {
    int max=0;
    int h;
    for (int i=0; i<n; i++) {
        int dem=0;
        for (int j=0; j<m; j++) {
            if (sqrt(a[i][j])==((float)sqrt(a[i][j])))
                dem++;
        }
        if (dem>max) {
            max =dem;
            h=i+1;
        }
    }
    if (max==0)
        printf("\nkhong co so chinh phuong");
    else
        printf("\ndong %d co nhieu so chinh phuong nhat",h);
}
int swap_t(int a[][MAX],int n, int m) {
    for (int j=0; j<m-1; j++) {
        for (int k=1; k<m; k++) {
            if (a[n][k]<a[n][j])
                return 0;
        }
    }
    return 1;
}
int swap_g(int a[][MAX],int n, int m) {
    for (int j=0; j<m-1; j++) {
        for (int k=1; k<m; k++) {
            if (a[n][k]>a[n][j])
                return 0;
        }
    }
    return 1;
}
void swap_t_g (int a[][MAX],int n, int m) {
    printf("\nhang co sap sep tang, giam: ");
    int dem=0;
    for (int i=0; i<n; i++) {
        if (swap_g(a,i,m)||swap_t(a,i,m)) {
            printf("%d\t",i+1);
            dem++;
        }
    }
    if (dem==0)
        printf("khong co");
}
void hoan_vi (int a[][MAX],int n, int m) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t",a[j][i]);
        }
        printf("\n");
    }
}
void menu() {
    printf("\n1. Tinh tong cac phan tu");
    printf("\n2. Liet ke phan tu chia het cho 7");
    printf("\n3. Tong cac phan tu tren duong vien");
    printf("\n4. Tong cac phan tu tren tam giac tren");
    printf("\n5. Cot co tich max");
    printf("\n6. Dong co nhieu so chinh phuong nhat");
    printf("\n7. Dong duoc sap xep tang hoac giam");
    printf("\n8. Hoan vi ma tran thanh MxN");
    printf("\n9. Thoat");
}
int main() {
    int a[MAX][MAX];
    int m,n,lc;
    printf("nhap dong: ");
    scanf("%d",&n);
    printf("nhap cot: ");
    scanf("%d",&m);
    nhap(a,n,m);
    xuat(a,n,m);
    do {
        menu();
        printf("\nLua chon: ");
        scanf("%d",&lc);
        switch (lc) {
        case 1:
            tong_pt(a,n,m);
            break;
        case 2:
            pt_chia7(a,n,m);
            break;
        case 3:
            tong_vien(a,n,m);
            break;
        case 4:
            tong_tg(a,n,m);
            break;
        case 5:
            cot_tich_max(a,n,m);
            break;
        case 6:
            max_spc_dong(a,n,m);
            break;
        case 7:
            swap_t_g(a,n,m);
            break;
        case 8:
            hoan_vi(a,n,m);
            break;
        case 9:
            exit(0);
        default:
            printf("\nLua chon khong hop le. Nhap lai");
            break;
        }
    } while (lc!=9);
    return 0;
}
