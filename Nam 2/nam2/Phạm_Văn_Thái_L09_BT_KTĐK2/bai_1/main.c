#include <stdio.h>
#include <stdlib.h>
int main() {
    float a, b, c;
    printf("Nhap do dai 3 canh: \n");
    do {
        printf("Nhap a = ");
        scanf("%f", &a);
        printf("\nNhap b = ");
        scanf("%f", &b);
        printf("\nNhap c = ");
        scanf("%f", &c);
        if (a<0||b<0||c<0)
            printf("\na,b,c duong, nhap lai: \n");
    } while (a<0||b<0||c<0);
    if ((a+b)>c && (a+c)>b && (b+c)>a) {
        printf("\nla tam giac");
        if (a==b||a==c||b==c) {
            if (a!=c||b!=c||a!=b) {
                if ((a*a+b*b)==c*c||(a*a+c*c)==b*b||(c*c+b*b)==a*a)
                    printf("\nla tam giac vuong can");
                else
                    printf("\nla tam giac can");
            } else
                printf("\nla tam giac deu");
        } else if ((a*a+b*b)==c*c||(a*a+c*c)==b*b||(c*c+b*b)==a*a)
            printf("\nla tam giac vuong");
        else
            printf("\nla tam giac thuong");
        float p= (a+b+c)/2;
        printf("\nchu vi = %.2f, dien tinh = %.2f. \n",(a+b+c),sqrt(p*(p-a)*(p-b)*(p-c)));
    } else
        printf("\nkhong la tam giac");
    return 0;
}
