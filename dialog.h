#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "timeserver.h"

namespace Ui {
class Dialog;
}
//服务器端界面类
class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
public slots:
    //用于界面上显示的请求次数
    void slotShow();

private:
    Ui::Dialog *ui;
        QLabel *label1;//用于显示服务器监听端口
        QLabel *label2;//用于显示请求次数
        QPushButton *exitbutton;//退出按钮
        TimeServer *timeServer;//TCP服务器端timeServer
        int count;//请求次数计数器count
};

#endif // DIALOG_H
