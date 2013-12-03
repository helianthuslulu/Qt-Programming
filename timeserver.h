#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QtNetwork/QTcpServer>
#include "dialog.h"

class TimeServer : public QTcpServer
{
    Q_OBJECT

public:
    TimeServer(QObject * parent);
protected:
    //该函数会在TCP服务器端有新的连接时被调用，socketDescriptor为所接收新连接的套接字描述符
    void incomingConnection(int socketDescriptor);
private:
    //dlg用于记录创建这个TCP服务器端对象的父类，
    //通过该界面指针，将线程发出的消息关联到界面的槽函数
    Dialog * dlg;
};

#endif // TIMESERVER_H
