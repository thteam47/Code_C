#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[10][10], b[10][10], c[10][10], m,n,p,q,i,j,k;
    int sum = 0;

    printf("\nNhap ma tran dau tien:\n");
    printf("\nnhap dong: ");
    scanf("%d",&m);
    printf("\nnhap cot: ");
    scanf("%d",&n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nNhap ma tran thu hai:\n");
    printf("\nnhap dong: ");
    scanf("%d",&p);
    printf("\nnhap cot: ");
    scanf("%d",&q);
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("b[%d][%d] = ",i+1,j+1);
            scanf("%d", &b[i][j]);
        }
    }

    printf("Ma tran dau tien: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("Ma tran thu hai: \n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    if (n==p) {
        //phep nhan ma tran
        for (i = 0; i < m; i++) {
            for (j = 0; j < q; j++) {
                sum = 0;
                for (k = 0; k < n; k++) {
                    sum = sum + a[i][k] * b[k][j];
                }
                c[i][j] = sum;
            }
        }
        printf("\nTich cua hai ma tran la: \n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < q; j++) {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    } else
        printf("\nkhong ton tai tich hai ma tran");
    return (0);
}
