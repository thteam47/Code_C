#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tinhcan(int nam){
    return (nam%10);
}
int tinhchi(int nam){
    int tinh=nam%60;
    if (tinh>12) return (tinh%12);
    else return tinh;
}
char *inchi(int chi){
    if (chi==0) return "Than";
    else if (chi==1) return "Dau";
    else if (chi==2) return "Tuat";
    else if (chi==3) return "Hoi";
    else if (chi==4) return "Ti";
    else if (chi==5) return "Suu";
    else if (chi==6) return "Dan";
    else if (chi==7) return "Mao";
    else if (chi==8) return "Thin";
    else if (chi==9) return "Ty";
    else if (chi==10) return "Ngo";
    else if (chi==11) return "Mui";
}
char *incan (int can){
    if (can==0) return "Canh";
    else if (can==1) return "Tan";
    else if (can==2) return "Nham";
    else if (can==3) return "Quy";
    else if (can==4) return "Giap";
    else if (can==5) return "At";
    else if (can==6) return "Binh";
    else if (can==7) return "Dinh";
    else if (can==8) return "Mau";
    else if (can==9) return "Ki";
}
int main() {
    int n;
    do {
        printf("nhap nam = ");
        scanf("%d",&n);
        if (n<1)
            printf("\nnam duong, nhap lai\n");
        }
    while (n<1);
    printf("\nNam am lich la: %s %s",incan(tinhcan(n)),inchi(tinhchi(n)));
    return 0;
    }
