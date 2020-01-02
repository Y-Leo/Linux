#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t ret=fork();
  if(ret<0)
  {
    perror("fork");
    return 1;
  }
  else if(ret==0)
  {
     printf("child: %d  , ret: %d\n",getpid(),ret);
     sleep(10);
  }
  if(ret>0)
  {
    printf("father: %d  , ret: %d\n",getpid(),ret);
    sleep(3);
   // exit(0);
   // 此时，如果父进程提前退出，则子进程变成孤儿进程，最终由1号进程init来领养，回收孤儿进程的资源
  }

}
   
