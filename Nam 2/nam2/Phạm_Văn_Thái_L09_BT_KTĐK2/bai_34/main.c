#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void doc_matran (int a[][MAX],int n,int m, FILE *fp){
    for (int i=0; i<n; i++){
        for (int j=0; j<m;j++){
            fscanf(fp,"%d",&a[i][j]);
        }
    }
}

int main()
{
    int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
    int m,n,p;
    char x[5],y[20];
    FILE *fp;
    fp = fopen("TICH_MT.C","r+t");
    if (fp==NULL) {
        printf("file TICH_MT.C khong ton tai");
        return 0;
    }
    fscanf(fp, "%d %d %d",&n,&p,&m);
    fgets (x,5, fp);
    fgets (y,30, fp);
    doc_matran(a,n,p,fp);
    fgets (x,5, fp);
    fgets (y,30, fp);
    doc_matran(b,p,m,fp);
    fseek(fp,0,2);
    fputs("Ma tran tich C\n",fp);
    for (int i=0;i<n;i++){
        for (int j=0; j<m;j++){
            for (int k=0;k<p;k++){
                c[i][j]= a[i][k]*b[k][j];
            }
            fprintf(fp,"%d\t",c[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
