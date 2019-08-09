//通用的 TCP 服务器
//不支持单次多客户端访问
//解决办法：多进程，多线程
#pragma once
#include "tcp_socket.hpp"
#include<functional>

#define CHECK_RET(exp) if(!(exp)){return false;}

typedef std::function<void(const std::string&,std::string*)> Handler;


class TcpServer
{
  public:
    TcpServer()
    {}

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
        //5、通过 accept 获取到一个连接
        TcpSocket client_sock;
        std::string ip;
        uint16_t port;
        //这个版本代码，核心问题在于，第一次accept之后就进入了一个循环
        //操作过程中，循环一直没有结束， Accept没有被重复调用
        //后续连接过来的客户端都在内核的连接队列中排队呢，一直得不到处理
        //应该让程序更快速的调用到 Accept
        bool ret = listen_sock_.Accept(&client_sock,&ip,&port);
        if(!ret)
        {
          continue;
        }
        printf("[%s:%d]有客户端连接!\n",ip.c_str(),port);
        //6、和客户端进行具体沟通,一次连接多次沟通
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
            client_sock.Close();
            printf("[%s:%d]对端关闭了连接\n",ip.c_str(),port);
            break;
          }
          printf("[%s:%d]客户端发送了：%s\n",ip.c_str(),port,req.c_str());
          //b)根据请求计算响应
          std::string resp;
          handler(req,&resp);
          //c)把响应写回客户端
          client_sock.Send(resp);
        }
      }
    }
  private:
    TcpSocket listen_sock_;
};
