#include "tcp_socket.hpp"

int main()
{
  TcpSocket sock1;
  sock1.Socket();
  sock1.Bind("0.0.0.0",9090);
  sock1.Listen();
  fork();
  while(true)
  {
    sleep(1);
  }
  return 0;
}
