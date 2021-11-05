#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        int k=1;
        for (int j=0;j<2*n;j++){
            if (j>=n-i&&j<=n+i) {
                    printf("%d\t",k);
                if (j<n) {
                    k++;
                }
                else k--;
            }
            else printf("\t");

        }
        printf("\n");
    }

    return 0;
}
