#ifndef NETCLASS_CLIENT_H
#define NETCLASS_CLIENT_H
#include "NetSettings.h"

class Client : public NetSettings{
public:
    Client(unsigned long adr):NetSettings(adr){};
    void setNetSettings(){
        connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    };
    void resetConnection(){
        Client(addr.sin_addr.s_addr);
    };
    void sendMessage(const void *__buf, size_t __len, int __flags){
        send(sock, __buf, __len, __flags);
    };
    void closeSocket(){
        close(sock);
    };
};


#endif //NETCLASS_CLIENT_H
