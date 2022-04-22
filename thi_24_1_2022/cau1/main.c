#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//khai báo struct sach
struct Sach {
    char MaSach[10];
    char TenSach[30];
    char NhaXB[30];
    int giaTien;
};
typedef struct Sach sach;

//nhập thông tin 1 sach
void NhapThongTinsach (sach *s) {
    do {
        printf("\nNhap ma sach: ");
        fflush(stdin);
        gets(s->MaSach);
        if (strlen(s->MaSach)>10)
            printf("\nDo dai ma sach nho hon 10 ki tu. Hay Nhap Lai");
    } while (strlen(s->MaSach)>10);
    do {
        printf("Nhap ten sach: ");
        fflush(stdin);
        gets(s->TenSach);
        if (strlen(s->TenSach)>30)
            printf("\nDo dai ten sach nho hon 30 ki tu. Hay Nhap Lai");
    } while (strlen(s->TenSach)>3);

    do {
        printf("Nha xuat ban: ");
        fflush(stdin);
        gets(s->NhaXB);
        if (strlen(s->NhaXB)>30)
            printf("\nDo dai nha xuat ban nho hon 10 ki tu. Hay Nhap Lai");
    } while (strlen(s->NhaXB)>30);
    do {
        printf("Nhap gia sach: ");
        fflush(stdin);
        scanf("%d",&s->giaTien);
        if (s->giaTien<0) {
            printf("\nGia sai. Nhap lai");
        }
    } while (s->giaTien<0);
}
void XuatThongTinSach (sach s) {
    printf("\r\n%-10s\t%-30s\t%-30s\t%-10d\t\n", s.MaSach, s.TenSach, s.NhaXB, s.giaTien);
}
//nhập dữ liệu cho danh sách
void Input (sach *ds, int *n) {
    int check = 1;
    int x = 1;
    do {
        printf("Nhap so luong sach: ");
        fflush(stdin);
        scanf("%d",n);
        if (*n<0) {
            printf("\so luong sai. Nhap lai");
        }
    } while (*n<0);
    for (int i=0; i<*n; i++) {
        printf("\nNhap Thong Tin Sach Thu %d",i+1);
        NhapThongTinsach(&ds[i]);
    }

}

void Output (sach *ds, int n) {
    printf("%-10s%-30s\t%-30s\t%-10s\t", "Ma sach","Ten sach", "Nha xuat ban", "Gia tien\n");
    for (int i=0; i<n; i++) {
        XuatThongTinSach(ds[i]);
    }
}
void search_sach (sach *ds, int n) {
    char mSach[10];
    do {
        printf("\nNhap Ma Sinh Vien Muon Tim Kiem: ");
        fflush(stdin);
        gets(mSach);
        if (strlen(mSach)>10)
            printf("\nDo dai mSach nho hon 10 ki tu. Hay Nhap Lai");
    } while (strlen(mSach)>10);
    int dem=0;
    printf("\nThong Tin sach Co Ma ma sach %s:\n",mSach);
    printf("%-10s%-30s\t%-30s\t%-10s\t", "Ma sach","Ten sach", "Nha xuat ban", "Gia tien\n");
    for (int i=0; i<n; i++) {
        if ((strcmp(mSach,ds[i].MaSach)==0)) {
            XuatThongTinSach(ds[i]);
            dem++;
        }
    }
    if (dem==0)
        printf("\nKhong co");
}
void menu() {
    printf("\n========MENU=======");
    printf("\n1. Nhap Danh Sach Sach");
    printf("\n2. Hien Thi Danh Sach Sach");
    printf("\n3. Tim Kiem Sach Theo Ma sach");
    printf("\n4. Xoa sach theo ma");
    printf("\n5. Ket Thuc");
    printf("\nLua Chon: ");
}
int binarySearch(int *ds, int l, int r, char mSach[10]) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if ((strcmp(mSach,ds[mid].MaSach)==0)) {
            XuatThongTinSach(ds[i]);
            return 0;
        }
    if (strcmp(mSach,ds[mid].MaSach)>0)
      return binarySearch(ds, l, mid - 1, mSach);
     return binarySearch(ds, mid + 1, r, mSach);
  }
   return -1;
}

int main() {
    sach *ds = (sach*)malloc(sizeof(sach));
    int n;
    int lc1;
    do {
        menu();
        fflush(stdin);
        scanf("%d",&lc1);
        switch (lc1) {
        case 1:
            Input(ds, &n);
            break;
        case 2:
            Output(ds, n);
            break;
        case 3:
            search_sach(ds, n);
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (lc1!=5);
    free(ds);
    return 0;
}
