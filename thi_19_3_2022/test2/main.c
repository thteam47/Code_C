#include<stdio.h>
#include<ctype.h>
#include<string.h>
int existed(char* filename) {
    int existed=0;
    FILE* f=fopen(filename,"r");
    if(f!=NULL) {
        existed=1;
        fclose(f);
    }
    return existed;
}
int writefile(char* filename) {
    if(existed(filename)==1) {
        printf("The file %s existed. Override it Y/N: ",filename);
        if(toupper(getchar())=='N')return 0;
    }
    char line[201];
    int length=0;
    FILE* f=fopen(filename,"w");
    fflush(stdin);
    do {
        gets(line);
        length=strlen(line);
        if(length>0) {
            fputs(line,f);
            fputs("\n",f);
        }
    } while(length>0);
    fclose(f);
    return 1;
}
int printfile(char* filename) {
    char c;
    if(existed(filename)==0) {
        printf("The file is not existed.\n",filename);
        return 0;
    }
    FILE* f=fopen(filename,"r");
    while((c=fgetc(f))!=EOF)putchar(c);
    fclose(f);
    return 1;
}
int main(int argCount,char* args[]) {
    char filename[81];
    printf("Program for writing then reading a file\n");
    printf("Enter a filename\n");
    gets(filename);
    printf("Write file\n");
    if(writefile(filename)==1) {
        printf("Data in the file %s:\n",filename);
        if(printfile(filename)==0)printf("File error\n");
    } else printf("Writing file failed\n",filename);
    getchar();
    return 0;
}
