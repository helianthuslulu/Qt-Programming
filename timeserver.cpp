#include "timeserver.h"
#include "timethread.h"

TimeServer::TimeServer(QObject * parent)
    : QTcpServer(parent)
{
    dlg = (Dialog *)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    TimeThread * thread = new TimeThread(socketDescriptor, 0);//创建一个工作者线程
    //将线程的结束的消息关联到槽函数slotShow()，用于显示请求计数。
    //在此操作中，应为信号是跨线程的，所以使用了排队连接方式。
    connect(thread, SIGNAL(finished()), dlg, SLOT(slotShow()));
    //将上述创建的线程结束消息函数关联到自身的槽函数deleteLater()用于结束线程
    //在此操作中，因为信号是连接在统一线程中的，所以使用了直连的方式，
    //也可以省略掉，使用Qt的自动连接选择方式
    //另外，由于工作者线程中存在网络事件，因此不能被外界线程销毁，这里使用了延迟销毁函数deleteLater()
    //保证由工作者线程自身销毁
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);

    thread->start();//启动上面创建的线程，执行这一语句之后，工作者线程TimeThread的虚函数run()开始执行
}
