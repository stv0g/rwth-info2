/********************************************************************************
** Form generated from reading UI file 'testprogramm.ui'
**
** Created: Sat Apr 9 14:01:22 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPROGRAMM_H
#define UI_TESTPROGRAMM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testProgrammClass
{
public:

    void setupUi(QWidget *testProgrammClass)
    {
        if (testProgrammClass->objectName().isEmpty())
            testProgrammClass->setObjectName(QString::fromUtf8("testProgrammClass"));
        testProgrammClass->resize(400, 300);

        retranslateUi(testProgrammClass);

        QMetaObject::connectSlotsByName(testProgrammClass);
    } // setupUi

    void retranslateUi(QWidget *testProgrammClass)
    {
        testProgrammClass->setWindowTitle(QApplication::translate("testProgrammClass", "testProgramm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testProgrammClass: public Ui_testProgrammClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPROGRAMM_H
