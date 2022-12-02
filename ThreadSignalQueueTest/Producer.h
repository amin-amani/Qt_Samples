#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QDebug>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);

signals:
    void Save();
public slots:
    void Start();
};

#endif // PRODUCER_H
