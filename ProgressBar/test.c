#include<stdio.h>
#include<unistd.h>
//命令行版本的进度条程序


int main()
{
  //#表示进度条
  const char* lable = "|/-\\";
  char buf[1024]={0};
  int i=0;
  for(; i < 100 ; ++i)
  {
    buf[i]='#';
    printf("[%d%%][%c][%s]\r",i,lable[i%4],buf);
    fflush(stdout);//手动刷新
    usleep(500 * 1000);
  }
  return 0;
}
