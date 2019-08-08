#include "udp_client.hpp"
using namespace std;
#include<iostream>


int main()
{
   UdpClient client("127.0.0.1",9090);
   while(1)
   {
     std::string str;
     printf("请输入一段内容：");
     fflush(stdout);
     cin>>str;
     int ret = client.SendTo(str);
     if(ret<0)
     {
       perror("sendto");
       continue;
     }
     std::string str_out;
     fflush(stdout);
     client.RecvFrom(&str_out);
     cout<<"server 响应："<<str_out<<endl;
   }


  return 0;
}


