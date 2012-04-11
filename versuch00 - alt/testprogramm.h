#ifndef TESTPROGRAMM_H
#define TESTPROGRAMM_H

#include <QtGui/QMainWindow>
#include "ui_testprogramm.h"


class testProgramm : public QMainWindow
{
    Q_OBJECT

public:
    testProgramm(QWidget *parent = 0);
    ~testProgramm();

private:
    Ui::testProgrammClass ui;
};

#endif // TESTPROGRAMM_H
