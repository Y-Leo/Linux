#include<jsoncpp/json/json.h>
#include"tcp_thread_server.hpp"

//使用 Json 的方式进行序列化和反序列化
//{
//  "nums":[1,2,3,4,5],
//  "op":"+",
//}
//{
//   "result":30
//}
//如何解析 Json 格式？涉及到编译原理里面的内容
//借助第三方库，完成解析和操作
//jsoncpp
//Json::Value 用来表示一个Json 数据
//Json::Reader 把字符串转换成 Json::Value
//Json::Writer 把 Json::Value 转成字符串

int main()
{
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,[](const std::string& req,std::string* resp)
      {
      //1、将 req 反序列化
      Json::Reader reader;
      Json::Value req_json;
      reader.parse(req,req_json);
      //2、根据反序列化结果进行计算
      Json::Value& nums = req_json["nums"];
      std::string op = req_json["op"].asString();
      int ret =0 ;
      for(size_t i=0;i<nums.size();++i)
      {
      if(op == "+")
      {
        ret +=nums[(int)i].asInt();
      }
      else if(op == "-")
      {
        ret -=nums[(int)i].asInt();
      }
      else if(op == "*")
      {
        ret *=nums[(int)i].asInt();
      }
      else if(op == "/")
      {
        ret /=nums[(int)i].asInt();
      }
      }
      //3、把结果再序列化
      Json::FastWriter writer;
      Json::Value resp_json;
      resp_json["result"] = ret;
      *resp = writer.write(resp_json);
      });

  return 0;
}
