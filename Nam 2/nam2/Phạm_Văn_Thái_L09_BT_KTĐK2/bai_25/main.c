#include <stdio.h>
#include <conio.h>
#include <string.h>
main() {
    char a[100],b,dem=0;
    printf("nhap chuoi: ");
    fflush(stdin);
    gets(a);
    printf("\nnhap ki tu: ");
    scanf("%c",&b);
    for (int i=0; i<strlen(a); i++) {
        if (a[i]==b)
            dem++;
    }
    printf("\nco %d ki tu %c trong chuoi",dem,b); //dem ki tu
    int kt=0;
    for (int i=0; i<=strlen(a)/2; i++) {
        if (a[i]!=a[strlen(a)-i-1]) {
            kt++;
            break;
        }
    }
    if (kt == 0)
        printf("\nchuoi doi xung");  //xet chuoi doi xung
    else {
        printf("\nchuoi khong doi xung");
        printf("\nchuoi dao nguoc: ");
        for (int k=strlen(a)-1; k>=0; k--)
            printf("%c",a[k]);  //dao chuoi
    }
}
