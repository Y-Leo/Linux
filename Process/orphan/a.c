#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t id = fork();
    if(id < 0)
    {
        perror("fork faild");
        return 1;
    }
    else if(0 == id)
    {
        //child
        printf("I am child,pid : %d\n",getpid());
        sleep(10);
    }
    else
    {
        //parent
        printf("I am parent,pid : %d\n",getpid());
        sleep(3);
        exit(0);
        //3秒后直接结束父进程,但是此时孩子进程还在执行，
        //当10秒后孩子进程结束，资源没法回收就变成
    }
}
