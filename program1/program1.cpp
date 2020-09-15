#include "myString.h"
#include "bufferhandler.h"
#include <pthread.h>
#include <cygwin/in.h>
#include "../netClass/Client.h"

void *thread1(void *arg){
    auto thread1Mutex = (pthread_mutex_t *)arg;
    myString mString;
    while(true) {
        pthread_mutex_lock(thread1Mutex);
        while(mString.getString() == -1){}
        mString.sortString();
        std::string str = mString.getModifyString();
        writeToBuffer(str);
        mString.clearString();
        pthread_mutex_unlock(thread1Mutex);
    }
}

void *thread2(void *arg){
    bufferHandler bH;
    auto thread2Mutex = (pthread_mutex_t *)arg;
    auto client = Client(htonl(INADDR_LOOPBACK));
    char message[4];
    while(true) {
        pthread_mutex_lock(thread2Mutex);
        bH.getPublicBuffer();
        int bufferSum = bH.getBuffSum();
        bH.printBuffer();
        std::cout << std::endl << bufferSum << std::endl;
        bH.clearBuffer();
        sprintf(message, "%d", bufferSum);
        client.resetConnection();
        client.setNetSettings();
        client.sendMessage(message, sizeof(message), 0);
        client.closeSocket();
        pthread_mutex_unlock(thread2Mutex);
    }
}

int main() {
    pthread_t thr1;
    pthread_t thr2;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    if(pthread_create(&thr1, NULL, thread1, &mutex)) {
        fprintf(stderr, "Error creating thread1\n");
        return 1;
    }
    if(pthread_create(&thr2, NULL, thread2, &mutex)) {
        fprintf(stderr, "Error creating thread2\n");
        return 1;
    }
    if(pthread_join(thr2, NULL)) {
        fprintf(stderr, "Error joining thread2\n");
        return 2;
    }
    if(pthread_join(thr1, NULL)) {
        fprintf(stderr, "Error joining thread2\n");
        return 2;
    }

    return 0;
}