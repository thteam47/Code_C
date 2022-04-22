#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
void nhapMang(int a[], int n) {
    if(n>0) {
        nhapMang(a, n-1);
        printf("Nhap vao phan tu thu: %d: ", n);
        scanf("%d", &a[n]);
    }
}
void xuatMang(int a[], int n) {
    if(n>0) {

        xuatMang(a, n-1);
        printf("%d ", a[n]);
    }
}

int Tong(int a[], int n) {
    if ( n == 0) {
        if( a[n]%2 == 0)
            return 0;
        else
            return a[n];
    }
    if ( a[n] % 2 == 0)
        return Tong(a, n-1);
    else
        return Tong(a, n-1) + a[n];
}
int TimMax(int a[], int n, int *vt) {
    if(n == 1) {
        *vt = n;
        return a[0];
    } else if(a[n-1] > TimMax(a,n-1,vt)) {
        *vt = n;
        return a[n-1];
    } else
        return TimMax(a, n-1, vt);
}
void menu() {
    printf("\n========MENU=======");
    printf("\n1. Nhap mang");
    printf("\n2. Xuat mang");
    printf("\n3. Tinh tong so le");
    printf("\n4. Tim phan tu lon nhat");
    printf("\n5. Ket Thuc");
    printf("\nLua Chon: ");
}
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main() {
    int a[100];
    int n;
    int lc1;
    int index = 0;
    do {
        menu();
        fflush(stdin);
        scanf("%d",&lc1);
        switch (lc1) {
        case 1:
            printf("Nhap so phan tu: ", n);
            scanf("%d", &n);
            nhapMang(a,n);
            break;
        case 2:
            xuatMang(a,n);
            break;
        case 3:
            printf("Tong le: %d", Tong(a, n));
            break;
        case 4:
            TimMax(a, n, &index);
            printf("Vi tri max la: %d", index);
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (lc1!=5);
    int x = 10;
    printf("Nhap phan tu can tim: ", x);
    scanf("%d", &x);
    int result = binarySearch(a, 0, n - 1, x);
    if (result == -1)
        printf("%d xuat hien tai chi so %d", x, result);
    else
        printf("%d xuat hien tai chi so %d", x, result);
    return 0;
}
