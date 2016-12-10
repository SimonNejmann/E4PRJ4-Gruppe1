#include <sys/select.h>
#include "SocketHandler.hpp"
#include "ComModule.hpp"
#include "constants.hpp"
#include "util.hpp"

SocketHandler::SocketHandler(MsgQueue *comModMq)
  : mq_(5), comModMq_(comModMq), sock_(constants::UDP_SOCKET)
{
}

SocketHandler::~SocketHandler()
{
}

void SocketHandler::run()
{
  pthread_t pt;
  pthread_create(&pt, NULL, SocketHandler::staticStarter, this);
}

void SocketHandler::send(unsigned long id, Message* msg)
{
  mq_.send(id, msg);
}

void* SocketHandler::staticStarter(void* arg)
{
  SocketHandler *s = static_cast<SocketHandler*>(arg);
  s->sockethandlerThread();

  return NULL;
}

void SocketHandler::sockethandlerThread()
{
  unsigned long id;
  fd_set watch_set, result_set;
  int mq_fd = mq_.getReceiveFD();
  int sock_fd = sock_.getFD();

  int fdLimit = util::max(mq_fd, sock_fd) +1;
    
  FD_ZERO(&watch_set);
  FD_SET(mq_fd, &watch_set);
  FD_SET(sock_fd, &watch_set);
    
  while(true) {
    result_set = watch_set;
    select(fdLimit, &result_set, NULL, NULL, NULL);
      
    if (FD_ISSET(mq_fd, &result_set)) {
      // Message in message queue
      Message *msg = mq_.receive(id);
      handleMsg(msg, id);
      delete msg;
        
    } else if(FD_ISSET(sock_fd, &result_set)) {
      // Packet incomming on socket
      ComModule::PacketMessage *pmsg = new ComModule::PacketMessage();
      pmsg->len_ = sock_.receive(pmsg->buf_, constants::BUFFER_SIZE);
      comModMq_->send(ComModule::RECEIVE_UDP_PACKET, pmsg);
    }
  }
}

void SocketHandler::handleMsg(Message *msg, unsigned long id)
{
  switch(id) {
    case SEND_UDP_PACKET:
      {
        SendUDPMessage *sm = static_cast<SendUDPMessage*>(msg);
        sock_.send(sm->buf_, sm->len_);
        break;
      }
    default:
      // Error!
      return;
  }
}
