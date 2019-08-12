//通用的 TCP 多进程 服务器
//支持大量用户同时访问服务器
#pragma once
#include<pthread.h>
#include "tcp_socket.hpp"
#include<functional>

//1、C语言标准库
//2、C++标准库
//3、操作系统提供的库
//4、第三方库
//5、本项目中的文件

#define CHECK_RET(exp) if(!(exp)){return false;}

typedef std::function<void(const std::string&,std::string*)> Handler;


class TcpThreadServer
{
  public:
    TcpThreadServer()
    {}

    ~TcpThreadServer()
    {
      listen_sock_.Close();
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
      //1、创建一个 socket
      CHECK_RET(listen_sock_.Socket());
      
      //2、绑定端口号
      CHECK_RET(listen_sock_.Bind(ip,port));

      //3、进行监听
      CHECK_RET( listen_sock_.Listen());
      printf("Server Start Ok!\n");

      //4、进入主循环
      while(true)
      {
        //5、调用 accept
        TcpSocket client_sock;
        std::string peer_ip;
        uint16_t peer_port;
        bool ret = listen_sock_.Accept(&client_sock,&peer_ip,&peer_port);
        if(!ret)
        {
          continue;
        }
        printf("[%s:%d]有客户端连接!\n",peer_ip.c_str(),peer_port);
        //6、创建线程，处理客户端请求
        
        ProcessConnect(client_sock,peer_ip,peer_port,handler);
      }
    }
  private:

    struct ThreadEntryArg
    {
       TcpSocket client_sock;
       std::string ip;
       uint16_t port;
       Handler handler;
    };
    void ProcessConnect(TcpSocket& client_sock,const std::string& ip,
        uint16_t port,Handler handler)
    {
      //1、创建线程
      pthread_t tid;
      ThreadEntryArg* arg = new ThreadEntryArg;
      arg->client_sock = client_sock;
      arg->ip = ip;
      arg->port = port;
      arg->handler = handler;
      pthread_create(&tid,NULL,ThreadEntry,(void*)arg);
      //2、主线程让函数立刻返回
      pthread_detach(tid);
    }
    static void* ThreadEntry(void* arg)
    {
      //3、新线程循环的做以下事情（客户端请求）
      ThreadEntryArg* argument = (ThreadEntryArg*) arg;
      TcpSocket& client_sock = argument->client_sock;
      std::string& ip = argument->ip;
      uint16_t port = argument->port;
      Handler handler = argument->handler;
      while(true)
      {
        //a、读取客户端请求
        std::string req;
        int ret = client_sock.Recv(&req);
        if(ret<0)
        {
          continue;
        }
          if(ret==0)
          {
            //对端关闭了socket
            client_sock.Close();
            printf("[%s:%d]客户端断开了连接\n",ip.c_str(),port);
            break;
          }
        //b、根据请求计算响应
          printf("[%s:%d]客户端发送了：%s\n",ip.c_str(),port,req.c_str());
          std::string resp;
          handler(req,&resp);
        //c、把响应写回客户端
          client_sock.Send(resp);
      }
      //delete
      delete argument;
      return NULL;
    }

  private:
    TcpSocket listen_sock_;
};
