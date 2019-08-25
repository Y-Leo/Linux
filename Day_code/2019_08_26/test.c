#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("./myfile",O_CREAT|O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    close(1); //关闭标准输出
    dup2(fd,1);//fd 为新的文件描述符，1为旧的文件描述符

    while(1)
    {
        char buf[1024] = {0};
        ssize_t read_size = read(0,buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read");
            break;
        }
        printf("%s",buf);
        fflush(stdout);
    }
    return 0;
}
