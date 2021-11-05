#include <stdio.h>
#include <stdlib.h>

//nhập dãy số nguyên bằng dslk đơn

struct node{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct list {
    NODE *pHead, *pTail;
};
typedef struct list LIST;

void createList(LIST *l){
    l->pHead=l->pTail=NULL;
}

NODE *createNode (int x){ //x la du lieu can cgo vaof
    NODE *p = (NODE*)malloc(sizeof(NODE));
    if (p==NULL){
        return NULL;
    }
    p->data=x;
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

void addHead (LIST *l, NODE *p){
    if (l->pHead==NULL){
        l->pHead=l->pTail=p;
    }
    else {

        p->pNext=l->pHead;
        l->pHead=p;
    }
}

void input (LIST *l){
    int x;
    createList(l);
    int check=1;
    do {
        printf("Nhap phan tu: ");
        scanf("%d",&x);
        NODE *p = createNode(x);
        addTail(l,p);
        printf("Co nhap nua khong (1/0): ");
        scanf("%d",&check);

    } while(check!=0);
}
void xuat (LIST l){
    for (NODE *p =l.pHead;p!=NULL;p=p->pNext){
        printf("%d\t",p->data);
    }
}





int main()
{
    LIST l;
    input(&l);
    xuat(l);
    return 0;
}
