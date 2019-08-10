//通用的 TCP 多进程 服务器
//支持多用户同时访问服务器(非大量用户)
//大量用户同时访问得靠多线程来解决
#pragma once
#include "tcp_socket.hpp"
#include<sys/wait.h>
#include<signal.h>
#include<functional>

#define CHECK_RET(exp) if(!(exp)){return false;}

typedef std::function<void(const std::string&,std::string*)> Handler;


class TcpPrecessServer
{
  public:
    TcpPrecessServer()
    {}

    ~TcpPrecessServer()
    {
      listen_sock_.Close();
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
      signal(SIGCLD,SIG_IGN);
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
        //6、创建子进程，让子进程处理客户端的请求
        //父进程继续调用 Accept
        ProcessConnect(client_sock,peer_ip,peer_port,handler);
      }
    }
  private:
    //Context上下文
    void ProcessConnect(TcpSocket& client_sock,const std::string& ip,
        uint16_t port,Handler handler)
    {
      //1、创建子进程
      pid_t ret = fork();
      //2、父进程直接结束这个函数
      if(ret>0)
      {
        //父进程
        //父进程也需要关闭自己的socket ，否则出现文件描述符泄露
        client_sock.Close();
        //wait(NULL);会阻塞，失去创建多进程的意义
        return;
      }
      //3、子进程循环的做以下事情
        while(true)
        {
          //a)读取请求
          std::string req;
          int r = client_sock.Recv(&req);
          if(r<0)
          {
            continue;
          }
          if(r==0)
          {
            //对端关闭了socket
            printf("[%s:%d]客户端断开了连接\n",ip.c_str(),port);
            break;
          }
          printf("[%s:%d]客户端发送了：%s\n",ip.c_str(),port,req.c_str());
          //b)根据请求计算响应
          std::string resp;
          handler(req,&resp);
          //c)把响应写回客户端
          client_sock.Send(resp);
        }
        //子进程的收尾工作
        //1、关闭 socket
        client_sock.Close();
        //2、结束进程
        exit(0);
    }
  private:
    TcpSocket listen_sock_;
};
