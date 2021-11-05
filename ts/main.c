#include <stdio.h>
#include <stdlib.h>

void test(int *x) {
    *x *= 2;
}

int main()
{
    int x =5;
    test(&x);
    printf("%d",x);

    return 0;
}
