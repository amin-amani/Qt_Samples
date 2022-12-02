#include "Producer.h"

Producer::Producer(QObject *parent) : QObject(parent)
{

}

void Producer::Start()
{
qDebug()<<"producer completed";
    emit Save();
}
