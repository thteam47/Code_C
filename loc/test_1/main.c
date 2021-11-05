#include <stdio.h>
#include <stdlib.h>
int dequy(int n )
{
    if(n<=0) //thái yêu thảo nhiều lắm thái yêu thảo nhiều lắm thái yêu thảo nhiều lắm thái yêu tarho nhiều lắm thái yêu thảo nhiều lắm thái yêu thảo nhiều lắm thái yêu thảo nhiều lắm thái yêu thảo nhiều lắm thái yêu thảo nhiều lắm thái yêu thảo nhiều lám
    {
    }
}
struct sinhvien
{
    char name[20];
    int age;
};
typedef struct sinhvien sv;

struct Node
{
    struct node *pNext;
    sv data;
};
typedef struct Node node;

struct List
{
    node *pHead,*pTail;
};
typedef struct List list;

void createList (list *l)
{
    l->pHead=l->pTail=NULL;
}

node* createNode (sv x)
{
    node *p = (node*)malloc(sizeof(node));
    if (p==NULL)
        return;
    p->data=x;
    p->pNext=NULL;
}
void addTail (list *l, node *p)
{
    if (l->pHead==NULL)
        l->pHead=l->pTail=p;
    else
    {
        l->pTail->pNext=p;
        l->pTail=p;

    }
}
void nhap(sv *x)
{
    printf("Nhap ten: ");
    fflush(stdin);
    gets(x->name);
    printf("Nhap tuoi: ");
    fflush(stdin);
    scanf("%d",&x->age);
}
void xuat(sv x)
{
    printf("%-15s\t%-10d\n",x.name,x.age);
}
void input (list *l,int n)
{
    createList(l);
    sv x;
    for (int i=0; i<n; i++)
    {
        printf("thang thu %d\n",i+1);
        nhap(&x);
        node *p= createNode(x);
        addTail(l,p);
    }
}
void output(list l)
{
    for (node *p=l.pHead; p!=NULL; p=p->pNext)
    {
        xuat(p->data);
    }
}

void freelist(list *l)
{
    node *p;
    while (l->pHead!=NULL)
    {
        p=l->pHead;
        l->pHead=l->pHead->pNext;
        free(p);
    }
}






int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    list l;
    input(&l,n);
    output(l);
    freelist(&l);


    return 0;
}
