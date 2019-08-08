#pragma once
#include "udp_socket.hpp"
#include<functional>
#include<cassert>


//通用的 UDP 服务器
//1、读取请求
//2、根据请求计算响应
//3、把响应写回客户端
//其中1、3是固定套路，代码不随场景变化
//2是和业务相关的，所以就把2对应的代码提取成一个回调函数

//typedef void(*Handler)(const std::string& req,std::string* resp);

//C++11引入
typedef std::function<void(const std::string&,std::string*)>  Handler;

class UdpServer
{
  public:
    UdpServer()
    {
      assert(sock_.Socket());
    }

    ~UdpServer()
    {
      sock_.Close();
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
      //1、创建 socket (已经完成)
      //2、绑定端口号
      bool ret = sock_.Bind(ip,port);
      if(!ret)
      {
        return false;
      }
      //3、进入一个死循环
      while(true)
      {
        //处理每个请求
        //a)读取请求
        std::string req;
        std::string peer_ip;
        uint16_t peer_port;
        sock_.RecvFrom(&req,&peer_ip,&peer_port);
        //b)根据请求计算响应
        std::string resp;
        handler(req,&resp);
        //c)把响应返回给客户端
        sock_.SendTo(resp,peer_ip,peer_port);
      }
    }

  private:
    UdpSocket sock_;
};
