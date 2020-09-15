#ifndef NETCLASS_SERVER_H
#define NETCLASS_SERVER_H
#include "NetSettings.h"

class Server: public NetSettings {
public:
    Server(unsigned long adr):NetSettings(adr){};
    void setNetSettings(){
        bind(sock, (struct sockaddr *)&addr, sizeof(addr));
        listen(sock, 1);
    };
    ssize_t getMessage(void *__buff, size_t __len, int __falgs){
        return recv( accept(sock, NULL, NULL), __buff, __len, __falgs);
    };
    void closeSock(ssize_t sck){
        close(sck);
    };
};


#endif //NETCLASS_SERVER_H
