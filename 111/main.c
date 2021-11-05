#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//khai báo struct sinh viên
struct SinhVien {
    char HoTen[30];
    char MaSv[8];
    char sdt[10];
    float diemTB;
    char diaChi[30];
};
typedef struct SinhVien SV;
//khai báo cấu trúc danh sách liên kết đơn
struct Node {
    SV data;
    struct Node *pNext;
};
typedef struct Node NODE;
//khai báo list
struct List {
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;
//khởi tạo danh dách liên kết đơn
void createlist (LIST *l) {
    l->pHead=l->pTail=NULL;
}
//tạo 1 node trong danh sách liên kết đơn
NODE* createnode (SV x) { //x là dữ liệu đưa vào data
    NODE *p=(NODE*)malloc(sizeof(NODE));
    if (p==NULL) {
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
//thêm node
//thêm cuối
void addtail (LIST *l, NODE *p) {
    if (l->pHead==NULL) { //khi trống
        l->pHead=l->pTail=p;
    } else {
        l->pTail->pNext=p;
        l->pTail=p;
    }
}
void AddHead(LIST *l, NODE *p) {
    if(l->pHead == NULL) { // Tức là danh sách bị rỗng
        l->pHead = l->pTail = p;
    } else {
        p ->pNext = l->pHead; // p quăng dây để tham gia vào danh sách
        l->pHead = p; // p chính thức đã đứng dầu danh sách
    }
}
//nhập thông tin 1 sinh viên
void NhapThongTinSinhVien (SV *sv) {
    do {
        printf("\nMa So Sinh Vien: ");
        fflush(stdin);
        gets(sv->MaSv);
        if (strlen(sv->MaSv)>8)
            printf("\nDo dai MSSV nho hon 8 ki tu. Hay Nhap Lai");
    } while (strlen(sv->MaSv)>8);
    do {
        printf("\nHo Ten Sinh Vien: ");
        fflush(stdin);
        gets(sv->HoTen);
        if (strlen(sv->HoTen)>30)
            printf("\nDo dai ten nho hon 30 ki tu. Hay Nhap Lai");
    } while (strlen(sv->HoTen)>30);
    do {
        printf("\nSo dien thoai: ");
        fflush(stdin);
        gets(sv->sdt);
        if (strlen(sv->sdt)>10)
            printf("\nDo dai so dien thoai nho hon 10 ki tu. Hay Nhap Lai");
    } while (strlen(sv->sdt)>10);
    do {
        printf("\nDiem TB: ");
        fflush(stdin);
        scanf("%f",&sv->diemTB);
        if (sv->diemTB<0||sv->diemTB>10) {
            printf("\nDiem khong hop le. Nhap lai");
        }
    } while (sv->diemTB<0||sv->diemTB>10);
    do {
        printf("\nDia chi: ");
        fflush(stdin);
        gets(sv->diaChi);
        if (strlen(sv->diaChi)>30)
            printf("\nDo dai diaChi nho hon 30 ki tu. Hay Nhap Lai");
    } while (strlen(sv->diaChi)>30);
}
void XuatThongTinSinhVien (SV sv) {
    printf("\r\n%-10s\t%-30s\t%-10s\t%-10.1f\t%-30s\t\n",  sv.MaSv,sv.HoTen, sv.sdt,sv.diemTB, sv.diaChi);
}
//nhập dữ liệu cho danh sách
void Input (LIST *l) {
    createlist(l);
    NODE *p;
    SV x;
    int i=0;
    int check=1;
    do {
        printf("\nNhap Thong Tin Sinh Vien Thu %d",i+1);
        NhapThongTinSinhVien(&x);
        p=createnode(x);
        addtail(l,p);
        //AddHead(l, p);
        memset(&x, 0, sizeof(x));
        p = NULL;
        printf("\nBan muon them nua khong: 1. Co 2. Khong\n");
        scanf("%d",&check);
    } while(check!=2);


}
void Output (LIST l) {
    printf("%-10s\t%-30s\t%-10s\t%-10s\t%-30s\t", "Ma SV", "Ho Ten","SDT", "DiemTB", "Dia chi\n");
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        XuatThongTinSinhVien(p->data);
    }
}
void GiaiPhong (LIST *l) {
    NODE *p; // Khai báo Node p.
    while(l->pHead != NULL) {
        p = l->pHead;
        l->pHead = (*l).pHead ->pNext;
        free(p);
    }
}
void search_name (LIST *l) {
    char name[10];
    printf("\nNhap Ten Sinh Vien Muon Tim Kiem: ");
    fflush(stdin);
    gets(name);
    int dem=0;
    for (NODE *p=l->pHead; p!=NULL; p=p->pNext) {

        if ((strcmp(name,p->data.HoTen)==0)) {
            printf("\nThong Tin Sinh Vien Co Ten %s:\n",name);
            printf("%-10s\t%-30s\t%-10s\t%-10s\t%-30s\t", "Ma SV", "Ho Ten","SDT", "DiemTB", "Dia chi\n");
            XuatThongTinSinhVien(p->data);
            dem++;
        }
    }
    if (dem==0) {
        NODE *p;
        SV sv;
        printf("Khong co sinh vien nay. Hay them thong tin sinh vien %s\n",name);
        strcpy(sv.HoTen,name);
        do {
            printf("Ma So Sinh Vien: ");
            fflush(stdin);
            gets(sv.MaSv);
            if (strlen(sv.MaSv)>8)
                printf("\nDo dai MSSV nho hon 8 ki tu. Hay Nhap Lai");
        } while (strlen(sv.MaSv)>8);

        do {
            printf("\nSo dien thoai: ");
            fflush(stdin);
            gets(sv.sdt);
            if (strlen(sv.sdt)>10)
                printf("\nDo dai so dien thoai nho hon 10 ki tu. Hay Nhap Lai");
        } while (strlen(sv.sdt)>10);
        do {
            printf("Diem TB: ");
            fflush(stdin);
            scanf("%f",&sv.diemTB);
            if (sv.diemTB<0||sv.diemTB>10) {
                printf("\nDiem khong hop le. Nhap lai");
            }
        } while (sv.diemTB<0);
        do {
            printf("Dia chi: ");
            fflush(stdin);
            gets(sv.diaChi);
            if (strlen(sv.diaChi)>30)
                printf("\nDo dai diaChi nho hon 30 ki tu. Hay Nhap Lai");
        } while (strlen(sv.diaChi)>30);
        p=createnode(sv);
        addtail(l,p);
        printf("Them thanh cong\n");
    }

}
void swap(SV *a,SV *b) {
    SV tg;
    tg=*a;
    *a=*b;
    *b=tg;
}
void sort_ht (LIST l) {
    printf("\nSap Xep Sinh Vien Theo Chieu Tang Ho Ten Sinh Vien:\n");
    printf("%-30s%-10s\t%-10s\t%-10s\t", "Ma SV","Ho Ten", "Tuoi", "Lop\n");
    for (NODE *p=l.pHead; p!=l.pTail; p=p->pNext) {
        for (NODE *q=p->pNext; q!=NULL; q=q->pNext) {
            if (strcmp(p->data.HoTen,q->data.HoTen)>0)
                swap(&p->data,&q->data);
        }
    }
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        XuatThongTinSinhVien(p->data);
    }
}
void ds_HB(LIST l) {
    printf("%-10s\t%-30s\t%-10s\t%-10s\t%-30s\t", "Ma SV", "Ho Ten","SDT", "DiemTB", "Dia chi\n");
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        if(p->data.diemTB>7) {
            XuatThongTinSinhVien(p->data);
        }
    }
}

