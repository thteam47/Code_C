#include <stdio.h>
#include <stdlib.h>

typedef struct hang {
    char ten_hang[20];
    float don_gia;
    int so_luong;
    float thanh_tien;
}HANG;
long size = sizeof (HANG);
int main()
{
    HANG h;
    char chon='1';
    int i=1;

    FILE *fp;
    fp = fopen("SO_LIEU.C","wb");
    printf("Nhap thong tin cac mat hang. Dung khi nhap 0");
    do{
        printf("\nThong tin mat hang thu %d",i++);
        printf("\nTen hang: ");
        fflush(stdin);
        gets(h.ten_hang);
        printf("Don gia: ");
        fflush(stdin);
        scanf("%f",&h.don_gia);
        printf("So Luong: ");
        scanf("%d",&h.so_luong);
        h.thanh_tien= (float)h.don_gia*h.so_luong;
        fseek(fp,0,2);
        fwrite(&h,size,1,fp);
        printf("co muon nhap nua khong: ");
        fflush(stdin);
        chon= getchar();
    } while (chon != '0');
    fclose(fp);
    printf("SO LIEU BAN HANG\n");
    printf("%-5s %-10s %-10s %-15s %-15s","STT", "Ten Hang", "Don Gia","So Luong","Thanh Tien");

    i=1;
    fp= fopen("SO_LIEU.C","rb");
    fseek(fp,0,0);
    float tong=0;
    while (fread(&h,size,1,fp)>0){
        printf("\n%-5d %-10s %-10.1f %-15d %-15.1f",i++,h.ten_hang,h.don_gia,h.so_luong,h.thanh_tien);
        tong += h.thanh_tien;
    }
    printf("\n%45s: %.1f","Tong",tong);
    fclose(fp);
    return 0;
}
