#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 3;
    int tich  = 1;
    for (int i=1; i<=n; i++){
        tich *= i;
    }
    printf("%d! = %d",n,tich);
    return 0;
}
