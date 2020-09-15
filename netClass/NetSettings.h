#ifndef NETCLASS_NETSETTINGS_H
#define NETCLASS_NETSETTINGS_H
#include <cygwin/in.h>
#include <unistd.h>

class NetSettings {
public:
    int sock;
    struct sockaddr_in addr;

    void setSockId(){
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }
    NetSettings(){
        addr.sin_family = AF_INET;
        addr.sin_port = htons(9999);
    };
    NetSettings(unsigned long adr){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(9999);
        addr.sin_addr.s_addr = adr;
    };
    virtual void setNetSettings(){};
};


#endif //NETCLASS_NETSETTINGS_H
