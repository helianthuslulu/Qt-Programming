#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QDialogButtonBox>
#include "mythread.h"

#define MAXSIZE 5

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void start();//启动线程的槽函数
    void stop();//终止线程的槽函数
private:
//    QWidget *widget;
    QPushButton *startbutton;
    QPushButton *stopbutton;
    QPushButton *quitbutton;
    QDialogButtonBox *buttonbox;
    MyThread * workthread[MAXSIZE];//记录所启动的所有线程，是指针数组

    Ui::Dialog *ui;
};

#endif // DIALOG_H
