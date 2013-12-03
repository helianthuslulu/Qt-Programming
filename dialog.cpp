#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QGridLayout * gridlayout = new QGridLayout(this);
    startbutton = new QPushButton("start", this);
    stopbutton = new QPushButton("stop", this);
    quitbutton = new QPushButton("quit", this);
    gridlayout->addWidget(startbutton, 0, 0, 1, 1);
    gridlayout->addWidget(stopbutton, 0, 1, 1, 1);
    gridlayout->addWidget(quitbutton, 0, 2, 1, 1);
    setLayout(gridlayout);

    connect(startbutton, SIGNAL(clicked()), this, SLOT(start()));
    connect(stopbutton, SIGNAL(clicked()), this, SLOT(stop()));
    connect(quitbutton, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::start()
{
    for (int i = 0; i < MAXSIZE; i++)
        workthread[i] = new MyThread;//创建指定数目的线程

    for (int i = 0; i < MAXSIZE; i++)
        workthread[i]->start();//调用基类QThread类的start()函数,这个函数将会启动run(),
                                              //从而使得线程开始真正运行

    stopbutton->setEnabled(true);
    startbutton->setEnabled(false);
}

void Dialog::stop()
{
    for (int i = 0; i < MAXSIZE; i++) {
        workthread[i]->terminate();//调用QThread基类的terminate()函数，依次终止保存在workthread[]
                                                       //数组中的MyThread类实例，但是terminate()函数不会立即终止这个
                                                       //线程，该线程何时终止取决于操作系统的调度策略；因此，程序接着
                                                       //调用了QThread基类的wait()函数，它使得线程阻塞等待知道退出或者
                                                       //超时。
        workthread[i]->wait();
    }
    startbutton->setEnabled(true);
    stopbutton->setEnabled(false);
}

