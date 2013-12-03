#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QSemaphore>

const int DataSize = 10000;
const int BufferSize = 8192;
int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);

class Producer : public QThread
{
public:
    Producer();
    void run();
};

#endif // PRODUCER_H
