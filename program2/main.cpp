#include <iostream>
#include <sys/socket.h>
#include <cygwin/in.h>
#include "../netClass/Server.h"

int main() {
    int sock;
    std::string str;
    char buf[5];
    auto server = Server(htonl(INADDR_ANY));
    server.setNetSettings();
    while(true){
        sock = server.getMessage(buf, 5, 0);
        if(buf[2] != '\0' && atoi(buf) % 32 == 0){
            std::cout << "Data received" << std::endl;
        }
        else{
            std::cout << "Error while receiving data" << std::endl;
        }
        server.closeSock(sock);
    }
}
