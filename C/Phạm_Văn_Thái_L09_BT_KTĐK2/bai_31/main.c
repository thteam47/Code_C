#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    printf("nhap cot: ");
    scanf("%d",&n);
    printf("\nnhap dong: ");
    scanf("%d",&m);
    int a[20][20],b[20][20];
    for (int i=0; i<m;i++){
        for (int j=0; j<n;j++){
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    FILE *fp;
    //mo file
    fp = fopen("ma_tran.C","wt");
    fprintf(fp,"%d ""%d",n,m);
    fputs("\nMa tran A\n",fp);
    for (int i=0; i<m;i++){
        for (int j=0;j<n;j++){
            fprintf(fp,"%-8d",a[i][j]);
        }
        fprintf(fp,"\n");
    }
    //dong file
    fclose(fp);
    printf("\nDa tao xong tep ma_tran.c");
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++){
            b[i][j]=a[j][i];
        }
    }
    fp= fopen("ma_tran.C","at");
    fputs("ma trận chuyển vị Bm*n\n",fp);
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++){
            fprintf(fp,"%-8d",b[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("\ntao xong ma tran chuyen vi");
    return 0;
}
