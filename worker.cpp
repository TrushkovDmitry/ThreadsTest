#include "worker.h"
#include "qthread.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created" << this;
}

void Worker::DoWork()
{
    qDebug() << "DoWork" << QThread::currentThread();
    for(int i = 0; i < 10; i++)
    {
        qInfo() << "Work" << QString().number(i) << this;
        QThread::sleep(1);
    }

    emit Complete();
}
