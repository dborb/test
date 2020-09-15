#include "bufferhandler.h"
int isNumber(char c) {
    return (c >= '0' && c <= '9');
}

void bufferHandler::getPublicBuffer() {
    std::ifstream in;
    in.open("publicbuffer.txt");
    if (in.is_open()) {
        in >> buffer;
        in.close();
        std::ofstream rewrite("publicbuffer.txt");
        rewrite.write("", 0);
        rewrite.flush();
        rewrite.close();
    }
}

void bufferHandler::printBuffer(){
    std::cout << buffer;
}

int bufferHandler::getBuffSum(){
    int sum = 0;
    for (auto it = buffer.begin(); it != buffer.end() && (*it) != '\0'; it++) {
        if (isNumber(*it)) {
            sum += ((*it) - '0');
        }
        else {
            it++;
        }
    }
    return sum;
}

bufferHandler::bufferHandler(){
}

bufferHandler::~bufferHandler() {
}

void bufferHandler::clearBuffer() {
    buffer.clear();
}

