#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,dem=0, tong=0;
    printf("nhap n = ");
    scanf("%d",&n);
    int t=n;
    do {
        if ((n/10)!=0) {
            dem++;
            tong+=n%10;
            n/=10;
        }
    } while ((n/10)!=0);
    dem++;
    tong+=n;
    printf("\n%d co %d chu so, tong cac chu so la %d",t,dem,tong);
    printf("\n\n%d = ",t);
    for(int i = 2; i <= t; i++) {
        while (t%i==0) {
            printf("%d", i);
            if(t > i) {
                printf(" * ");
            }
            t /= i;
        }
    }

    return 0;
}
