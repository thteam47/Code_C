#include <stdio.h>
#include <stdlib.h>

struct Sinhvien{
    char name[20];
    int tuoi;
    float diem;
    char msv[10];
};
typedef struct Sinhvien sinhvien;



void nhap_1_sv(sinhvien *sv){
    printf("\nNhap ten: ");
    fflush(stdin);
    gets(sv->name);
    printf("Ma sinh vien: ");
    fflush(stdin);
    gets(sv->msv);
    printf("Tuoi: ");
    scanf("%d",&sv->tuoi);
    printf("Diem: ");
    scanf("%f",&sv->diem);
}
void nhap_ds (sinhvien *ds,int n){
    for (int i=0;i<n;i++){
        printf("Nhap sv thu %d",i+1);
        nhap_1_sv(&ds[i]);
    }
}
void xuat_1_sv(sinhvien sv){
    printf("\n%-20s%-10s%-10d%-10.1f",sv.name,sv.msv,sv.tuoi,sv.diem);
}
void xuat_ds (sinhvien *ds,int n){
    for (int i=0;i<n;i++){
        xuat_1_sv(ds[i]);
    }
}
int main()
{
    printf("nhap so luong sinh vien: ");
    int n;
    scanf("%d",&n);
    sinhvien *dssv = (sinhvien*)malloc(n*sizeof(sinhvien));
    nhap_ds(dssv,n);
    printf("\n%-20s%-10s%-10s%-10s","Ten","MSV","Tuoi","Diem");\
    xuat_ds(dssv,n);



    return 0;
}
