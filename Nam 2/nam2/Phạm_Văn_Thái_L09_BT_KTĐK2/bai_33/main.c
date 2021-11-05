#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void nhap (int a[][MAX], int n, int m, char x){
    printf("\nNhap ma tran %c\n",x);
    for (int i=0; i<n;i++){
        for (int j=0;j<m;j++) {
            printf("%c[%d][%d] = ",x,i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
}
void cong (int a[][MAX],int b[][MAX],int c[][MAX], int n, int m){
    for (int i=0; i<n;i++){
        for (int j=0;j<m;j++) {
            c[i][j]= a[i][j] +b[i][j];
        }}
}
void xuat_file (int a[][MAX], int n, int m, char x,FILE *fp) {
    fseek(fp,0,2);
    fprintf(fp,"Ma tran %c\n",x);
    for (int i=0; i<n;i++){
        for (int j=0;j<m;j++) {
            fprintf(fp,"%-6d",a[i][j]);
        }
        fprintf(fp,"\n");
        }
}
int main()
{
    int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
    int n,m;
    printf("\nnhap dong: ");
    scanf("%d",&n);
    printf("nhap cot: ");
    scanf("%d",&m);
    nhap(a,n,m,'A');
    nhap(b,n,m,'B');
    cong(a,b,c,n,m);
    FILE *fp = fopen("CONG_MT.C","w");
    xuat_file(a,n,m,'A',fp);
    xuat_file(b,n,m,'B',fp);
    xuat_file(c,n,m,'C',fp);
    fclose(fp);
    return 0;
}
