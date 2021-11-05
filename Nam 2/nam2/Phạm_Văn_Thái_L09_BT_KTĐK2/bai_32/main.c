#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SinhVien {
    char ten[20];
    float dtb;
} sinhvien;
long size = sizeof(sinhvien);
char ten[20]= "sinh_vien.c";
void tao_tep () {
    sinhvien sv;
    int i=0;
    FILE *fp;
    fp = fopen(ten,"wb");
    printf("nhap thong tin sinh vien, ket thuc khi chon 0");
    char chon= '1';
    do {
        printf("\nThong tin sinh vien thu %d",++i);
        printf("\nTen: ");
        fflush(stdin);
        gets(sv.ten);
        printf("Diem trung binh: ");
        fflush(stdin);
        scanf("%f",&sv.dtb);
        printf("\nco muon nhap nua khong: ");
        fflush(stdin);
        fwrite(&sv,size,1,fp);
        chon = getchar();
    } while (chon != '0');
    fclose(fp);
}
void hien_thi () {
    sinhvien sv;
    FILE *fp;
    fp = fopen(ten,"rb");
    if (fp==NULL){
         printf("\ntep khong ton tai");
         return;
    }
    rewind(fp);
    int i=0;
    printf("\n%-5s %-15s %-10s","STT", "Ten","Diem TB");
    while (fread(&sv,size,1,fp)>0) {
        printf("\n%-5d %-15s %-10.1f",++i,sv.ten,sv.dtb);
    }
    fclose(fp);
}
void bo_sung () {
    sinhvien sv;
    FILE *fp;
    fp = fopen(ten,"r+b");
    if (fp==NULL) fp = fopen(ten,"wb");
    fseek(fp,0,SEEK_END);
    int i=ftell(fp)/size;
    printf("nhap thong tin sinh vien, ket thuc khi chon 0");
    char chon= '1';
    do {
        printf("\nThong tin sinh vien thu %d",i+1);
        printf("\nTen: ");
        fflush(stdin);
        gets(sv.ten);
        printf("Diem trung binh: ");
        fflush(stdin);
        scanf("%f",&sv.dtb);
        printf("\nco muon nhap nua khong: ");
        fflush(stdin);
        fwrite(&sv,size,1,fp);
        chon = getchar();
    } while (chon != '0');
    fclose(fp);
}
void sua() {
    char name[20];
    printf("\nten sinh vien can sua: ");
    fflush(stdin);
    gets (name);
    FILE *fp;
    fp = fopen(ten, "r+b");
    if (fp==NULL){
         printf("\ntep khong ton tai");
         return;
    }
    int dem=0;
    sinhvien sv;
    while (fread(&sv,size,1,fp)>0&&dem==0) {
        if (strcmp(sv.ten,name)==0) {
            dem++;
            printf("\nnhap thong tin can sua:");
            printf("\nnhap ten: ");
            fflush(stdin);
            gets (sv.ten);
            printf("\nnhap diem trung binh: ");
            fflush(stdin);
            scanf("%f",&sv.dtb);
            fseek(fp,-size,1);
            fwrite(&sv,size,1,fp);
            fclose(fp);
            return;
        }
    }
    if (dem==0)
        printf("\nkhong co sinh vien can sua");
}
void menu(){
    printf("\n1. Tao tep");
    printf("\n2. Bo sung sinh vien");
    printf("\n3. Sua thong tin sinh vien");
    printf("\n4. Hien thi thong tin");
    printf("\n5. Ket thuc");

    }
int main() {
    int chon1;
    do {
        menu();
        printf("\nLua chon: ");
        fflush(stdin);
        scanf("%d",&chon1);
        switch (chon1) {
        case 1: tao_tep();
        break;
        case 2: bo_sung();
        break;
        case 3: sua();
        break;
        case 4: hien_thi();
        break;
        case 5: exit(1);
        break;
        }
    } while (chon1 !=5);
    getch();
    return 0;
}
