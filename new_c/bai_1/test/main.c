#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    do {
        printf("Nhap so: ");
        scanf("%d",&x);
        if (x<100|| x>1000) printf("Nhap lai");
    } while (x<100|| x>1000);
    if (x%5==0) {
        int n=1;
        float S=0;
        printf("%d chia het cho 5\n",x);
        for (int i=0; i< ((x-5)/5+1)/5+1; i++) {
            for (int j=0; j<5; j++) {
                if (n*5<=x) {
                    printf("%d\t",n*5);
                    S+= (float)1/(n*5);
                }
                n++;
            }
            printf("\n");
        }
        printf("Tong nghich dao: %f",S);

    } else printf("%d khong chia het cho 5",x);


    return 0;
}
