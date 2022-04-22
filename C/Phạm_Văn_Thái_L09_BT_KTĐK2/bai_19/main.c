#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[2]= "A";
char c[2]= "C";
struct sinhvien {
    char ho_ten[30];
    char khoi[2];
    int sbd;
};
typedef struct sinhvien SV;
struct danhsach {
    int so_sv;
    SV dssv[100];
};
typedef struct danhsach DS;
//nhap thong tin 1 sinh vien
void thong_tin_1_sinh_vien (SV *sv) {

    do {
        printf("\nHo ten: ");
        fflush(stdin);
        gets (sv->ho_ten);
        if (strlen(sv->ho_ten)>30)
            printf("\nDo dai ho ten nho hon 30 ki tu. Nhap lai.\n");
    } while (strlen(sv->ho_ten)>30);
    int check;
    do {
        printf("Khoi: ");
        fflush(stdin);
        gets(sv->khoi);
        char *k = strupr(sv->khoi);
        if (strcmp(k,a)==0) {
            check=1;

        } else if (strcmp(k,c)==0) {
            check=1;
        } else {
            check=0;
            printf("\nkhoi khong hop le. nhap lai.\n");
        }
    } while (check==0);
    do {
        printf("So bao danh: ");
        fflush(stdin);
        scanf("%d",&sv->sbd);
        if (sv->sbd<1)
            printf("\nso bao danh khong hop le. nhap lai\n");
    } while (sv->sbd<1);
}
void xuat_thong_tin (SV sv,int i) {
    printf("\n%-3d %-20s %-5d",i,sv.ho_ten,sv.sbd);
}
void danh_sach_sinh_vien (DS *ds) {
    do {
        printf("Nhap so sinh vien: ");
        fflush(stdin);
        scanf("%d",&ds->so_sv);
        if (ds->so_sv<1)
            printf("\nSo luong sinh vien khong hop le. Nhap lai\n");
    } while (ds->so_sv<1);
    for (int i=0; i<ds->so_sv; i++) {
        printf("\nNhap thong sinh vien thu %d",i+1);
        thong_tin_1_sinh_vien(&ds->dssv[i]);
    }
}
void xuat_a_c (DS ds) {
    int ad=1,cd=1;
    printf("\nDANH SACH SINH VIEN KHOI %s\n",a);
    printf("\n%-3s %-20s %-5s","STT", "Ho Ten", "SBD");
    for (int i=0; i<ds.so_sv; i++) {
        char *k = strupr(ds.dssv[i].khoi);
        if (strcmp(k,a)==0) {
            xuat_thong_tin(ds.dssv[i],ad++);
        }
    }
    printf("\nDANH SACH SINH VIEN KHOI %s\n",c);
    printf("\n%-3s %-20s %-5s","STT", "Ho Ten", "SBD");
    for (int i=0; i<ds.so_sv; i++) {
        char *k = strupr(ds.dssv[i].khoi);
        if (strcmp(k,c)==0) {
            xuat_thong_tin(ds.dssv[i],cd++);
        }
    }
}
int main() {
    DS *ds=(DS*)malloc((sizeof(DS)));
    danh_sach_sinh_vien(ds);
    xuat_a_c(*ds);
    free(ds);
    return 0;
}
