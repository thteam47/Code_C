#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//khoi tao node
template <typename type>
class DSLK
{
public:
    struct node
    {
        struct node *pNext;
        type data;
    };
    typedef struct node NODE;
//tao list

    struct LIST
    {
        NODE *pHead, *pTail;
    };


//tao 1 list
    void createList (LIST *l)
    {
        l->pHead=l->pTail=NULL;
    }
//tao node

    NODE *createNode (type x)
    {
        NODE *p=(NODE*)malloc(sizeof(NODE));
        if (p==NULL)
            return NULL;
        p->data = x;
        p->pNext = NULL;
        return p;
    }
    void addTail (LIST *l, NODE *p)
    {
        if (l->pHead==NULL)
        {
            l->pHead=l->pTail=p;
        }
        else
        {
            l->pTail->pNext=p;
            l->pTail=p;
        }
    }

    void input (LIST *l)
    {
        createList(l);
        NODE *p;
        type x;
        char isCheck;
        while (true)
        {

            cout << "Nhap phan tu: ";
            fflush(stdin);
            cin >> x;
            p = createNode(x);
            addTail(l,p);
            p=NULL;
            fflush(stdin);
            cout << "Ban co nhap nua khong (Y/N): ";
            cin >> isCheck;
            if (isCheck == 'n' || isCheck == 'N')
                break;
        }
    }

    void output (LIST l)
    {

        for (NODE *k=l.pHead; k != NULL; k=k->pNext)
        {
            cout << k->data <<"\t";
        }
    }
    void freeBN(LIST *l)
    {
        NODE *p;
        while (l->pHead!=NULL)
        {
            p = l->pHead;
            l->pHead = l->pHead->pNext;
            free(p);
        }
    }
    void ok()
    {
        LIST l;
        input(&l);
        output(l);
        freeBN(&l);
    }
};
int main(int argc, char** argv)
{
    DSLK <int> dslk;  //test ham
    //DSLK <float> dslk;
    //DSLK <double> dslk;
    //DSLK <char> dslk;
    dslk.ok();
    return 0;
}
