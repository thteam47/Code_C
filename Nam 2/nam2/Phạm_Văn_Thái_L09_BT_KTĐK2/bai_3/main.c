#include <stdio.h>
#include <stdlib.h>
void pt() {
    int a,b,c;
    printf("phuong trinh dang:");
    printf("\nax^2+bx+c=0");
    printf("\nnhap a,b,c theo thu tu\n");
    scanf("%d%d%d",&a,&b,&c);
    if (a==0)
        printf("phuong trinh co nghiem duy nhat x = %8.3f",-c/(float)b);
    else {
        int denta;
        denta= b*b-4*a*c;
        if (denta<0)
            printf("phuong trinh vo nghiem");
        else if (denta==0)
            printf("phuong trinh co nghiem kep x = %8.3f",-b/(float)2*a);
        else {
            printf("phuong trinh co 2 nghiem phan biet x1 = %8.3f, x2 = %8.3f",(-b+sqrt(denta))/(float)2*a,(-b-sqrt(denta))/(float)2*a);
        }
    }
}
void hpt (){
    int a,b,c,d,e,f;
    printf("he phuong trinh dang:");
    printf("\nax+by=c");
    printf("\ndx+ey=f");
    printf("\nnhap a,b,c,d,e,f theo thu tu cua he\n");
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int D, Dx, Dy;
    D= a*e-b*d;
    Dx= c*e-b*f;
    Dy= a*f-c*d;
    if (D==0) {
        if (c==f)
            printf("\nhe vo so nghiem");
        else
            printf("\nhe vo nghiem");
    } else
        printf("\nhe co nghiem duy nhat x = %7.3f, y = %7.3f",(float)Dx/D, (float)Dy/D);
}
void menu() {
    printf("\n\n1. Giai phuong trinh ax^2+bx+c=0");
    printf("\n2. Giai he phuong trinh: ");
    printf("\nax+by=c");
    printf("\ndx+ey=f");
    printf("\n3. Thoat");
}
int main() {
    int lc;
    do {
        menu();
        printf("\nLua chon: ");
        scanf("%d",&lc);
        switch (lc) {
        case 1:
            pt();
            break;
        case 2:
            hpt ();
            break;
        case 3:
            exit(1);
        default: {
            printf("\nLua chon khong hop le");
            break;
        }
        }
    } while(lc!=3);
    return 0;
}
