#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    if(c.set_connection()){
        w.show();
        qDebug()<<"database connected";
    }else{
        qDebug()<<"database not connected";
    }

    return a.exec();
}
