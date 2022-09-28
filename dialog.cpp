#include "dialog.h"
#include "autothread.h"
#include "ui_dialog.h"

//#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked" << QThread::currentThread();
    autothread *AT = new autothread(this);
}

void Dialog::complete()
{
    Worker *worker = qobject_cast<Worker*>(sender());
    qDebug() << "Complete" << worker;
    worker->deleteLater();
    worker->thread()->exit();
}

