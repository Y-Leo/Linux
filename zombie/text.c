#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int  ret = fork();
  if(ret<0)
  {
    perror("fork");
    return 1;
  }
  else if(ret==0)
  {
    //子进程
    //如果子进程意外退出，而父进程没有收到子进程的退出码，则导致子进程变成僵尸进程
    //处理办法：
    //1、kill父进程，比较不合理，不推荐
    //2、进程等待，推荐
    //僵尸进程危害：内存泄漏
    //父进程先退出，子进程就变成孤儿进程，被1号进程init领养，资源被1号进程回收
    printf("pid:%d     %d\n",getpid(),ret);
  }
  else
  {
    //父进程
    printf("ppid:%d    %d\n",getppid(),ret);
  }
  sleep(1);

  return 0;
}
