#include <stdio.h>

int main()
{
    FILE *file;
    //1.dat 为 "Demo1"
    file = fopen("1.dat","r");

    char a;
    char b[3];
    int c;

    if(file){
        a = fgetc(file);
        fread(b,sizeof(char),3,file);
        fscanf(file,"%d",&c);
    }

    putchar(a);
    for(int i = 0; i < 3; i++){
        printf(" %c",b[i]);
    }
    printf(" %d",c);

    fclose(file);
    return 0;
}
