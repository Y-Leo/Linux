#include<iostream>
#include<vector>
#include<unistd.h>
#include<pthread.h>

#include"threadpool.hpp"


//用户自定义任务，自行添加任务
class MyTask: public Task
{
  public:
    MyTask(int id)
      :id_(id)
    {

    }

    ~MyTask()
    {}

    void Run()
    {
      //执行用户自定义的逻辑
      printf("id=%d\n",id_);
    }
  private:
    int id_;
};


int main()
{
  ThreadPool pool(10);
  for(int i=0;i<20;++i)
  {
     pool.AddTask(new MyTask(i));
  }
  while(1)
  {
    sleep(1);
  }
  return 0;
}
