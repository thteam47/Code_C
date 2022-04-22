#include <stdio.h>
#include <stdlib.h>
void NhapMang(int *a, int n) {
    for(int i = 0; i < n; ++i) {
        printf("\nNhap phan tu a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
int checkSNT (int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i < (n - 1); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {

    int n;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    int a[n];
    int count =0;
    NhapMang(a,n);
    int snt = 0;
    for (int i=0; i<n; i++) {
        if (checkSNT(a[i])==1) {
            snt = a[i];
            count++;
        }
    }
    if (count ==0) {
        printf("Khong co so nguyen to nao");
    } else {
        printf("So nguyen to cuoi cung la: %d",snt);
    }
    return 0;
}
