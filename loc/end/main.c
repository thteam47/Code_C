#include <stdio.h>
#include <stdlib.h>

int check_diem(float diem, float diem_xet){
    if (diem<diem_xet) return 0;
    else return 1;
}

int main()
{
    float diem_toan, diem_ly, diem_hoa;
    do {
        printf("Diem Toan: ");
        scanf("%f",&diem_toan);
        if (diem_toan>10||diem_toan<0) printf("\nNhap diem sai. Nhap lai");
    } while (diem_toan>10||diem_toan<0);
    do {
        printf("Diem Ly: ");
        scanf("%f",&diem_ly);
        if (diem_ly>10||diem_ly<0) printf("\nNhap diem sai. Nhap lai");
    } while (diem_ly>10||diem_ly<0);
    do {
        printf("Diem toan: ");
        scanf("%f",&diem_hoa);
        if (diem_hoa>10||diem_hoa<0) printf("\nNhap diem sai. Nhap lai");
    } while (diem_hoa>10||diem_hoa<0);

    float diemTB = (diem_toan*2+diem_hoa+diem_ly)/4;
    if (diemTB>=8&&(diem_hoa>=6.5)&&diem_ly>=6.5&&diem_toan>=6.5) printf("Loai Gioi");
    else if (diemTB>=7&&(diem_hoa>=5)&&diem_ly>=5&&diem_toan>=5) printf("Loai Kha");
    else if (diemTB>=5&&(diem_hoa>=3.5)&&diem_ly>=3.5&&diem_toan>=3.5) printf("Loai TB");
    else printf("Loai Yeu");
    return 0;
}
