#include "testprogramm.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testProgramm w;
    w.show();
    return a.exec();
}
