#include "mainwindow.h"

#include <QApplication>
#include <QLocale>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.resize(700, 700);
    w.show();
    return a.exec();
}
