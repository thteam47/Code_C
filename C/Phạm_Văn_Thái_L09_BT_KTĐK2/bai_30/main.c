#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    printf("nhap cot: ");
    scanf("%d",&n);
    printf("\nnhap dong: ");
    scanf("%d",&m);
    int a[20][20];
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
    fprintf(fp,"%s","\nMa tran A\n");
    for (int i=0; i<m;i++){
        for (int j=0;j<n;j++){
            fprintf(fp,"%-8d",a[i][j]);
        }
        fprintf(fp,"%c",'\n');
    }
    //dong file
    fclose(fp);
    printf("\nDa tao xong tep ma_tran.c");
    return 0;
}
