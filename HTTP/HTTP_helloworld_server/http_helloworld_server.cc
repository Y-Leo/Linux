#include"tcp_thread_server.hpp"

//HTTP 协议 是基于 TCP 协议基础之上，直接用之前封装好的类

void HttpProcess(const std::string& req,std::string* resp)
{
  //不管用户输入什么请求，直接返回 "hello world!"
  (void) req;
  std::string first_line = "HTTP/1.1 200 OK\n";
  std::string body = "<html><div>hello world!</div></html>";
  std::string header = "Content-Type: text/html\nContent-Length:"
    +std::to_string(body.size())+"\n";
  *resp = first_line + header + "\n" +body;
}

int main()
{
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,HttpProcess);
  return 0;
}
