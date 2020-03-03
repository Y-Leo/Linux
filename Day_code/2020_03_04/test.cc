#include <iostream>
using namespace std;

#include <cstdio>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

class UdpSvr
{
 public:
    UdpSvr()
    {
        Sock_ = -1;
    }
    ~UdpSvr()
    {}

    //创建套接字
    bool CreatSock()
    {
        Sock_ = socket(AF_INET,SOCK_DGRAM,17);
        if(Sock_ < 0)
        {
            perror("socket");
            return false;
        }
        return true;
    }

    //绑地址信息
    bool Bind(string& ip,uint16_t port)
    {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        //主机字节序变网络字节序
        addr.sin_port = htons(port);//两个字节，牵扯到大小端问题
        addr.sin_addr.s_addr = inet_addr(ip.c_str());

        int ret = bind(Sock_,(struct sockaddr*)&addr,sizeof(addr));
        if(ret < 0)
        {
            perror("bind");
            return false;
        }
        return true;
    }

    //发送数据
    bool Send()
    {
        sendto(Sock_,buf.c_str(),buf.size(),0,destaddr);
    }

    //接收数据

private:
    int Sock_;
};

int main()
{

    return 0;
}
