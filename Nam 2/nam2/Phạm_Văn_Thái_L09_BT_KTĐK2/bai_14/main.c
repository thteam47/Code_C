#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//khai báo struct sinh viên
struct SinhVien {
    char HoTen[30];
    char MaSv[4];
    int Tuoi;
    char Lop[10];
};
typedef struct SinhVien SV;
//khai bao prototype cho ds sv
struct danhsach {
    SV dssv[100];
    int siso;
};
typedef struct danhsach DanhSach;

//nhập thông tin 1 sinh viên
void NhapThongTinSinhVien (SV *sv) {
   do {
        printf("\nHo Ten Sinh Vien: ");
        fflush(stdin);
        gets(sv->HoTen);
        if (strlen(sv->HoTen)>30)
            printf("\nDo dai ten nho hon 30 ki tu. Hay Nhap Lai");
    } while (strlen(sv->HoTen)>30);
    do {
        printf("Ma So Sinh Vien: ");
        fflush(stdin);
        gets(sv->MaSv);
        if (strlen(sv->MaSv)>3)
            printf("\nDo dai MSSV nho hon 3 ki tu. Hay Nhap Lai");
    } while (strlen(sv->MaSv)>3);
    do {
        printf("Tuoi: ");
        fflush(stdin);
        scanf("%d",&sv->Tuoi);
        if (sv->Tuoi<0) {
            printf("\nTuoi sai. Nhap lai");
        }
    } while (sv->Tuoi<0);
    do {
        printf("Lop: ");
        fflush(stdin);
        gets(sv->Lop);
        if (strlen(sv->Lop)>10)
            printf("\nDo dai Lop nho hon 10 ki tu. Hay Nhap Lai");
    } while (strlen(sv->Lop)>10);
}
void XuatThongTinSinhVien (SV sv) {
    printf("\r\n%-30s\t%-10s\t%-10d\t%-10s\t\n", sv.HoTen, sv.MaSv, sv.Tuoi, sv.Lop);
}
//nhập dữ liệu cho danh sách
void Input (DanhSach *ds) {
    do {
        printf("Nhap So Luong Sinh Vien: ");
        scanf("%d",&ds->siso);
        if (ds->siso>100)
            printf("So Luong Sinh Vien Toi Da 70. Hay Nhap Lai");
    } while (ds->siso>100);
    for (int i=0; i<ds->siso; i++) {
        printf("\nNhap Thong Tin Sinh Vien Thu %d",i+1);
        NhapThongTinSinhVien(&ds->dssv[i]);
    }
}

void Output (DanhSach ds) {
    printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
    for (int i=0; i<ds.siso; i++) {
        XuatThongTinSinhVien(ds.dssv[i]);
    }
}
void search_name (DanhSach ds) {
    char tensv[10];
    printf("\nNhap Ten Sinh Vien Muon Tim Kiem: ");
    fflush(stdin);
    gets(tensv);
    int i,d,h,k,u;
    int dem=0;
    char atensv[15];
    for (i=0; i<ds.siso; i++) {
        u=strlen(ds.dssv[i].HoTen);
        for (d=u-1; d>0; d--) {
            if ((ds.dssv[i].HoTen[d])== ' ') {
                break;
            }
        }
        k=0;
        for (h=d+1; h<u; h++) {
            atensv[k++]=ds.dssv[i].HoTen[h];
        }
        if (strcmp(atensv,tensv)==0) {
            printf("\nThong Tin Sinh Vien Co Ten %s:\n",tensv);
            printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
            XuatThongTinSinhVien(ds.dssv[i]);
            dem++;
        }
    }
    if (dem==0)
        printf("\nKhong co");

}
void swap(SV *a,SV *b) {
    SV tg;
    tg=*a;
    *a=*b;
    *b=tg;
}
void sort_msv (DanhSach ds) {
    printf("\nSap Xep Sinh Vien Theo Chieu Tang Ma Sinh Vien:\n");
    printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
    for (int i=0; i<ds.siso-1; i++) {
        for (int j=1; j<ds.siso; j++) {
            if (strcmp(ds.dssv[i].MaSv,ds.dssv[j].MaSv)>0)
                swap(&ds.dssv[i],&ds.dssv[j]);
        }
    }
    for (int i=0; i<ds.siso; i++) {
        XuatThongTinSinhVien(ds.dssv[i]);
    }
}
void search_msv (DanhSach ds) {
    char msv[4];
    do {
        printf("\nNhap Ma Sinh Vien Muon Tim Kiem: ");
        fflush(stdin);
        gets(msv);
        if (strlen(msv)>3)
            printf("\nDo dai MSSV nho hon 3 ki tu. Hay Nhap Lai");
    } while (strlen(msv)>3);
    int dem=0;
    for (int i=0; i<ds.siso; i++) {
        if ((strcmp(msv,ds.dssv[i].MaSv)==0)) {
            printf("\nThong Tin Sinh Vien Co Ma Sinh Vien %s:\n",msv);
            printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
            XuatThongTinSinhVien(ds.dssv[i]);
            dem++;
        }
    }
    if (dem==0)
        printf("\nKhong co");
}
void menu(){
    printf("\n========MENU=======");
    printf("\n1. Nhap Danh Sach Sinh Vien");
    printf("\n2. Hien Thi Danh Sach Sinh Vien");
    printf("\n3. Tim Kiem Sinh Vien Theo Ten");
    printf("\n4. Sap Xep Danh Sach Sinh Vien Theo Chieu Tang Cua Ma Sinh Vien");
    printf("\n5. Tim Kiem Sinh Vien Theo Ma Sinh Vien");
    printf("\n6. Ket Thuc");
    printf("\nLua Chon: ");
}
int main() {
    DanhSach *ds = (DanhSach*)malloc(sizeof(DanhSach));
tiep:
    menu();
    int lc;
    scanf("%d",&lc);
    if (lc==6)
        exit(1);
    while (lc!=1&&lc!=6) {
        printf("\nChua Nhap Danh Sach Sinh Vien");
        goto tiep;
    }
nhap:
    Input(ds);
luachon:
    menu();
    int lc1;
    scanf("%d",&lc1);
    switch (lc1) {
    case 1:
        goto nhap;
        break;
    case 2:
        Output(*ds);
        goto luachon;
        break;
    case 3:
        search_name(*ds);
        goto luachon;
        break;
    case 4:
        sort_msv(*ds);
        goto luachon;
        break;
    case 5:
        search_msv(*ds);
        goto luachon;
        break;
    case 6:
        break;
    default:
        break;
    }
    free(ds);
    return 0;
}
