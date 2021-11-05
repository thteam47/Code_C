#include <stdio.h>
#include <stdlib.h>
void check_snt () {
    int n;
    do {
        printf("nhap n = ");
        scanf("%d",&n);
        if (n<1)
            printf("\nn duong, nhap lai\n");
    } while (n<1);
    int dem=0;
    for(int i = 2; i <= sqrt(n); i++) {
        if (n%i==0) {
            printf("\n%d khong phai la so nguyen to", n);
            dem++;
            break;
        }
    }
    if (dem==0||n==2||n==3)
        printf("\n%d la so nguyen to",n);
}
void sohhn () {
    int n,tong=0;
    do {
        printf("nhap n = ");
        scanf("%d",&n);
        if (n<1)
            printf("\nn duong, nhap lai\n");
    } while (n<1);
    printf("\nso hoan hao la: ");
    for (int i=1; i<=n; i++) {
        if (i==1) {
            printf("1");
            continue;
        }
        for (int j=1; j<i; j++) {
            if (i%j==0)
                tong+=j;
        }
        if (i==tong)
            printf("\t%d",i);
        tong=0;
    }

}
void check_sohhn () {
    int n,tong=0;
    do {
        printf("nhap n = ");
        scanf("%d",&n);
        if (n<1)
            printf("\nn duong, nhap lai\n");
    } while (n<1);
    for (int j=1; j<n; j++) {
        if (n%j==0)
            tong+=j;
    }
    if (n!=tong|| n==1)
        printf("\n%d khong la so hoan hao",n);
    else
        printf("\n%d la so hoan hao",n);

    }
int kiemtra (int n) {
    int dem=0;
    for(int i = 2; i <= sqrt(n); i++) {
        if (n%i==0) {
            return 0;
            dem++;
            break;
        }
    }
    if (dem==0||n==2||n==3)
        return 1;
}
void snt_n () {
    int n;
    printf("\nNhap N: ");
    scanf("%d", &n);
    printf("\ncac so nguyen to tu 1 den %d la:\n",n);
    for (int i=2; i<=n; i++) {
        if (kiemtra(i))
            printf("%d\t",i);
    }

}
int ucln(int a, int b) {
    if (a<0)
        a=-a;
    if (b<0)
        b=-b;
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
int ucln1(int a, int b) {
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
void tim_ucln() {
    int a, b;
    printf("Nhap a = ");
    scanf("%d", &a);
    printf("\nNhap b = ");
    scanf("%d", &b);
    printf("\nUCLN cua %d va %d la: %d", a, b, ucln1(a, b));
}

void u_cln() {
    int a, b;
    do {
        printf("Nhap tu so = ");
        scanf("%d", &a);
        printf("\nNhap mau so = ");
        scanf("%d", &b);
        if (a==0||b==0)
            printf("\nnhap so khac 0, nhap lai: \n");
    } while (a==0||b==0);
    if (b==1)
        printf("\nPhan so rut gon %d/%d = %d",a,b,a);
    else if (b==-1)
        printf("\nPhan so rut gon %d/%d = %d",a,b,-a);
    else {
        if (b>0)
            printf("\nPhan so rut gon %d/%d = %d/%d",a,b,a/ucln(a,b),b/ucln(a,b));
        else
            printf("\nPhan so rut gon %d/%d = %d/%d",a,b,-a/ucln(a,b),-b/ucln(a,b));
    }

}

void menu() {
    printf("\n\n1. Kiem tra so nguyen to");
    printf("\n2. In so nguyen to nho hon n");
    printf("\n3. Kiem tra so hoan hao");
    printf("\n4. In so hoan hao nho hon n");
    printf("\n5. Tim USCLN cua 2 so");
    printf("\n6. In phan so toi gian");
    printf("\n7. Thoat");
}
int main() {
    int lc;
    do {
        menu();
        printf("\nLua chon: ");
        scanf("%d",&lc);
        switch (lc) {
        case 1:
            check_snt();
            break;
        case 2:
            snt_n();
            break;
        case 3:
            check_sohhn();
            break;
        case 4:
            sohhn();
            break;
        case 5:
            tim_ucln();
            break;
        case 6:
            u_cln();
            break;
        case 7:
            exit(1);
        default: {
            printf("\nLua chon khong hop le");
            break;
        }
        }
    } while (lc!=7);
    return 0;
}
