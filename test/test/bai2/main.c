#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ThuThu {
    char HoTen[30];
    char MaTt[4];
    int namSinh;
};
typedef struct ThuThu TT;
//khai báo cấu trúc danh sách liên kết đơn
struct Node {
    TT data;
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
NODE* createnode (TT x) { //x là dữ liệu đưa vào data
    NODE *p=(NODE*)malloc(sizeof(NODE));
    if (p==NULL) {
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
void AddHead(LIST *l, NODE *p) {
    if(l->pHead == NULL) { // Tức là danh sách bị rỗng
        l->pHead = l->pTail = p;
    } else {
        p ->pNext = l->pHead; // p quăng dây để tham gia vào danh sách
        l->pHead = p; // p chính thức đã đứng dầu danh sách
    }
}
void NhapThongTinThuThu(TT *tt) {

    do {
        printf("\nMa So Thu Thu: ");
        fflush(stdin);
        gets(tt->MaTt);
        if (strlen(tt->MaTt)>3)
            printf("\nDo dai Ma so Thu Thu nho hon 3 ki tu. Hay Nhap Lai");
    } while (strlen(tt->MaTt)>3);
    do {
        printf("\nHo Ten Thu Thu: ");
        fflush(stdin);
        gets(tt->HoTen);
        if (strlen(tt->HoTen)>30)
            printf("\nDo dai ten nho hon 30 ki tu. Hay Nhap Lai");
    } while (strlen(tt->HoTen)>30);
    do {
        printf("Nam Sinh: ");
        fflush(stdin);
        scanf("%d",&tt->namSinh);
        if (tt->namSinh<0) {
            printf("\nNam sinh sai. Nhap lai");
        }
    } while (tt->namSinh<0);
}
void XuatThongTinThuThu (int x,TT tt) {
    printf("\n%-10d%-10s%-30s%-10d",x,  tt.MaTt,tt.HoTen, tt.namSinh);
}
//nhập dữ liệu cho danh sách
void Input (LIST *l,int n) {
    createlist(l);
    NODE *p;
    TT x;
    for (int i=0; i<n; i++) {
        printf("\nNhap Thong Tin Thu Thu Thu %d",i+1);
        NhapThongTinThuThu(&x);
        p=createnode(x);
        AddHead(l, p);
        memset(&x, 0, sizeof(x));
        p = NULL;
    }
}
void Output (LIST l) {
    printf("%-10s%-10s%-30s%-10s\n", "STT","Ma SV","Ho Ten", "Nam Sinh");
    int x =1;
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        XuatThongTinThuThu(x,p->data);
        x++;
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

void menu() {
    printf("\n========MENU=======");
    printf("\n1. Nhap Danh Sach Thu Thu");
    printf("\n2. Hien Thi Danh Sach Thu Thu");
    printf("\n3. Them Thu Thu");
    printf("\n4. Ket Thuc");
}
int main() {
    LIST l;
    int n;
tiep:
    menu();
    printf("\nLua Chon: ");
    int lc;
    scanf("%d",&lc);
    if (lc==4)
        exit(1);
    while (lc!=1&&lc!=4) {
        printf("\nChua Nhap Danh Sach Sinh Vien");
        goto tiep;
    }
nhap:
    printf("\nNhap So Thu Thu: ");
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
    case 4:
        break;
    default:
        goto luachon;
        break;
    }
    GiaiPhong(&l);
    return 0;
}
