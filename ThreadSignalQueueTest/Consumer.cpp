#include "Consumer.h"

Consumer::Consumer(QObject *parent) : QObject(parent)
{

}

void Consumer::Save()
{

    qDebug()<<"save start... "<< count;
    QThread::msleep(100);
    qDebug()<<"save end "<<count;
    count++;
}
