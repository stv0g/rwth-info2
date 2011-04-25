/********************************************************************************
** Form generated from reading UI file 'ImageController.ui'
**
** Created: Mon Apr 25 21:54:06 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECONTROLLER_H
#define UI_IMAGECONTROLLER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageControllerClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *strokeButton;
    QPushButton *frameButton;
    QPushButton *grayscaleButton;
    QPushButton *quitButton;
    QWidget *widget;
    QFormLayout *formLayout;
    QCheckBox *horCheckbox;
    QCheckBox *verCheckbox;
    QCheckBox *normalizeCheckbox;
    QSlider *edgeSensivity;
    QComboBox *edgeFilter;
    QPushButton *edgeButton;
    QComboBox *viewersCombo;

    void setupUi(QWidget *ImageControllerClass)
    {
        if (ImageControllerClass->objectName().isEmpty())
            ImageControllerClass->setObjectName(QString::fromUtf8("ImageControllerClass"));
        ImageControllerClass->resize(285, 319);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageControllerClass->sizePolicy().hasHeightForWidth());
        ImageControllerClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ImageControllerClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        loadButton = new QPushButton(ImageControllerClass);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        gridLayout->addWidget(loadButton, 1, 0, 1, 1);

        saveButton = new QPushButton(ImageControllerClass);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 3, 0, 1, 1);

        strokeButton = new QPushButton(ImageControllerClass);
        strokeButton->setObjectName(QString::fromUtf8("strokeButton"));

        gridLayout->addWidget(strokeButton, 4, 0, 1, 1);

        frameButton = new QPushButton(ImageControllerClass);
        frameButton->setObjectName(QString::fromUtf8("frameButton"));

        gridLayout->addWidget(frameButton, 5, 0, 1, 1);

        grayscaleButton = new QPushButton(ImageControllerClass);
        grayscaleButton->setObjectName(QString::fromUtf8("grayscaleButton"));

        gridLayout->addWidget(grayscaleButton, 6, 0, 1, 1);

        quitButton = new QPushButton(ImageControllerClass);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout->addWidget(quitButton, 8, 0, 1, 1);

        widget = new QWidget(ImageControllerClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        horCheckbox = new QCheckBox(widget);
        horCheckbox->setObjectName(QString::fromUtf8("horCheckbox"));
        horCheckbox->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, horCheckbox);

        verCheckbox = new QCheckBox(widget);
        verCheckbox->setObjectName(QString::fromUtf8("verCheckbox"));
        verCheckbox->setChecked(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, verCheckbox);

        normalizeCheckbox = new QCheckBox(widget);
        normalizeCheckbox->setObjectName(QString::fromUtf8("normalizeCheckbox"));
        normalizeCheckbox->setChecked(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, normalizeCheckbox);

        edgeSensivity = new QSlider(widget);
        edgeSensivity->setObjectName(QString::fromUtf8("edgeSensivity"));
        edgeSensivity->setMaximum(150);
        edgeSensivity->setPageStep(10);
        edgeSensivity->setValue(70);
        edgeSensivity->setSliderPosition(70);
        edgeSensivity->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, edgeSensivity);

        edgeFilter = new QComboBox(widget);
        edgeFilter->setObjectName(QString::fromUtf8("edgeFilter"));

        formLayout->setWidget(2, QFormLayout::LabelRole, edgeFilter);

        edgeButton = new QPushButton(widget);
        edgeButton->setObjectName(QString::fromUtf8("edgeButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, edgeButton);


        gridLayout->addWidget(widget, 7, 0, 1, 1);

        viewersCombo = new QComboBox(ImageControllerClass);
        viewersCombo->setObjectName(QString::fromUtf8("viewersCombo"));

        gridLayout->addWidget(viewersCombo, 0, 0, 1, 1);


        retranslateUi(ImageControllerClass);
        QObject::connect(quitButton, SIGNAL(clicked()), ImageControllerClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ImageControllerClass);
    } // setupUi

    void retranslateUi(QWidget *ImageControllerClass)
    {
        ImageControllerClass->setWindowTitle(QApplication::translate("ImageControllerClass", "ImageController", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("ImageControllerClass", "Load", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("ImageControllerClass", "Save", 0, QApplication::UnicodeUTF8));
        strokeButton->setText(QApplication::translate("ImageControllerClass", "Stroke", 0, QApplication::UnicodeUTF8));
        frameButton->setText(QApplication::translate("ImageControllerClass", "Frame", 0, QApplication::UnicodeUTF8));
        grayscaleButton->setText(QApplication::translate("ImageControllerClass", "Grayscale", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("ImageControllerClass", "Quit", 0, QApplication::UnicodeUTF8));
        horCheckbox->setText(QApplication::translate("ImageControllerClass", "horizontal", 0, QApplication::UnicodeUTF8));
        verCheckbox->setText(QApplication::translate("ImageControllerClass", "vertical", 0, QApplication::UnicodeUTF8));
        normalizeCheckbox->setText(QApplication::translate("ImageControllerClass", "normalized", 0, QApplication::UnicodeUTF8));
        edgeFilter->clear();
        edgeFilter->insertItems(0, QStringList()
         << QApplication::translate("ImageControllerClass", "Sobel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ImageControllerClass", "Prewitt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ImageControllerClass", "Laplace", 0, QApplication::UnicodeUTF8)
        );
        edgeButton->setText(QApplication::translate("ImageControllerClass", "Detect Edges", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageControllerClass: public Ui_ImageControllerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECONTROLLER_H
