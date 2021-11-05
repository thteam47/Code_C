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
void Input (LIST *l,int n) {
    createlist(l);
    NODE *p;
    SV x;
    for (int i=0; i<n; i++) {
        printf("\nNhap Thong Tin Sinh Vien Thu %d",i+1);
        NhapThongTinSinhVien(&x);
        p=createnode(x);
        addtail(l,p);
        //AddHead(l, p);
        memset(&x, 0, sizeof(x));
        p = NULL;
    }
}
void Output (LIST l) {
    printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
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
void search_name (LIST l) {
    char name[10];
    printf("\nNhap Ten Sinh Vien Muon Tim Kiem: ");
    fflush(stdin);
    gets(name);
    int dem=0;
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        char *ten=p->data.HoTen;
        char *dao_ten= strrev(ten);
        char *pos=strchr(dao_ten,' ');
        *pos = '\0';
        if ((strcmp(name,strrev(dao_ten))==0)) {
            printf("\nThong Tin Sinh Vien Co Ten %s:\n",name);
            printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
            XuatThongTinSinhVien(p->data);
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
void sort_msv (LIST l) {
    printf("\nSap Xep Sinh Vien Theo Chieu Tang Ma Sinh Vien:\n");
    printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
    for (NODE *p=l.pHead; p!=l.pTail; p=p->pNext) {
        for (NODE *q=p->pNext; q!=NULL; q=q->pNext) {
            if (strcmp(p->data.MaSv,q->data.MaSv)>0)
                swap(&p->data,&q->data);
        }
    }
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        XuatThongTinSinhVien(p->data);
    }
}
void search_msv (LIST l) {
    char msv[4];
    do {
        printf("\nNhap Ma Sinh Vien Muon Tim Kiem: ");
        fflush(stdin);
        gets(msv);
        if (strlen(msv)>3)
            printf("\nDo dai MSSV nho hon 3 ki tu. Hay Nhap Lai");
    } while (strlen(msv)>3);
    int dem=0;
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        if ((strcmp(msv,p->data.MaSv)==0)) {
            printf("\nThong Tin Sinh Vien Co Ma Sinh Vien %s:\n",msv);
            printf("%-30s%-10s\t%-10s\t%-10s\t", "Ho Ten","Ma SV", "Tuoi", "Lop\n");
            XuatThongTinSinhVien(p->data);
            dem++;
        }
    }
    if (dem==0)
        printf("\nKhong co");
}
void menu() {
    printf("\n========MENU=======");
    printf("\n1. Nhap Danh Sach Sinh Vien");
    printf("\n2. Hien Thi Danh Sach Sinh Vien");
    printf("\n3. Tim Kiem Sinh Vien Theo Ten");
    printf("\n4. Sap Xep Danh Sach Sinh Vien Theo Chieu Tang Cua Ma Sinh Vien");
    printf("\n5. Tim Kiem Sinh Vien Theo Ma Sinh Vien");
    printf("\n6. Ket Thuc");
}
int main() {
    LIST l;
    int n;
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
    printf("\nNhap So Sinh Vien: ");
    scanf("%d",&n);
    getchar();
    Input(&l,n);
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
        Output(l);
        goto luachon;
        break;
    case 3:
        search_name(l);
        goto luachon;
        break;
    case 4:
        sort_msv(l);
        goto luachon;
        break;
    case 5:
        search_msv(l);
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
