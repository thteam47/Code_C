#include <stdio.h>
#include <string.h>

//khoi tao node

struct node{
	struct node *pNext;
	int data;
};
typedef struct node NODE;
//tao list

struct LIST{
	NODE *pHead, *pTail;
};


//tao 1 list
void createList (LIST *l){
	l->pHead=l->pTail=NULL;
}
//tao node

NODE *createNode (int x){
	NODE *p=(NODE*)calloc(sizeof(NODE));
	if (p==NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void addTail (LIST *l, NODE *p){
	if (l->pHead==NULL){
		l->pHead=l->pTail=p;
	}
	else {
		l->pTail->pNext=p;
		l->pTail=p;
	}
}

void input (LIST *l){
	createList(l);
	NODE *p;
	int x;
	char isCheck;
	while (true){
		cout <<"Nhap phan tu: ";
		fflush(stdin);
		cin >> x;
		p = createNode(x);
		addTail(l,p);
		p=NULL;
		cout << "Ban co nhap nua khong (Y/N): ";
		cin >> isCheck;
		if (isCheck == 'n' || isCheck == 'N')
		break;
	}
}

void output (LIST l){
	cout <<endl;
	for (NODE *k=l.pHead,k!=l.pTail,k=k->pNext){
		cout << k.data <<"\t";
	}
}
void freeBN(LIST *l){
	NODE *p;
	while (l->pHead!=NULL){
		pHead = l->pHead;
		l->pHead = l->pHead->pNext;
		free(p);
	}
}



int main(int argc, char** argv) {
	LIST l;
	input(&l);
	output(l);
	freeBN(&l);
	return 0;
}
