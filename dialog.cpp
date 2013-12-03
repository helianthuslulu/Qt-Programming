#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    count = 0;
    timeServer = new TimeServer(this);
    if (!timeServer->listen()) {
        QMessageBox::Critical(this, tr("多线程时间服务器"),
                              tr("无法启动服务器: %1.").arg(timeServer->errorString()));
        close();
        return ;
    }

    setWindowTitle(tr("多线程时间服务器"));

    label1 = new QLabel(tr("服务器端口："));
    label2 = new QLabel;
    label1->setText(tr("服务器端口: %1.").arg(timeServer->serverPort()));

    exitbutton = new QPushButton(tr("退出"));
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
     mainlayout->addWidget(label1);
     mainlayout->addWidget(label2);
     mainlayout->addWidget(exitbutton);

     connect(exitbutton, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}
//用于界面上显示的请求次数
//虽然槽函数slotShow()被多个线程激活，但是调用入口只有主线程的时间循环一个。
//多个线程的激活信号最终会在主线程事件循环中排队调用此槽函数，从而保证了count变量的互斥访问
//因此，槽函数slotShow()是一个天然的临界区
void Dialog::slotShow()
{
    //在标签label2上显示当前的请求次数，并将请求次数计数count加1
    label2->setText(tr("第%1次请求完毕。").arg(++count));
}
