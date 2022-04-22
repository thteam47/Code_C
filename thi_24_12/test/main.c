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

void nhap1ThongTinSV (SV *sv){
    printf("Nhap ho ten: ");
    gets(sv->HoTen);
    printf("Nhap ma sinh vien: ");
    gets(sv->MaSv);
    printf("Nhap tuoi: ");
    scanf("%d",&sv->Tuoi);
    printf("Nhap lop: ");
    fflush(stdin);
    gets(sv->Lop);
}
void xuat1SV(SV sv){
    printf("%-30s%-10s%-5d%-10s",sv.HoTen,sv.MaSv,sv.Tuoi,sv.Lop);
}

int main()
{
    SV sv;
    nhap1ThongTinSV(&sv);
    xuat1SV(sv);
    return 0;
}
