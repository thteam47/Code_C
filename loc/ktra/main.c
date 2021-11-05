#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //phan a
    char c;
    printf("Nhap 6 ki tu: ");
    int dem_ct=0, dem_s=0, dem_ch=0;
    for (int i=0; i<6; i++)
    {
        scanf("%c",&c);
        if (c>='0'&&c<='9')
            dem_s++;
        else if (c>='a'&&c<='z')
            dem_ct++;
        else if (c>='A'&&c<='Z')
            dem_ch++;
    }
    printf("\nSo chu so: %d",dem_s);
    printf("\nSo chu hoa: %d",dem_ch);
    printf("\nSo chu thuong: %d",dem_ct);
    //phan b
    int n=dem_s+dem_ct;
    printf("\nTong ki tu thuong va ki tu so la: %d",n);
    //phan c
    float S=0;
    for (int i=2;i<=n;i++){
        int giai_thua=1;
        for (int j=1;j<=i+1;j++){
            giai_thua *= j;
        }
        S+= pow(-1,i)*(i+1)/(float)(giai_thua);
    }
    printf("\nGia tri S = %f",S);
    return 0;
}
