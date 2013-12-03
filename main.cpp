/*
  Qt中QSemaphore的使用
*/
#include "producer.h"
#include "customer.h"
#include <iostream>
using namespace std;

int main()
{
    Producer producer;
    Customer customer;
    producer.start();
    customer.start();
    producer.wait();
    customer.wait();

    cout << "Hello World!" << endl;
    return 0;
}
