#include <stdio.h>
#include <conio.h>
#include <string.h>
void nhap_ham(char *a) {
    printf("nhap ho ten: ");
    gets(a);
    printf("\nHo ten: %s",a);
}
void xoatrang(char *s) {
    int i,j,n=strlen(s);
    for(i=0; i<n; i++) {
        if (s[0]==32) {
            for(j=0; j<n-1; j++) {
                s[j]=s[j+1];
            }
            n--;
            i--;
        }
        if((s[i]==' ')&&(s[i+1]==' ')) {
            for(j=i; j<n; j++) {
                s[j]=s[j+1];
            }
            n--;
            i--;
        }
        if (s[n-1]==32) {
            n--;
            i--;
        }
    }
}
void inhoa(char *s) {
    if (s[0]>='a'&&s[0]<='z')
        s[0]-=32;
    for (int i=1; i<strlen(s); i++) {
        if (s[i]==32)
            if (s[i+1]>='a'&&s[i+1]<='z')
                s[i+1]-=32;
    }
    printf("\nTen chua hoa: %s",s);
}
main() {
    char a[100];
    nhap_ham(a); //nhap
    xoatrang(a); //xoa trang
    inhoa(a); //in hoa
}
