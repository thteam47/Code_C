#include <stdio.h>
#include <conio.h>
#include <string.h>
main() {
    char a[100];
    printf("nhap chuoi: ");
    fflush(stdin);
    gets(a);
    int i;
    while (a[i]!=NULL) {
        for (i=0; i<strlen(a); i++) {
            int dem=1;
            for (int j=i;; j++) {
                if (a[j]==a[j+1]) {
                    dem++;
                    i++;
                } else
                    break;
            }
            printf("%d%c",dem,a[i]);
        }
    }
}
