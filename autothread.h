#ifndef AUTOTHREAD_H
#define AUTOTHREAD_H


#include "dialog.h"

class autothread: public QObject
{
    Q_OBJECT
public:
    QThread *mthread;
    Worker *worker;
    autothread(Dialog *d);
    ~autothread();
};

#endif // AUTOTHREAD_H
