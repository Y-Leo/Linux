#include <iostream>
#include <mutex>
//懒汉模式，线程安全
template <typename T>
class Singleton
{
    //设置volatile关键字，防止被编译器优化
    volatile static T* inst;
    static std::mutex lock;
public:
    static T* GetInstance()
    {
        if(inst == NULL)
        {
            //使用互斥锁，保证多线程情况下也只调用一次new
            lock.lock();
            //双重判断空指针，降低锁冲突的概率，提高性能
            if(inst == NULL)
            {
                inst == new T();
            }
            lock.unlock();
        }
        return inst;
    }
};
