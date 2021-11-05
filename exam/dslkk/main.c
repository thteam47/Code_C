#include <stdio.h>
#include <stdlib.h>

struct sinhvien{
    char ten[20];
    char lop[10];
};
typedef struct sinhvien SV;

struct node{
    SV data;
    struct node *pNext;
};
typedef struct node NODE;

void nhap1sv(SV *sv){
    printf("Ho ten: ");
    fflush(stdin);
    gets(sv->ten);
    printf("Lop: ");
    fflush(stdin);
    gets(sv->lop);
}

void xuat1sv (SV sv){
    printf("%-20s%-10s",sv.ten,sv.lop);
}

struct list{
    NODE *pHead, *pTail;
};
typedef struct list LIST;

//khoi tao list
void createList (LIST *l){
    l->pHead=l->pTail=NULL;
}

//khoi tao node

NODE *createNode(SV x){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    if (p==NULL)
        return NULL;
    p->data =x; // gan gia tri
    p->pNext=NULL;
    return p;
}

void addTail (LIST *l,NODE *p){
    if (l->pHead==NULL){
        l->pHead=l->pTail=p;
    }
    else {
        l->pTail->pNext=p;
        l->pTail=p;
    }
}

void addHead (LIST *l,NODE *p){
    if (l->pHead==NULL){
        l->pHead=l->pTail=p;
    }
    else {
        p->pNext=l->pHead;
        l->pHead=p;
    }
}

void createDS(LIST *l){
    createList(l);
    SV x;
    int check = 1;
    int i=1;
    do {
        printf("Nhap thong tin sinh vien thu %d\n",i++);
        nhap1sv(&x);
        NODE *p= createNode(x);
        addTail(l,p);
        printf("\nCo muon nhap nua khong (1/0): ");
        scanf("%d",&check);
    } while(check!=0);

}

void xuatList (LIST l){
    printf("%-20s%-10s","Ho ten","Lop");
    for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
        printf("\n");
        xuat1sv(p->data);
    }
}

void timKiem (LIST l){
    char searchName[20];
    printf("\nNhap ho ten can tim: ");
    fflush(stdin);
    gets(searchName);
    int check=0;
    for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
        if (strcmp(searchName,p->data.ten)==0){
            printf("%-20s%-10s\n","Ho ten","Lop");
            xuat1sv(p->data);
            check++;
        }

    }
    if (check==0) printf("\nKhong co sinh vien %s",searchName);
}

void deleteName (LIST *l){
    char searchName[20];
    printf("\nNhap ho ten can tim: ");
    fflush(stdin);
    gets(searchName);
    int check=0;
    NODE *g = (NODE*)malloc(sizeof(NODE));
    for (NODE *p=l->pHead;p!=NULL;p=p->pNext){
        if (strcmp(searchName,p->data.ten)==0){
            if (p==l->pHead){
                g=p->pNext;
                l->pHead=g;
                break;

            }
            check++;
        }
        g=p;
    }
    if (check==0) printf("\nKhong co sinh vien %s",searchName);
}

int main()
{
    LIST l;
    createDS(&l);
    xuatList(l);
    //timKiem(l);
    deleteName(&l);
     xuatList(l);

    return 0;
}
