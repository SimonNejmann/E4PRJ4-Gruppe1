#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

class UDPSocket
{
public:
  UDPSocket(int port)
  {
    sock_ = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    bind(sock_, reinterpret_cast<struct sockaddr*>(&server), sizeof(server));

    fromlen_ = sizeof(struct sockaddr_in);
  }

  ~UDPSocket()
  {
    close(sock_);
  }

  int receive(char *buf, int length)
  {
    return recvfrom(sock_, buf, length, 0,
                    reinterpret_cast<struct sockaddr*>(&from_), &fromlen_);
  }

  int send(char *buf, int length)
  {
    return sendto(sock_, buf, length, 0,
                  reinterpret_cast<struct sockaddr*>(&from_), fromlen_);
  }

  int getFD()
  {
    return sock_;
  }
  
private:
  int sock_;
  struct sockaddr_in from_;
  socklen_t fromlen_;
  
};

#endif // UDPSOCKET_HPP_
