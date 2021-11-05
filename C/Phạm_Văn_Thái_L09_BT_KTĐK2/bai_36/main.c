#include <stdio.h>
#include <stdlib.h>

typedef struct SINHVIEN {
    char ho_ten[30];
    int tuoi;
    float diem_TB;
} sinhvien;
long size = sizeof (sinhvien);
void ghi_file() {
    FILE *fp;
    sinhvien sv;
    char chon='1';
    int i=1;
    fp = fopen("DSACH.C","wb");
    printf("\nNhap thong tin sinh vien. Dung khi nhap 0");
    do {
        printf("Thong tin sinh vien thu %d",i++);
        printf("\nHo ten: ");
        fflush(stdin);
        gets(sv.ho_ten);
        printf("Tuoi: ");
        fflush(stdin);
        scanf("%d",&sv.tuoi);
        printf("Diem TB: ");
        scanf("%f",&sv.diem_TB);
        fseek(fp,0,2);
        fwrite(&sv,size,1,fp);
        printf("co muon nhap nua khong: ");
        fflush(stdin);
        chon= getchar();
    } while (chon != '0');
    fclose(fp);
}
void bo_sung() {
        sinhvien sv;
    FILE *fp;
    char chon='1';
    fp = fopen("DSACH.C","r+b");
    fseek(fp,0,2);
    int i= (ftell(fp)/size)+1;
    printf("\nNhap thong tin sinh vien. Dung khi nhap 0");
    do {
        printf("\nThong tin sinh vien thu %d",i++);
        printf("\nHo ten: ");
        fflush(stdin);
        gets(sv.ho_ten);
        printf("Tuoi: ");
        fflush(stdin);
        scanf("%d",&sv.tuoi);
        printf("Diem TB: ");
        scanf("%f",&sv.diem_TB);
        fseek(fp,0,2);
        fwrite(&sv,size,1,fp);
        printf("co muon nhap nua khong: ");
        fflush(stdin);
        chon= getchar();
    } while (chon != '0');
    fclose(fp);
}
void hien_thi () {
        sinhvien sv;
    FILE *fp;
    printf("DANH SACH SINH VIEN\n");
    printf("%-5s %-20s %-10s %-10s","STT", "Ho Ten", "Tuoi","Diem TB");
    int i=1;
    fp= fopen("DSACH.C","rb");
    fseek(fp,0,0);
    while (fread(&sv,size,1,fp)>0) {
        printf("\n%-5d %-20s %-10d %-10.1f",i++,sv.ho_ten,sv.tuoi,sv.diem_TB);
    }
    fclose(fp);
}
int main() {
    ghi_file();
    hien_thi();
    printf("\nbo sung sinh vien");
    bo_sung();
    hien_thi();
    return 0;
}
