#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MainWindow w2;
    w2.show();
    MainWindow w3;
    w3.show();
    MainWindow w4;
    w4.show();
    return a.exec();
}
