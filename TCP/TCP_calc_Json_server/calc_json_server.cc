#include<jsoncpp/json/json.h>
#include"tcp_thread_server.hpp"

//使用 Json 的方式进行序列化和反序列化
//{
//  "num1":10,
//  "num2":20,
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
      int num1 = req_json["num1"].asInt();
      int num2 = req_json["num2"].asInt();
      std::string op = req_json["op"].asString();
//      printf("req:%d, %d, %s\n",num1,num2,op.c_str());
      int ret =0 ;
      if(op == "+")
      {
        ret = num1 + num2;
      }
      else if(op == "-")
      {
      ret = num1 - num2;
      }
      else if(op == "*")
      {
        ret = num1 * num2;
      }
      else if(op == "/")
      {
        ret = num1/num2;
      }
      else
      {
       *resp = "非法输入";
      }
      //3、把结果再序列化
      Json::FastWriter writer;
      Json::Value resp_json;
      resp_json["result"] = ret;
      *resp = writer.write(resp_json);
      });

  return 0;
}