void menu() {
    printf("\n========MENU=======");
    printf("\n1. Nhap Danh Sach Sinh Vien");
    printf("\n2. Sap Xep Danh Sach Sinh Vien Theo Chieu Tang Cua Ma Sinh Vien");

    printf("\n3. Hien thi thong tin hoc bong");

    printf("\n5. Tim Kiem Sinh Vien Theo Ho ten Sinh Vien");
    printf("\n5. Hien Thi Danh Sach Sinh Vien");
    printf("\n6. Ket Thuc");
}
int main() {
    LIST l;
tiep:
    menu();
    printf("\nLua Chon: ");
    int lc;
    scanf("%d",&lc);
    if (lc==6)
        exit(1);
    while (lc!=1&&lc!=6) {
        printf("\nChua Nhap Danh Sach Sinh Vien");
        goto tiep;
    }
nhap:

    Input(&l);
luachon:
    menu();
    printf("\nLua Chon: ");
    int lc1;
    scanf("%d",&lc1);
    switch (lc1) {
    case 1:
        goto nhap;
        break;
    case 2:
        sort_ht(l);
        goto luachon;
        break;
    case 4:
        search_name(&l);
        goto luachon;
        break;
    case 3:
        ds_HB(l);
        goto luachon;
        break;
    case 5:
        Output(l);
        goto luachon;
        break;
    case 6:
        break;
    default:
        break;
    }
    GiaiPhong(&l);
    return 0;
}
