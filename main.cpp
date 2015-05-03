#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QPushButton hello("Helloworld",0);
    QSize size(100,30);
    hello.resize(size);
    return a.exec();
}
