/*多线程练习
   多线程程序的一般特点：
   1.多线程程序的行为无法预测，当多次执行该程序时，每次的运行结果都不相同；
   2.线程的执行顺序无法保证，它与操作系统的调度策略和线程的优先级等因素有关；
   3.线程的切换可能发生在任何时刻任何地点
   4.线程对代码的敏感度高，代码的细微修改可能产生意想不到的结果。
   因此，综上，必须对线程进行控制
*/
#include <QtGui/QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    
    return a.exec();
}
