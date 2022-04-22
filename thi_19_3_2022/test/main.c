#include <stdio.h>
#include <stdlib.h>
//cau 1
float dien_tich(int a, int b, int c){
    float dt = 1;
    float p = 0
	if ( (a+b)>c && (b+c)>a && (a+c)>b ) {
		p = (a+b+c)/2.0;
		dt = sqrt(p*(p - a)*(p - b)*(p - c));
		return dt;
	}
	return -1;
}
//cau 2
int doixung(char s[100])
{
   int i,n;
   n= strlen(s);
   for(i=0;i<n/2;i++)
   {
      if(s[i]!=s[n-1-i])
      return 0;
   }
   return 1;
}
//cau 3
float tinh_tong(float e) {
    float s = 0;
    int i = 1;
    while ((1.0/i) >= e){
        if (i%2==0){
            s = s + (float)1/i;
        }else {
            s = s - (float)1/i;
        }
        i++;
    }
    return s;
}
//cau 4
void tao_mang(int *a, int k){
    for (int i=0; i< k; i++){
        a[i] = rand();
    }
    printf("Mang vua nhap la: "\n)
    for (int i=0; i< k; i++){
        printf("%d/t",a[i])
    }
}

int main()
{
    int a,b,c;
    int check = 1;
    char s[100];
    int a[100];
    int k;
    do {
        printf("---------Menu-------\n")
        printf("1. Tinh dien tich tam giac\n");
        printf("2. Kiem tra chuoi doi xung\n");
        printf("3. Tinh ham tong so hoc\n");
        printf("4. Nhap mang\n");
        printf("5. Dung\n");
        printf("Lua chon: ");
        scanf("%d", &check);
        switch (check) {
        case 1:
            float dt = dien_tich(a,b,c);
            break;
        case 2:
            int dx = doixung(s);
            break;
        case 4:
            tao_mang(a,k);
            break;
        case 5:
            break;
        default:
            printf("Khong hop le. Nhap lai")
        }
    } while( check != 5)
    printf("Hello world!\n");
    return 0;
}
