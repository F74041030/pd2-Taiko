#include "mainwindow.h"
#include "dig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dig abc;
    abc.show();
     QObject::connect(&abc,SIGNAL(showmainwindow()),&w,SLOT(receivelogin()));
     QObject::connect(&abc,SIGNAL(showmainwindow()),&w,SLOT(runagain()));
     QObject::connect(&w,SIGNAL(showdig()),&abc,SLOT(receivelogout()));
     QObject::connect(&abc,SIGNAL(allclose()),&w,SLOT(closed()));

    return a.exec();
}
