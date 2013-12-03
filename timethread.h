#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QtNetwork/QTcpSocket>
#include <QThread>

//实现TCP套接字
class TimeThread : public QThread
{
    Q_OBJECT

public:
    TimeThread(int socketDescriptor, QWidget *parent = 0);
    void run();//工作线程TimeThread的实质所在
signals:
    void error(QTcpSocket::SocketError socketError);//出错信号
private:
    int socketDescriptor;//套接字描述符
};

#endif // TIMETHREAD_H
