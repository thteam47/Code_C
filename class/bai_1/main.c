#include <stdio.h>
#include <stdlib.h>
typedef struct SinhVien
{
    char HoTen[30] ;
    int Tuoi;
    char Lop[10];
} SV;
void Nhapdssv(SV *sv, int n)
{

    for(int i=0; i<n; i++)
    {
        printf("\nTen sinh vien thu %d :",i);
        fflush(stdin);
        gets(sv[i].HoTen);
        printf("\nNhap tuoi sinh vien thu %d :",i);
        scanf("%d",&sv[i].Tuoi);
        printf("\nNhap Lop sinh vien thu %d :",i);
        fflush(stdin);
        gets(sv[i].Lop);
    }
}
void Hienthidssv(SV *sv,int n)
{
    printf("Danh sach sinh vien:\n");
    printf(" Ho ten \t Tuoi \t\t Lop\n");
    for(int i=0; i<n; i++)
    {
        printf("%s\t\t %d\t\t %s\n",sv[i].HoTen,sv[i].Tuoi,sv[i].Lop);
    }
}
    void timkiemsv(SV *sv,int n)
    {   int dem=0;
        char sosanh[30];
        printf("Nhap ten sinh vien can tim: ");
        fflush(stdin);
        gets(sosanh);
        for(int i=0; i<n; i++)
        {
            if(strcmp(sosanh,sv[i].HoTen)==0)
            {
                printf("Tim thay sinh vien \n");
                printf("%s\t\t %d\t\t %s\n",sv[i].HoTen,sv[i].Tuoi,sv[i].Lop);
                dem++;
            }
        }if (dem==0){printf(" Khong tim thay sinh vien");}

    }

int main()
{
    int n;
    printf("So sinh vien can nhap:");
    scanf("%d",&n);
    SV *sv = (SV*)malloc(sizeof(SV)*n);
    printf()
    switch(a)
    Nhapdssv(sv,n);
    Hienthidssv(sv,n);
    timkiemsv(sv,n);
    return 0;
}
