#include <stdio.h>
#include <stdlib.h>
//ham nhap mang
void nhap_mang(int *a,int n) {
    printf("\nnhap phan tu mang:\n");
    for (int i=0; i<n; i++) {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}
//ham xuat mang
void xuat_mang(int *a,int n) {
    printf("\ncac phan tu cua mang la: \n");
    for (int i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
}
//check day tang
int check_day_tang(int *a, int n){
    for (int i=0; i<n-1; i++) {
        if (a[i] >= a[i+1]) {
            return 0;
        }
    }
    return 1;
}
//check so hoan hao

int check_so_hoan_hao(int n){
    if (n<0) return 0;
    int sum = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)
            sum+=i;
    }
    if(sum==n) return 1;
    return 0;
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
    int *a= (int*)malloc(n*sizeof(int));
    printf("phan a \n");
    nhap_mang(a,n);
    printf("\nphan b \n");
    xuat_mang(a,n);
    printf("\nphan c \n");
    if (check_day_tang(a, n)==1 ){
        printf("\nDay tang");
    }else {
        printf("\nKhong phai la day tang");
    }
    printf("\nphan d \n");
    printf("Cac so hoan hao co trong day la \n");
    int dem =0;
    for (int i=0; i<n;i++){
        if (check_so_hoan_hao(a[i])==1) {
            printf("%d\t",a[i]);
            dem ++;
        }
    }
    if (dem==0) printf("Khong co \n");
    return 0;
}
