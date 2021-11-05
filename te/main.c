#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("baitap.txt","wb");
    char str[] = "Bui Quang Ninh";
    fwrite(str, sizeof(str),1,fp);
    fclose(fp);
}
