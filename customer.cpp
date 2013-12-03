#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QThread>
#include "producer.h"

class Customer : public QThread
{
public:
    Customer();
    void run();
};

#endif // CUSTOMER_H
