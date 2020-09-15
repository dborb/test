#ifndef TASK3_MYSTRING_H
#define TASK3_MYSTRING_H

#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>

void writeToBuffer(std::string str);


class myString {
public:
    myString() { }
    ~myString() { buffer.clear(); }
    int getString();
    void sortString();
    void clearString();
    std::string getModifyString();
private:
    std::string buffer;
};


#endif //TASK3_MYSTRING_H
