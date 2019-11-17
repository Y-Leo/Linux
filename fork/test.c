#include<stdio.h>
#include<unistd.h>


int main()
{
  pid_t ret = fork();
  if(ret<0)
  {
    perror("fork");
    return 1;
  }
  else if(ret==0)
  {
    printf("child: %d  , ret: %d\n",getpid(),ret);
  }
  else
  {
    printf("father: %d  , ret: %d\n",getpid(),ret);
  }
  sleep(1);

  return 0;
}

