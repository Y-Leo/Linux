#pragma once

#include<vector>
#include<pthread.h>
#include<semaphore.h>

template <typename T>
class BlockingQueue
{
  public:
    BlockingQueue(int max_size)
      :max_size_(max_size)
       ,head_(0)
       ,tail_(0)
       ,size_(0)
       ,queue_(max_size)
  {
    sem_init(&lock_,0,1);
    sem_init(&elem_,0,0);
    sem_init(&blank_,0,max_size);

  }


    ~BlockingQueue()
    {
       sem_destroy(&lock_);
       sem_destroy(&elem_);
       sem_destroy(&blank_);
    }

    void Push(const T&data)
    {
      //每次要插入元素就得先申请一个空格资源
      //如果没有资源说明队列满了
      //满了就不能继续插入并且在Push中阻塞
      sem_wait(&blank_);

      sem_wait(&lock_);
      queue_[tail_]=data;
      ++tail_;
      ++size_;
      sem_post(&lock_);   //信号量这个计数器+1 -1是原子的

      sem_post(&elem_);
    }

    void Pop(T* data)
    {
      //每次出队列，得先申请一个元素资源
      //如果没有，队列为空
      //不能直接出队列，在POP位置阻塞 
      sem_wait(&elem_);//同步

      sem_wait(&lock_);//互斥
      *data=queue_[head_];
      ++head_;
      --size_;
      sem_post(&lock_);

      sem_post(&blank_);
    }

  private:
    std::vector<T> queue_;
    int head_;
    int tail_;
    int size_;
    int max_size_;
    sem_t lock_;//用一个二元(非0即1)信号量表示互斥锁
    sem_t elem_;//可用元素个数
    sem_t blank_;//可用空格个数
};
