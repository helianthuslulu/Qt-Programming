#include <QtGui/QApplication>
#include <QTextCodec>
#include "timeclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    TimeClient w;
    w.show();
    
    return a.exec();
}
