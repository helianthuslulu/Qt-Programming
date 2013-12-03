#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>

namespace Ui {
class TimeClient;
}

class TimeClient : public QDialog
{
    Q_OBJECT
    
public:
    explicit TimeClient(QWidget *parent = 0);
    ~TimeClient();

public slots:
    void enableGetBtn();
    void getTime();
    void readTime();
    void showError(QAbstractSocket::SocketError socketError);
    
private:
    Ui::TimeClient *ui;
    QLabel * serverNameLabel;
    QLineEdit * serverNameLineEdit;
    QLabel * portLabel;
    QLineEdit * portLineEdit;
    QDateTimeEdit * dateTimeEdit;
    QLabel * stateLabel;

    QPushButton * getbtn;
    QPushButton * quitbtn;

    uint time2u;
    QTcpSocket * tcpSocket;
};

#endif // TIMECLIENT_H
