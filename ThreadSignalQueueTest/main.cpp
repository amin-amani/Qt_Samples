#include <QCoreApplication>
#include <QThread>
#include "Worker.h"
#include "Consumer.h"
#include "Producer.h"

    Consumer consumer;
    void CreateThread()
    {
        Producer *producer=new Producer();


        QThread *thr=new QThread();
        QObject::connect(thr, SIGNAL(started()), producer, SLOT(Start()));
        QObject::connect(producer, SIGNAL(Save()), thr, SLOT(quit()));
        QObject::connect(producer, SIGNAL(Save()), producer, SLOT(deleteLater()));
        QObject::connect(thr, SIGNAL(finished()), thr, SLOT(deleteLater()));
        producer->moveToThread(thr);
        thr->start();

        QObject::connect(producer,SIGNAL(Save()),&consumer,SLOT(Save()));
    }
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    for(int i=0;i<1000;i++)
    CreateThread();



//    QObject::connect(thr,SIGNAL(start()),&producer,SLOT(Start()));
//    QObject::connect(thr,SIGNAL(quit()),&producer,SLOT(deleteLater()));
//    QObject::connect(&producer,SIGNAL(Save()),&consumer,SLOT(Save()));
//    producer.Start();

    return a.exec();
}
