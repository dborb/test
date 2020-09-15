#include "myString.h"

int myString::getString() {
    int c;
    auto it = buffer.begin();
    while ((c = getchar()) != '\n') {
        if (!(c >= '0' && c <= '9') || buffer.size() == 64) {
            while ((c = getchar()) != '\n');
            return -1;
        }
        it = buffer.insert(it, c);
        it++;
    }
    return 1;
}

void myString::sortString() {
    std::sort(buffer.begin(), buffer.end(), [](char c1, char c2){ return c2 - c1;});
}

std::string myString::getModifyString() {
    std::string modificatedString;
    modificatedString.assign(65, '\0');
    int i = 0;
    for (auto it = buffer.begin(); it != buffer.end(); it++, i++) {
        if ((*it - '0') % 2 == 0) {
            modificatedString[i++] = 'K';
            modificatedString[i] = 'B';
        }
        else {
            modificatedString[i] = *it;
        }
    }
    modificatedString[i] = '\0';
    return modificatedString;
}

void myString::clearString() {
    buffer.clear();
}

void writeToBuffer(std::string str) {
    std::ofstream out;
    out.open("publicbuffer.txt");
    if (out.is_open()) {
        out << str;
    }
    out.close();
}


