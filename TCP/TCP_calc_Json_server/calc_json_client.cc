#include<jsoncpp/json/json.h>
#include "tcp_client.hpp"

int main()
{
  //1、创建一个 TCP 客户端
  TcpClient client;
  bool ret = client.Connect("127.0.0.1",9090);
  if(!ret)
  {
    return 1;
  }
  //2、循环从标准输入读入数据
  while(true)
  {
    printf("请输入操作数和一个运算符：");
    fflush(stdout);
    int num1 = 0;
    int num2 = 0;
    char op[10] = {0};
    scanf("%d %d %s",&num1,&num2,op);
    //3、根据用户输入的内容，构造一个 Json 对象
    Json::Value req_json;
    req_json["num1"] = num1;
    req_json["num2"] = num2;
    req_json["op"] = op;
    //4、把 Json 对象序列化成一个字符串
    Json::StyledWriter writer;
    std::string req = writer.write(req_json);
    printf("req:%s\n",req.c_str());
    //5、把字符串发送到服务器
    client.Send(req);
    //6、从服务器读取返回的结果
    std::string resp;
    client.Recv(&resp);
    //7、把服务器返回结果再进行 Json 解析
    Json::Reader reader;
    Json::Value resp_json;
    reader.parse(resp,resp_json);
    printf("server resp:%d\n",resp_json["result"].asInt());
  }
  return 0;
}
