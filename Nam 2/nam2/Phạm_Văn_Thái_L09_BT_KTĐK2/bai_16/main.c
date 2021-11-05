#include <stdio.h>
#include <stdlib.h>
void nhap (int a[][100], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
}
void xuat (int a[][100], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void in_cheo_chinh (int a[][100], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j)
                printf("%d\t",a[i][j]);
            else
                printf("*\t");
        }
        printf("\n");
    }
}
void ptu_max (int a[][100],int n) {
    int max= a[0][0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]>max)
                max=a[i][j];
        }
    }
    printf("\nPhan tu lon nhat cua ma tran la: %d", max);
}
void ptu_min (int a[][100],int n) {
    int min= a[0][0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]<min)
                min=a[i][j];
        }
    }
    printf("\nPhan tu nho nhat cua ma tran la: %d", min);
}
void swap (int *a, int *b) {
    int tg=*a;
    *a=*b;
    *b=tg;
}
void sort_cot (int a[][100],int n) {
    for (int j=0; j<n; j++) {
        for (int i=0; i<n-1; i++) {
            for (int k=1; k<n; k++) {
                if (a[i][j]>a[k][j])
                    swap(&a[i][j],&a[k][j]);
            }
        }
    }
    xuat(a,n);
}
void sort_hang (int a[][100],int n) {
    for (int j=0; j<n; j++) {
        for (int i=0; i<n-1; i++) {
            for (int k=1; k<n; k++) {
                if (a[j][i]>a[j][k])
                    swap(&a[j][i],&a[j][k]);
            }
        }
    }
    xuat(a,n);
}
void max_2 (int a[][100],int n) {
    int max= a[0][0];
    int h,k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]>max) {
                max=a[i][j];
                h=i;
                k=j;
            }
        }
    }
    int max2,dem=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (max==a[i][j]) {
                dem++;
                continue;
            } else {
                max2=a[i][j];
                break;
            }
        }
    }
    if (dem==n*n)
        printf("\nKhong co phan tu lon thu 2");
    else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==h&&j==k||a[i][j]==max)
                    continue;
                else {
                    if (a[i][j]>max2)
                        max2=a[i][j];
                }
            }
        }
        printf("\nPhan tu lon thu 2 cua ma tran la: %d", max2);
    }
}
int check_songuyento (int n) {
    if (n==2)
        return 1;
    for (int i=2; i<n; i++) {
        if (n%i==0)
            return 0;
    }
    return 1;
}
void tong_songuyento (int a[][100],int n) {
    int tong=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]>1&&check_songuyento(a[i][j]))
                tong+=a[i][j];
        }
    }
    printf("\nTong cac so nguyen to la: %d",tong);
}
void menu () {
    printf("\n===MENU===");
    printf("\n1. NHAP MA TRAN");
    printf("\n2. IN PHAN TU TREN DUONG CHEO CHINH");
    printf("\n3. TIM PHAN TU LON NHAT");
    printf("\n4. TIM PHAN TU NHO NHAT");
    printf("\n5. SAP XEM PHAN TU TANG DAN THEO HANG");
    printf("\n6. SAP XEP PHAN TU TANG DAN THEO COT");
    printf("\n7. TIM PHAN TU LON THU 2 CUA MA TRAN");
    printf("\n8. TONG CAC SO NGUYEN TO TRONG MA TRAN");
    printf("\n9. THOAT");
    printf("\nLua chon: ");
}
int main() {
    int lc,n,lc1;
    int a[100][100];
    do {
        menu();
        scanf("%d",&lc);
        if (lc==9)
            exit(1);
        else if (lc==1) {
            printf("nhap cap n: ");
            scanf("%d",&n);
            nhap(a,n);
            printf("\nMa tran da nhap\n");
            xuat(a,n);
            break;
        } else
            printf("\nChua nhap ma tran");
    } while (lc!=9||lc!=1);
tiep:
    menu();
    scanf("%d",&lc1);
    switch (lc1) {
    case 1:
        printf("nhap cap n: ");
        scanf("%d",&n);
        nhap(a,n);
        printf("\nMa tran da nhap\n");
        xuat(a,n);
        goto tiep;
        break;
    case 2:
        in_cheo_chinh(a,n);
        goto tiep;
        break;
    case 3:
        ptu_max(a,n);
        goto tiep;
        break;
    case 4:
        ptu_min(a,n);
        goto tiep;
        break;
    case 5:
        sort_hang(a,n);
        goto tiep;
        break;
    case 6:
        sort_cot(a,n);
        goto tiep;
        break;
    case 7:
        max_2(a,n);
        goto tiep;
        break;
    case 8:
        tong_songuyento(a,n);
        goto tiep;
        break;
    case 9:
        exit(1);
    default:
        goto tiep;
        break;
    }
    return 0;
}
