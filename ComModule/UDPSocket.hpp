#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include <string.h>
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
    memset(&from_, 0, fromlen_);
  }

  ~UDPSocket()
  {
    close(sock_);
  }

  int receive(char *buf, int length)
  {
    // from_ is set to a "real" address on receive
    return recvfrom(sock_, buf, length, 0,
                    reinterpret_cast<struct sockaddr*>(&from_), &fromlen_);
  }

  int send(char *buf, int length)
  {
    // Only send if from_ contains a "real" address
    if (from_.sin_port != 0) {
      return sendto(sock_, buf, length, 0,
                    reinterpret_cast<struct sockaddr*>(&from_), fromlen_);
    } else {
      return 0;
    }
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
