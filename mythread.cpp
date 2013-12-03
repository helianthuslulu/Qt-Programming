#include "mythread.h"
#include <QDebug>
MyThread::MyThread()
{
}

void MyThread::run()
{
    while (true) {
        for (int n = 0; n < 5; n++)
            qDebug() << n << n << n << n << n;
    }
}
