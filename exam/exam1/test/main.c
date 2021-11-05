
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char HoTen[40];
	int Tuoi;
	char Lop[30];
}SV;

typedef struct {
	SV data;
	struct NODE *pNext;
}NODE;

typedef struct {
	NODE *pHead;
	NODE *pTail;
}LIST;

NODE* CreatNODE(SV sv){
	NODE *p = (NODE*)malloc(sizeof(NODE));
	if(p==NULL)
		return;
	p->data=sv;
	p->pNext=NULL;
	return p;
}

void CreateLIST(LIST *l){
	l->pHead = NULL;
	l->pTail = NULL;
}

void NhapTTSV(SV *sv){
	printf("\nNhap ten sinh vien : ");
	fflush(stdin);
	gets(sv->HoTen);
	printf("\nNhap tuoi : ");
	scanf("%d",&sv->Tuoi);
	printf("\nNhap lop");
	fflush(stdin);
	gets(sv->Lop);
}

void AddHead(LIST *l , NODE *p){
	if(l->pHead==NULL)
		l->pHead=l->pTail=p;
	p->pNext=l->pHead;
	l->pHead=p;
}

void AddTail(LIST *l , NODE *p){
	if(l->pTail==NULL)
		l->pHead=l->pTail=p;
	l->pTail->pNext=p;
	l->pTail=p;
}

void NhapDSSV(LIST *l){
	char k;
	SV sv;
	do{
		printf("\n Nhap ki tu bat ki de nhap thong tin sinh vien ");
		printf("\n Nhan 0 de ket thuc ");
		k=getch();
		if(k=='0')
			break;
		NhapTTSV(&sv);
		NODE *p = CreatNODE(sv);
		AddTail(l,p);
	}while(1);
}


void HienTDSSV(LIST l){
	printf("\n%-40s %-10s %-30s","HO TEN"," TUOI","LOP");
	for(NODE *p =l.pHead;p!=NULL;p=p->pNext)
	printf("\n%-40s %-10d %-30s",p->data.HoTen,p->data.Tuoi,p->data.Lop);
}
void timKiem(LIST l){
    char ten[10];
    printf("\nNhap ten can tim: ");
    fflush(stdin);
    gets(ten);

    for(NODE *p =l.pHead;p!=NULL;p=p->pNext){

        if (strcmp(ten, p->data.HoTen)==0) {
            printf("\n%-40s %-10d %-30s",p->data.HoTen,p->data.Tuoi,p->data.Lop);break;
        }

    }
}

main(){
    int lc;
	LIST l;
	CreateLIST(&l);
	SV sv;
	do{
		printf("\nChon 1 : De nhap danh sach sinh vien ");
		printf("\nChon 2 : De hien thi danh sach sinh vien ");
		printf("\nChon 3 : De tim kiem theo ten ");
		printf("\nChon 4 : De ket thuc \n");
		scanf("%d",&lc);
		switch(lc){
			case 1:
				NhapDSSV(&l);
				break;
			case 2:
				HienTDSSV(l);
				break;
			case 3:
			    timKiem(l);
				break;
			case 4:
				break;
            default:
                break;
		}
	}while(lc!=4);
}
