#include "timethread.h"

TimeThread::TimeThread(int socketDescriptor, QWidget *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
}

void TimeThread::run()
{
    QTcpSocket tcpSocket;
    //tcpSocket.setSocketDescriptor(socketDescriptor)用来将之前上面创建的QTcpSocket类的对象置以
    //从构造函数中传入的套接字描述符，用来向客户端传回服务器端的当前时间
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());//如果出错，就发该信号报告错误
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    uint time2u = QDataTime::currentDataTime().toTime_t();//如果不出错，就开始获取当前时间，单位是s
    out << time2u;

    tcpSocket.write(block);//将获得的当前时间传回客户端
    tcpSocket.disconnectFromHost();//断开连接
    tcpSocket.waitForDisconnected();//等待返回
}
