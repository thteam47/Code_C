#include <stdio.h>
#include <stdlib.h>
int main() {
    int day,month,year;
    int x;
    printf("nhap ngay,thang,nam\n");
    scanf("%d%d%d",&day,&month,&year);
    int check_year (int year) {
        return (((year%4==0)&&(year%100!=0))||(year%400==0));
        }
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            x=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            x=30;
            break;
        case 2: {
            if (check_year(year))
                x=29;
            else
                x=28;
            }
        break;
        }
    if (day==x) {
        if (month==12) {
            day=1;
            month=1;
            year++;
            }
        else {
            day=1;;
            month++;
            }
        }
    else {
        day++;
        }
    printf("\nngay mai: %d/%d/%d",day,month,year);
    return 0;
    }
