#pragma once
#include <iostream>
#include <vector>
#include "Common.hpp"
using namespace std;

template <class T>
struct HashNode
{
    HashNode(const T& data = T())
        :pNext_(nullptr)
         ,data_(data)
    {}

    HashNode<T> * pNext_;
    T data_;
};

template<class T, class DF = DFDef<T>>
class HashBucket;

//迭代器:从事实现原理上分类----1、原生态指针  2、对原生态的指针进行封装
template<class T,class DF = DFDef<T>>
struct HBIterator
{
    typedef HashNode<T> Node;
    typedef HBIterator<T> Self;

    HBIterator(Node* pNode = nullptr,HashBucket<T,DF>* ht = nullptr)
        :_pNode(pNode)
         ,_ht(ht)
    {}

    //具有类似指针的操作
    T& operator*()
    {
        return _pNode->data_;
    }

    T* operator->()
    {
        return &(_pNode->data_);
    }

    //能够移动
    //前置++
    Self& operator++()
    {
        Next();
        return *this;
    }

    //后置++
    Self operator++(int)
    {
        Self temp(*this);
        Next();
        return temp;
    }

    //比较
    bool operator!=(Self& s)
    {
        return _pNode != s._pNode;
    }

    bool operator==(Self& s)
    {
        return _pNode == s._pNode;
    }

    void Next()
    {
        if(_pNode->pNext_)
        {
            //_pNode对应的链表后续还有节点
            _pNode = _pNode->pNext_;
        }
        else
        {
            //pNode是当前链表中的最后一个节点
            //找pNode后序第一个非空桶
            //问题：如何知道pNode在哪个桶中？解决：如果知道哈希函数，就能直到pNode的桶号
            //如果能够拿到当前迭代器对应的哈希表，就可以拿到哈希函数
            size_t bucketNo = _ht->HashFunc(_pNode->data_) + 1;
            for(; bucketNo < _ht->table_.capacity(); ++bucketNo)
            {
                if(_ht->table_[bucketNo])
                {
                    //非空桶已找到
                    _pNode = _ht->table_[bucketNo];
                    return;
                }
            }
            //已经是末尾位置
            _pNode = nullptr;
        }
    }
    
    HashNode<T>* _pNode;
    HashBucket<T,DF>* _ht;
};


//迭代器如何与类结合:
//1、为该类定义迭代器
//2、在类中重新给迭代器命名
//3、增加begin/end
template<class T,class DF>
class HashBucket
{
    friend struct HBIterator<T,DF>;
    typedef HashNode<T> Node;
    typedef HBIterator<T,DF> iterator;

public:
    HashBucket(size_t capacity = 10)
        :size_(0)
    {
        table_.resize(/*GetNextPrime(10)*/10);
    }

    bool insertunique(const T& data)
    {
        size_t bucketNo = HashFunc(data);
        Node* pCur = table_[bucketNo];
        while(pCur)
        {
            if(pCur->data_ == data)
                return false;
            pCur = pCur->pNext_;
        }
        pCur = new Node(data);
        pCur->pNext_ = table_[bucketNo];
        table_[bucketNo] = pCur;
        ++size_;
        return true;
    }

    //TODO 可以插入重复的
    bool insertEqual(const T& data);

    bool eraseunique(const T& data)
    {
        size_t bucketNo = HashFunc(data);

        Node* pCur = table_[bucketNo];
        Node* pPre = nullptr;
        while(pCur)
        {
            if(pCur->data_ == data)
            {
                if(pPre == nullptr)
                    table_[bucketNo] = pCur->pNext_;
                else
                    pPre->pNext_ = pCur->pNext_;

                delete pCur;
                --size_;
                return true;
            }
            else
                pCur = pCur->pNext_;
        }
        return false;
    }

//TODO 删除重复的
bool eraseEqual(const T& data);

Node* find(const T& data)const
{
    size_t bucketNo = HashFunc(data);

    Node* pCur = table_[bucketNo];
    while(pCur)
    {
        if(pCur->data_ == data)
            return pCur;
        pCur = pCur->pNext_;
    }
    return nullptr;
}

size_t size()const
{
    return size_;
}

bool empty()const
{
    return 0 == size_;
}

iterator begin()
{
    //找第一个非空桶
    for(size_t bucket = 0; bucket < table_.capacity(); ++bucket)
    {
        if(table_[bucket])
            return iterator(table_[bucket],this);
    }

    return end();
}

iterator end()
{
    return iterator(nullptr,this);
}

//测试
void PrintHashBucket()
{
    for(size_t bucketNo = 0;bucketNo < table_.capacity();++bucketNo)
    {
        Node* pCur = table_[bucketNo];
        std::cout << "table_[" << bucketNo << "]:";
        while(pCur)
        {
            std::cout << pCur->data_ << "---->";
            pCur = pCur->pNext_;
        }
        std::cout << "NULL" << std::endl;
    }
}

private:
    //存储元素的个数等于桶的个数
    //每个桶中都有一个元素，继续插入一定会发生冲突
void CheckCapacity()
{
    if(size_ == table_.capacity())
    {

    }
}

size_t HashFunc(const T& data)const
{
    return DF()(data) % table_.capacity();
}

    std::vector<Node*> table_;
    size_t size_;
};

void TestHashBucket()
{
    HashBucket<int> ht;
    int arr[] = {1,4,7,9,6,5};
    for(auto e : arr)
        ht.insertunique(e);

    std::cout << ht.size() << std::endl;
    ht.PrintHashBucket();

    ht.insertunique(44);
    ht.insertunique(54);

    /*
    auto it = ht.begin();
    while(it != ht.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
*/

    ht.PrintHashBucket();

    ht.eraseunique(44);
    if(ht.find(44))
        std::cout << "44 is in HashBucket" << std::endl;
    else
        std::cout << "44 is not in HashBucket" << std::endl;

    std::cout << ht.size() << std::endl;
    ht.PrintHashBucket();
}

