#ifndef TASK3_BUFFERHANDLER_H
#define TASK3_BUFFERHANDLER_H

#include <iostream>
#include <fstream>
#include <string>

class bufferHandler {
private:
    std::string buffer;
public:
    void getPublicBuffer();
    void printBuffer();
    int getBuffSum();
    void clearBuffer();
    bufferHandler();
    ~bufferHandler();
};

#endif //TASK3_BUFFERHANDLER_H
