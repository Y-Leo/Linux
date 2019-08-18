#include <stdio.h>

int main()
{
    FILE *file;
    //1.dat 为空
    file = fopen("1.dat","w+");

    char a0 = 'D';
    char b0[3] = {'e','m','o'};
    int c0 = 2;
    char a1;
    char b1[3];
    int c1;

    if(file != NULL){
        // 输出
        fputc(a0,file);
        fwrite(b0,sizeof(char),3,file);
        fprintf(file,"%d",c0);
        // 读写指针移动到文件开头
        rewind(file);
        // 读入
        a1 = fgetc(file);
        fread(b1,sizeof(char),3,file);
        fscanf(file,"%d",&c1);
    }
    // 打印结果
    putchar(a1);
    for(int i = 0; i < 3; i++){
        printf(" %c",b1[i]);
    }
    printf(" %d",c1);

    fclose(file);
    return 0;
}
