#include "autothread.h"
#include "qthread.h"
#include "worker.h"
#include "dialog.h"

autothread::autothread(Dialog *d)
{
    QThread *mthread = new QThread();
    Worker *worker = new Worker();
    connect(mthread,&QThread::started,worker,&Worker::DoWork);
    connect(worker,&Worker::Complete,d,&Dialog::complete);
    worker->moveToThread(mthread);
    mthread->start();
}

autothread::~autothread(){
    delete this;
}
