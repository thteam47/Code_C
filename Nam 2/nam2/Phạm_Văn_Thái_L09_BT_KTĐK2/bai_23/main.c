#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TU {
    char ten[20];

} tu;

int main() {
    char s[1000];
    printf("nhap chuoi: ");
    fflush(stdin);
    gets(s);
    int i=0,k=0,h=0;
    tu a[100];
    do {
        if (s[i] != ' ')
            a[k].ten[h++] = s[i];
        else {
            a[k].ten[h]=NULL;
            k++;
            h=0;
        }
    } while (s[++i]!=NULL);
    a[k].ten[h]=NULL;
    printf("\nchuoi co %d tu",k+1);
    int max=0;
    for (int j=0; j<=k; j++) {
        if (strlen(a[j].ten)>max) max= strlen(a[j].ten);
    }
    printf("\ntu dat nhat: ");
    for (int j=0; j<=k; j++) {
        if (strlen(a[j].ten)==max) printf("%s\t",a[j].ten);
    }
    return 0;
}
