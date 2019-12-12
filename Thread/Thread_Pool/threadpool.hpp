#pragma once
#include<stdio.h>
#include"blockingqueue.hpp"


class Task
{
  public:
    virtual void Run()
    {
      printf("base run\n");
    }

    virtual ~Task()
    {}

};

//线程池对象启动时会创建一组线程
//每个线程都需要执行一定的代码逻辑
class ThreadPool
{
public:
     //n表示创建线程的数量
     ThreadPool(int n)
       :queue_(100)
        ,worker_count_(n)
     {
         //创建出若干个线程
         for(int i=0;i<worker_count_;++i)
         {
           pthread_t tid;
           pthread_create(&tid,NULL,ThreadEntry,this);
           workers_.push_back(tid);
         }
     }
     
     ~ThreadPool()
     {
       for(size_t i=0;i<workers_.size();++i)
       {
         pthread_cancel(workers_[i]);
       }
       for(size_t i=0;i<workers_.size();++i)
       {
         pthread_join(workers_[i],NULL);
       }
     }

     //使用线程池的时候，需要调用者加入一些任务，让线程池去执行
     //任务是一段代码，可以用函数来表示
     void AddTask(Task* task)
     {
        queue_.Push(task);
     }

private:
   Blockingqueue<Task*> queue_;
   int worker_count_;
   std::vector<pthread_t> workers_;

   static void* ThreadEntry(void*arg)
   {
     ThreadPool* pool = (ThreadPool*)arg;
     while(true)
     {
       Task*task=NULL;
       pool->queue_.Pop(&task);
       task->Run();
       delete task;
     }
     return NULL;
   }
};
