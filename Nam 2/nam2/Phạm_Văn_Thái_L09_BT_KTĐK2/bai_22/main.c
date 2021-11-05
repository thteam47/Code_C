#include <stdio.h>
#include<conio.h>
#define MAX 100
int i,n,m,min;
float x,P[MAX],Q[MAX],T[MAX],sum;
void nhap_dt(float a[],int *n,char ten) {
    printf("\nNhap so he so cua da thuc %c: ",ten);
    scanf("%d",n);
    while(*n<0) {
        printf("Gia tri ban nhap khong hop le, moi ban nhap lai !\n");
        printf("Nhap so he so cua da thuc %c: ",ten);
        scanf("%d",n);
    }
    printf("Nhap cac he so cua da thuc %c:\n",ten);
    for(i=0; i<*n; i++) {
        printf("%c[%d]=",ten,i);
        scanf("%f",&a[i]);
    }
}
void heso_dtTong(float a[],float b[],float c[],int n,int m) {
    int i=0;
    int min=(n<m)?n:m;
    for(int k=0; k<=min; k++)
        c[i++]=a[k]+b[k];
    if(n>m) {
        for(int k=min+1; k<n; k++)
            c[i++]=a[k];
    } else {
        for(int k=min+1; k<m; k++)
            c[i++]=b[k];
    }
    printf("\nhe so da thuc tong: ");
    for (int k=0;k<i;k++){
        printf("%.1f\t",c[k]);
    }
}
float luy_thua(float x,int n) {
    if(n==0)
        return 1;
    if(n==1)
        return x;
    else
        return x*luy_thua(x,n-1);
}
void tinh_dt(float a[],float x,int n,char ten) {
    sum=a[0];
    for(i=1; i<=n; i++)
        sum+=a[i]*luy_thua(x,i);
    printf("\nGia tri cua da thuc %c la %.2f",ten,sum);
}
void in_heso_dt(float a[],int n,char ten) {
    printf("\nHe so cua da thuc %c:\t",ten);
    for(i=0; i<=n; i++) {
        printf("%.2f\t",a[i]);
    }
}
void menu(){
    printf("\nCHON CHUC NANG CAN THUC HIEN:\n");
    printf("1. Nhap he so cho 2 da thuc P va Q\n");
    printf("2. Tinh he so cua da thuc tong T\n");
    printf("3. In he so cua 3 da thuc P,Q,T\n");
    printf("4. In gia tri cua 3 da thuc P,Q,T\n");
    printf("5. Ket thuc\n");
}
int main() {
    char chon;
    printf("Nhap gia tri cho x: x=");
    scanf("%f",&x);

    do {
            menu();
        fflush(stdin);
        chon=getch();
        switch(chon) {
        case '1':
            nhap_dt(P,&n,'P');
            nhap_dt(Q,&m,'Q');
            break;
        case '2':
            heso_dtTong(P,Q,T,n,m);
            break;
        case '3':
            in_heso_dt(P,n,'P');
            in_heso_dt(Q,m,'Q');
            in_heso_dt(T,(n>m)?n:m,'T');
            break;
        case '4':
            printf("\n");
            tinh_dt(P,x,n,'P');
            tinh_dt(Q,x,m,'Q');
            tinh_dt(T,x,(n>m)?n:m,'T');
            break;
        }
    } while(chon!='5');
    return 0;
}
