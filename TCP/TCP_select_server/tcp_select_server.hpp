//通用的 TCP 多线程  select 版本 服务器
#pragma once
#include<vector>
//1、需要尽量高效的插入和删除
//2、需要方便的找到最大元素
#include<set>
#include<sys/select.h>
#include<functional>
#include "tcp_socket.hpp"

//lhs 表示左操作数
//rhs 表示右操作数
bool operator<(const TcpSocket& lhs,const TcpSocket& rhs)
{
   return  lhs.GetFd()<rhs.GetFd();
}

//select 本身用起来不方便，所以封装成类
//提供操作：
//文件描述符的管理器(这个管理器中包含的socket就是要使用select来管理的的socket)
//1、新增一个文件描述符
//2、删除一个文件描述符
//3、等待操作 等待管理的文件描述符就绪（只考虑读就绪的情况）
class Selector
{
  public:
    void Add(const TcpSocket& sock)
    {
      printf("[Selector::Add]%d\n",sock.GetFd());
      socket_set_.insert(sock);
    }

    void Del(const TcpSocket& sock)
    {
      printf("[Selector::Del]%d\n",sock.GetFd());
      socket_set_.erase(sock);
    }

    //wait 返回的时候需要告诉调用者那些文件描述符就绪了
    void Wait(std::vector<TcpSocket>* output)
    {
       //调用 wait 就相当于调用 select 进行等待
       //先获取到最大的文件描述符
      if(socket_set_.empty())
      {
        printf("[Selector::Wait] socket_set_ is empty\n");
        return;
      }
       int max_fd = socket_set_.rbegin()->GetFd();
       fd_set readfds;
       FD_ZERO(&readfds);
       //把 set 中的每个需要关注的文件描述符都设置到 readfds 之中
       for(const auto sock:socket_set_)
       {
         FD_SET(sock.GetFd(),&readfds);
       }
       //select 默认为阻塞等待，有文件描述符返回时，才会进行返回
       //当这个函数返回之后，就应该根据文件描述符的返回情况
       //构造一个输出参数，告诉调用者哪些socket 就绪了
       int nfds = select(max_fd +1,&readfds,NULL,NULL,NULL);
       if(nfds<0)
       {
         perror("select");
         return;
       }
       //已经返回了，返回结果同样也保存在readfds之中
       for(int fd=0;fd<max_fd+1;++fd)
       {
         if(FD_ISSET(fd,&readfds))
         {
           //如果是，说明当前fd 就是读就绪的
           //就把这个结果放到输出结果中
           output->push_back(TcpSocket(fd));
         }
       }
    }

  private:
    //得用一个数据结构把需要的 socet 存起来
    std::set<TcpSocket> socket_set_;
};

//实现一个 select 版本的 TCP server
#define CHECK_RET(exp) if(!(exp)){return false;}

typedef std::function<void(const std::string&,std::string*)> Handler;

class TcpSelectServer
{
  public:
    TcpSelectServer()
    {}

    ~TcpSelectServer()
    {
      listen_sock_.Close();
    }

    //一个服务器程序在处理请求的时候典型的流程就3个步骤
    //1、读取请求并解析
    //2、根据请求计算响应（Handler）
    //3、把响应写回到客户端
    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
      //1、创建一个 socket
      CHECK_RET(listen_sock_.Socket());
      
      //2、绑定端口号
      CHECK_RET(listen_sock_.Bind(ip,port));

      //3、进行监听
      CHECK_RET( listen_sock_.Listen());
      printf("Server Start Ok!\n");

      //4、创建一个 Selector 对象，让这个对象先把 listen_sock_ 管理起来
      //后续进行等待都是靠 selector 对象完成
      Selector selector;
      selector.Add(listen_sock_);

      //5、进入主循环
      while(true)
      {
        //6、不再是直接调用 accept ，而是使用 selector 进行等待
        std::vector<TcpSocket> output;
        selector.Wait(&output);

        //7、遍历返回结果，依次处理每个就虚的 socket
        for(auto tcp_socket : output)
        {
           //8、分两种情况讨论
            if(tcp_socket.GetFd()==listen_sock_.GetFd())
            {
              //a)如果就绪的 socket 是 listen_sock_ 要进行的操作是调用 accept
              TcpSocket client_sock;
              std::string ip;
              uint16_t port;
              tcp_socket.Accept(&client_sock,&ip,&port);
              selector.Add(client_sock);
              printf("[client %s:%d] connected\n",ip.c_str(),port);
            }
            else
            {
              //b)如果就绪的 socket 不是 listen_sock_ 要进行的操作是调用 recv  
              std::string req;
              int n = tcp_socket.Recv(&req);
              if(n<0)
              {
                continue;
              }
              if(n == 0)
              {
                //对端关闭,本端也要关闭， 把这个 socket 从 select 中删掉
                tcp_socket.Close();
                selector.Del(tcp_socket);
                continue;
              }
              printf("[client] %s\n",req.c_str());
              std::string resp;
              //根据请求计算响应
              handler(req,&resp);
              tcp_socket.Send(resp);
            }
        }
      }
    }
  private:
    TcpSocket listen_sock_;
};
