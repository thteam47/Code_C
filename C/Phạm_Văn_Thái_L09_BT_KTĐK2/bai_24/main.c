#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_ki_tu (char x) {
    if ((x>=65&&x<=90)||(x>=97&&x<=122))
        return 1;
    else if (x>=48&&x<=57)
        return 2;
    else
        return 0;
}
int main() {
    char s[100];
    printf("nhap xau: ");
    fflush(stdin);
    gets(s);
    int chu=0, so=0,db=0;
    for (int i=0;i<strlen(s);i++){
        if (check_ki_tu(s[i])==1)  chu++;
        else if (check_ki_tu(s[i])==2) so++;
        else db++;
    }
    printf("\nXau co %d chu cai, %d chu so, %d ki tu dac biet", chu, so, db);
    return 0;
}
