#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct sach {
    int ma_sach;
    char ten_sach[101];
    char tac_gia[101];
    int ma_nxb;
};
typedef struct sach SACH;
struct node {
    SACH data;
    struct node *pNext;
};
typedef struct node NODE;
struct list {
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void tao_list (LIST *l) {
    l->pHead=l->pTail=NULL;
}
//tạo 1 node
NODE *getnode (SACH x) {
    NODE *p= (NODE*)malloc(sizeof(NODE));
    if (p==NULL) {
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
//them cuoi
void add_tail (LIST *l, NODE *p) {
    if (l->pHead==NULL) {
        l->pHead=l->pTail=p;
    } else {
        l->pTail->pNext=p;
        l->pTail=p;
    }
}
void nhap_thong_tin (SACH *s) {
    printf("\nMa Sanh: ");
    scanf("%d",&s->ma_sach);
    do {
        printf("Ten Sach: ");
        fflush(stdin);
        gets (s->ten_sach);
        if (strlen(s->ten_sach)>100)
            printf("\nTen sach toi da 100 ki tu. Nhap lai\n");
    } while (strlen(s->ten_sach)>100);
    do {
        printf("Tac Gia: ");
        fflush(stdin);
        gets (s->tac_gia);
        if (strlen(s->tac_gia)>100)
            printf("\nTen tac gia toi da 100 ki tu. Nhap lai\n");
    } while (strlen(s->tac_gia)>100);
    printf("Ma So Nha Xuat Ban: ");
    fflush(stdin);
    scanf("%d",&s->ma_nxb);
}
void xuat_thong_tin (SACH s) {
    printf("\nMa Sach: %d",s.ma_sach);
    printf("\nTen Sach: %s",s.ten_sach);
    printf("\nTac Gia: %s",s.tac_gia);
    printf("\nMa So Nha Xuat Ban: %d",s.ma_nxb);
}
void input (LIST *l) {
    tao_list(l);
    SACH x;
    NODE *p;
    int check =1;
    int i=1;
    do {
        printf("\nNhap Thong Tin Sach Thu %d",i++);
        nhap_thong_tin(&x);
        p=getnode(x);
        add_tail(l,p);
        printf("\nCo muon nhap nua khong: (1/0): ");
        fflush(stdin);
        scanf("%d",&check);
    }while(check!=0);
}
void output (LIST l) {
    int i=1;
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        printf("\n===THONG TIN SACH THU %d",i++);
        xuat_thong_tin(p->data);
    }
}
void giai_phong (LIST *l) {
    NODE *p;
    while (l->pHead!=NULL) {
        p=l->pHead;
        l->pHead=l->pHead->pNext;
        free(p);
    }
}
void hien_thi_sach_nxb (LIST l) {
    NODE *g = (NODE*)malloc(sizeof(NODE));
    int i;
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        i=1;
        printf("\n=== THONG TIN SACH CUA NHA XUAT BAN %d ===",p->data.ma_nxb);
        printf("\nTHONG TIN SACH THU %d",i);
        xuat_thong_tin(p->data);
        if (p!=l.pTail)
            for (NODE *q=p->pNext; q!=NULL; q=q->pNext) {
                if (p->data.ma_nxb==q->data.ma_nxb) {
                    printf("\nTHONG TIN SACH THU %d",++i);
                    xuat_thong_tin(q->data);
                    if (q->pNext==NULL) {
                        g->pNext=NULL;
                        free(q);
                        return;
                    } else {
                        g->pNext=q->pNext;
                        free(q);
                        q=g;
                    }
                }
                g=q;
            }
    }
}
void search_ms (LIST l) {
    int ms;
    printf("\nNhap ma sach can tim kiem: ");
    fflush(stdin);
    scanf("%d",&ms);
    int dem=0;
    printf("\nThong tin sach co ma %d:\n",ms);
    for (NODE *p=l.pHead; p!=NULL; p=p->pNext) {
        if (ms==p->data.ma_sach) {
            dem++;
            printf("\n= THONG TIN SACH THU %d =\n",dem);
            xuat_thong_tin(p->data);
        }
    }
    if (dem==0)
        printf("Khong co\n");
}
void swap (SACH *a, SACH *b) {
    SACH tg=*a;
    *a=*b;
    *b=tg;
}
void sort_ms (LIST l) {
    for (NODE *p=l.pHead; p!=l.pTail; p=p->pNext) {
        for (NODE *q=p->pNext; q!=NULL; q=q->pNext) {
            if (p->data.ma_sach>q->data.ma_sach)
                swap(&p->data,&q->data);
        }
    }
    printf("\nDANH SACH SAU KHI SAP XEP\n");
    output(l);
}
void menu() {
    printf("\n1. TAO DANH MUC SACH");
    printf("\n2. HIEN THI DANH SACH SACH");
    printf("\n3. HIEN THI SACH CUA CUNG MOT NHA XUAT BAN");
    printf("\n4. TIM KIEM THONG TIN THEO MA SACH");
    printf("\n5. SAP XEP SACH THEO CHIEU TANG CUA MA SACH");
    printf("\n6. THOAT CHUONG TRINH");
    printf("\nLUA CHON: ");
}
int main() {
    LIST l;
    int lc,lc1;
    do {
        system("cls");
        menu();
        scanf("%d",&lc);
        if (lc==6)
            exit(1);
        else if (lc==1) {
            input(&l);
            break;
        } else {
            printf("\nLua chon khong hop le");
    getch();
        }
    } while (lc!=6||lc!=1);
tiep:
    menu();
    scanf("%d",&lc1);
    switch (lc1) {
    case 1:
        input(&l);
        goto tiep;
        break;
    case 2:
        output(l);
        goto tiep;
        break;
    case 3:
        hien_thi_sach_nxb(l);
        goto tiep;
        break;
    case 4:
        search_ms(l);
        goto tiep;
        break;
    case 5:
        sort_ms(l);
        goto tiep;
        break;
    case 6:
        giai_phong(&l);
        exit(1);
    default:
        goto tiep;
        break;
    }
    //hien_thi_sach_nxb(l);
    //search_ms(l);
    //sort_ms(l);
    giai_phong(&l);
    return 0;
}
