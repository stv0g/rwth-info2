#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include "ImageViewer.h"

#include <QtGui/QWidget>
#include <QtGui/QMessageBox>
#include <QtGui/QCloseEvent>

#include <vector>

#include "ui_ImageController.h"

class ImageController: public QWidget
{
Q_OBJECT

public:
	ImageController();

public slots:
	void loadImage();
	void saveImage();
	void showImage(ImageViewer * newImage);

	void strokeImage();
	void frameImage();
	void grayscaleImage();
	void detectEdges();

	void viewerClosed(QObject * obj);
	void viewerSelected(int index);

private:
	void closeEvent(QCloseEvent *e);

	Ui::ImageControllerClass ui;
	std::vector<ImageViewer*> *viewers;
	ImageViewer *current; /* holds last focused viewer */
};

#endif // IMAGECONTROLLER_H
