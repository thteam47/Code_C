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
int max_hang (int a[][MAX],int n, int m) {
    int max=a[n][0];
    for (int i=0; i<m; i++) {
        if (a[n][i]>max)
            max=a[n][i];
    }
    return max;
}
int min_cot (int a[][MAX],int n, int m) {
    int min=a[0][m];
    for (int i=0; i<n; i++) {
        if (a[i][m]<min)
            min=a[i][m];
    }
    return min;
}
void xuat (int a[][MAX],int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void search_max_min (int a[][MAX],int n, int m) {
    int dem=0;
    int i,j;
    printf("\nphan tu lon nhat dong va nho nhat cot la:\n");
    for ( i=0;i<n;i++){
        for ( j=0;j<m;j++){
            if (a[i][j]==max_hang(a,i,m))
                break;
        }
        if (max_hang(a,i,m)==min_cot(a,n,j)) {
            dem++;
            printf("%d\t",a[i][j]);
        }
    }
    if (dem==0) printf("khong co");
}
int main() {
    int a[MAX][MAX];
    int m,n;
    printf("nhap dong: ");
    scanf("%d",&n);
    printf("nhap cot: ");
    scanf("%d",&m);
    nhap(a,n,m);
    xuat(a,n,m);
    search_max_min(a,n,m);
    return 0;
}
