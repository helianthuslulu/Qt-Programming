#include "customer.h"
#include <iostream>
#include <QDebug>

using namespace std;

Customer::Customer()
{
}

void Customer::run()
{
    for (int i = 0; i < DataSize; i++) {
        usedBytes.acquire();
        qDebug() << buffer[i % BufferSize];
        if ((i % 16 == 0) && (i != 0))
            cout << endl;
        freeBytes.release();
    }
    cout << endl;
}
