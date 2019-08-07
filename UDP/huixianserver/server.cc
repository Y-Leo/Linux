
//先实现 UDP 版本的服务器
#include<sys/socket.h>
#include<cstring>
#include<cstdio>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
  //1、先创建一个 socket
  //AF_INET 是一个宏，表示表示使用ipv4协议
  //SOCK_DGRAM 表示使用 UDP 协议
  int sock=socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0)
  {
    perror("socket");//socket失败
    return 1;
  }

  //2、把当前socket绑定一个 ip + 端口号
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  //IP 地址也是一个整数，也需要转成网络字节序，只不过 inet_addr 函数自动帮我们转了
  addr.sin_addr.s_addr = inet_addr("0.0.0.0");
  //端口号必须先转成网络字节序
  addr.sin_port = htons(9090);
  int ret = bind(sock,(sockaddr*)&addr,sizeof(addr));
  if(ret<0)
  {
    perror("bind");//bind失败
    return 1;
  }
  printf("server start OK!\n");

  //3、处理服务器收到的请求
  while(true)
  {
    //a)读取客户端请求
    //面向数据报的函数接口
    sockaddr_in peer;
    socklen_t len = sizeof(peer); //输入输出参数
    char buf[1024] = {0};
    ssize_t n = recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)&peer,&len);
    if(n<0)
    {
      perror("recvfrom");
      continue; //考虑到容错，不因为一次请求失败就结束整个程序
    }
    buf[n] = '\0';

    //b)根据请求计算响应
    //[略]  这个程序实现一个“回显服务器 （echo serve）”
    
    //c)把响应写回客户端
    n = sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
    if(n<0)
    {
      perror("sendto");
      continue;
    }
    printf("[%s:%d] buf: %s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf);
  }
  close(sock);
  return 0;
}
