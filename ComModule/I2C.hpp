#ifndef I2C_HPP_
#define I2C_HPP_

#include <linux/i2c-dev.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <fcntl.h>

class I2C
{
public:
  I2C(int adapter_nr)
  {
    char filename[20];
    
    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    fd_ = open(filename, O_RDWR);
    if (fd_ < 0) {
      printf("Error in opening I2C device\n");
      exit(1);
    }
  }
  
  ~I2C()
  {
    close(fd_);
  }

  int send(int addr, char *buf, int len)
  {
    if (ioctl(fd_, I2C_SLAVE, addr) < 0) {
      return -1;
    }
    if (write(fd_, buf, len) != len) {
      return -1;
    }
    return len;
  }
  
  int receive(int addr, char *buf, int len)
  {
    if (read(fd_, buf, len) != len) {
      return -1;
    }
    return len;
  }

private:
  int fd_;
  
};

#endif // I2C_HPP_
