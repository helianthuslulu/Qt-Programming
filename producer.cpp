#include "producer.h"

Producer::Producer()
{
}

void Producer::run()
{
    for (int i = 0; i < DataSize; i++) {
        freeBytes.acquire();//此时如果缓冲区被消费者尚未读取的数据填满，对freeBytes.acquire()函数
                                         //的调用就会阻塞，知道消费者读取了这些数据为止。
        buffer[i % BufferSize] = (i % BufferSize);
        usedBytes.release();//把可用资源加1，表示消费者此时可以读取这个刚刚被填写的单元了
    }
}
