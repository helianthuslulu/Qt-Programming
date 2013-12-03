#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
//#include <stdio.h>
#include <iostream>

using namespace std;

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
protected:
    void run();
};

#endif // MYTHREAD_H
