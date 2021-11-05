#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct hoten {
    char ho[15];
    char ten_dem[15];
    char ten[15];
};
typedef struct hoten HOTEN;
struct quequan {
    char xa[15];
    char huyen[15];
    char tinh[15];
};
typedef struct quequan QUEQUAN;
struct diemthi {
    float toan;
    float li;
    float hoa;
};
typedef struct diemthi DIEMTHI;
struct sinhvien {
    HOTEN ho_ten;
    QUEQUAN que_quan;
    char truong[30];
    int tuoi;
    char sbd[15];
    DIEMTHI diem;
};
typedef struct sinhvien SV;
struct DanhSach {
    int siso;
    SV dssv[20];
};
typedef struct DanhSach DS;
void Nhap_Thong_Tin (SV *sv) {
    printf("\nNhap Thong Tin Sinh Vien");
    printf("\nHo Ten Sinh Vien:");
    printf("\nHo: ");
    fflush(stdin);
    gets(sv->ho_ten.ho);
    printf("Ten Dem: ");
    fflush(stdin);
    gets(sv->ho_ten.ten_dem);
    printf("Ten: ");
    fflush(stdin);
    gets(sv->ho_ten.ten);
    printf("Que Quan Sinh Vien");
    printf("\nXa: ");
    fflush(stdin);
    gets(sv->que_quan.xa);
    printf("Huyen: ");
    fflush(stdin);
    gets(sv->que_quan.huyen);
    printf("Tinh: ");
    fflush(stdin);
    gets(sv->que_quan.tinh);
    printf("Truong: ");
    fflush(stdin);
    gets(sv->truong);
    fflush(stdin);
    printf("Tuoi: ");
    scanf("%d",&sv->tuoi);
    printf("So Bao Danh ");
    fflush(stdin);
    gets(sv->sbd);
    printf("Diem Thi");
    printf("\nDiem Toan: ");
    fflush(stdin);
    scanf("%f",&sv->diem.toan);
    printf("Diem Ly: ");
    scanf("%f",&sv->diem.li);
    printf("Diem Hoa: ");
    scanf("%f",&sv->diem.hoa);
}
void Xuat_Thong_Tin (SV sv) {
    printf("\n- Ho Ten: %s %s %s",sv.ho_ten.ho,sv.ho_ten.ten_dem,sv.ho_ten.ten);
    printf("\n- Que Quan: %s - %s - %s",sv.que_quan.xa,sv.que_quan.huyen,sv.que_quan.tinh);
    printf("\n- Truong: %s",sv.truong);
    printf("\n- Tuoi: %d",sv.tuoi);
    printf("\n- So Bao Danh: %s",sv.sbd);
    printf("\n- Diem Thi:");
    printf("\nToan: %.2f\t Ly: %.2f\t Hoa: %.2f",sv.diem.toan,sv.diem.li,sv.diem.hoa);
}
void Danh_Sach_Sinh_Vien (DS *ds ) {
    do {
        printf("Nhap So Luong Sinh Vien: ");
        scanf("%d",&ds->siso);
        if (ds->siso>20) {
            printf("\nSo Luong Sinh Vien Nho Hon 20. Nhap Lai\n");
        }
    } while (ds->siso>20);
    for (int i=0; i<ds->siso; i++) {
        printf("\n==== Thong Tin Sinh Vien Thu %d ===",i+1);
        Nhap_Thong_Tin(&ds->dssv[i]);
    }
}
void Xuat_DS_Sinh_Vien (DS ds) {
    for (int i=0; i<ds.siso; i++) {
        printf("\n=== Thong Tin Sinh Vien Thu %d ===",i+1);
        Xuat_Thong_Tin(ds.dssv[i]);
    }
}
void Tim_Sinh_Vien (DS ds) {
    int thu_tu=1;
    printf("\n=== Danh Sach Sinh Vien Co Tong 3 Mon Lon Hon 15\n");
    for (int i=0; i<ds.siso; i++) {
        if ((ds.dssv[i].diem.toan+ds.dssv[i].diem.li+ds.dssv[i].diem.hoa)>15) {
            printf("\nSinh Vien Thu %d",thu_tu);
            Xuat_Thong_Tin(ds.dssv[i]);
            thu_tu++;
        }
    }
}
void swap (SV *a, SV *b) {
    SV tg=*a;
    *a=*b;
    *b=tg;
}
void sap_xep (DS ds) {
    for (int i=0; i<ds.siso-1; i++) {
        for (int j=1; j<ds.siso; j++) {
            if ((ds.dssv[i].diem.hoa+ds.dssv[i].diem.li+ds.dssv[i].diem.toan)<(ds.dssv[j].diem.hoa+ds.dssv[j].diem.li+ds.dssv[j].diem.toan)) {
                swap(&ds.dssv[i],&ds.dssv[j]);
            }
        }
    }
    printf("\n===Danh Sach Sinh Vien So Diem Giam Dan\n");
    Xuat_DS_Sinh_Vien(ds);
}
void them (DS *ds) {
    char name[20];
    printf("\nNhap ten sinh vien truoc: ");
    fflush(stdin);
    gets(name);
    int dem=0;
    for (int i=0; i<ds->siso; i++) {
        if (strcmp(ds->dssv[i].ho_ten.ten,name)==0) {
            printf("\nnhap thong tin sinh vien can them:");
            SV x;
            Nhap_Thong_Tin(&x);
            for (int k=ds->siso; k>i; k--) {
                ds->dssv[k]=ds->dssv[k-1];
            }
            ds->dssv[i+1]=x;
            printf("\nda them xong");
            dem++;
            ds->siso++;
            break;
        }
    }
    if (dem==0)
        printf("\nkhong co sinh vien %s",name);
}
void xoa (DS *ds) {
    char name[20];
    printf("\nNhap ten sinh vien can xoa: ");
    fflush(stdin);
    gets(name);
    int dem=0;
    for (int i=0; i<ds->siso; i++) {
        if (strcmp(ds->dssv[i].ho_ten.ten,name)==0) {
            for (int k=i; k<ds->siso-1; k++) {
                ds->dssv[k]=ds->dssv[k+1];
            }
            printf("\nda xoa xong");
            dem++;
            ds->siso--;
            break;
        }
    }
    if (dem==0)
        printf("\nkhong co sinh vien %s",name);
}
void menu() {
    printf("\n1. Nhap thong tin sinh vien va in sinh vien");
    printf("\n2. Tim sinh vien tong diem tren 15");
    printf("\n3. Sap xep sinh vien diem giam dan");
    printf("\n4. Them sinh vien sau ten sinh vien cho truoc");
    printf("\n5. Xoa sinh vien");
    printf("\n6. Xuat danh sach");
    printf("\n7. Ket thuc");
}
int main() {
    DS *ds=(DS*)malloc(sizeof(DS));
    int chon;
    do {
        menu();
        printf("\nLua chon: ");
        fflush(stdin);
        scanf("%d",&chon);
        switch (chon) {
        case 1:
            Danh_Sach_Sinh_Vien(ds);
            Xuat_DS_Sinh_Vien(*ds);
            break;
        case 2:
            Tim_Sinh_Vien(*ds);
            break;
        case 3:
            sap_xep(*ds);
            break;
        case 4:
            them(ds);
            break;
        case 5:
            xoa(ds);
            break;
        case 6:
            Xuat_DS_Sinh_Vien(*ds);
            break;
        }
    } while (chon !=7);
    free(ds);
    return 0;
}
