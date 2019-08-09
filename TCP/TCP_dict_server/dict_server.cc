#include "tcp_server.hpp"
#include<unordered_map>

int main()
{
  std::unordered_map<std::string,std::string> dict;
  dict.insert(std::make_pair("hello","你好"));
  dict.insert(std::make_pair("world","世界"));
  dict.insert(std::make_pair("hehe","呵呵"));
  dict.insert(std::make_pair("good","好的"));
  dict.insert(std::make_pair("sun","太阳"));
  TcpServer server;
  server.Start("0.0.0.0",9090,[&dict](const std::string&req,std::string* resp)
      {
        auto it = dict.find(req);
        if(it == dict.end())
        {
        *resp = "未找到结果";
        }
        else
        {
          *resp = it->second;
        }
      });
  return 0;
}
