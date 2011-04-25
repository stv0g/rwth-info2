//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 09: Anwendung von Filterfunktionen
//
// Datei:  ImageViewer.cpp
// Inhalt: Klasse ImageViewer zum oeffnen, speicher, und zum Darstellen von Bildern
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <QtCore/QString>
#include <QtGui/QtGui>
#include <QtGui/QColor>
#include <QtGui/QSizePolicy>

#include "ImageViewer.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
int ImageViewer::count = 1;

//////////////////////////////////////////////////////////////////////////////
ImageViewer::ImageViewer()
{
	label = new QLabel;
	label->setBackgroundRole(QPalette::Base);

	name = "unsaved " + QString::number(count++, 10);

	setCentralWidget(label);
	setFocusPolicy(Qt::ClickFocus);
	layout()->setSizeConstraint(QLayout::SetFixedSize);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle("ImageViewer: " + name);
}

//////////////////////////////////////////////////////////////////////////////
ImageViewer::ImageViewer(QImage* neuesImage)
{
	label = new QLabel;
	label->setBackgroundRole(QPalette::Base);

	name = "unsaved_" + QString::number(count++, 10) + ".png";

	setCentralWidget(label);
	setFocusPolicy(Qt::ClickFocus);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle("ImageViewer: " + name);

	image = neuesImage;
	label->setPixmap(QPixmap::fromImage(*image));
	label->adjustSize();

	resize(image->width(), image->height());
	show();
}

//////////////////////////////////////////////////////////////////////////////
ImageViewer::~ImageViewer()
{
	delete image;
}

//////////////////////////////////////////////////////////////////////////////
void ImageViewer::open()
{
	image = new QImage;
	QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen",
			"./images");
	if (!fileName.isEmpty())
	{
		image->load(fileName);
		if (image->isNull())
		{
			QMessageBox::information(this, "Image Viewer",
					tr("Cannot load %1.").arg(fileName));
			return;
		}
		label->setPixmap(QPixmap::fromImage(*image));
		label->adjustSize();

		name = fileName.section('/', -1);
		setWindowTitle("ImageViewer: " + name);

	}

	resize(image->width(), image->height());
	show();
}

//////////////////////////////////////////////////////////////////////////////
void ImageViewer::save()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Datei speichern",
			QDir::currentPath() + "/images/" + name, "Bilddateien (*.png *.bmp)");

	if (!fileName.isEmpty())
	{
		image->save(fileName);
		name = fileName;
	}
}

//////////////////////////////////////////////////////////////////////////////
QImage* ImageViewer::getImage()
{
	return image;
}

//////////////////////////////////////////////////////////////////////////////
void ImageViewer::setImage(QImage* neu)
{
	image = neu;
	label->setPixmap(QPixmap::fromImage(*image));
	label->adjustSize();
	resize(image->width(), image->height());
	show();
}

//////////////////////////////////////////////////////////////////////////////
QImage* ImageViewer::stroke(QColor color = Qt::red)
{
	QImage *strokedImage = new QImage(*image); /* copy constructor */

	QPainter painter(strokedImage);

	QPen pen(color, 3);
	painter.setPen(pen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawLine(0, 0, image->width(), image->height());

	return strokedImage;
}

//////////////////////////////////////////////////////////////////////////////
QImage* ImageViewer::frame(int thickness = 20, QColor color = Qt::red)
{
	QImage *framedImage = new QImage(image->width() + 2 * thickness,
			image->height() + 2 * thickness, QImage::Format_RGB32);
	framedImage->fill((uint) color.rgb());

	QPainter painter(framedImage);
	painter.drawImage(thickness, thickness, *image);

	return framedImage;
}

//////////////////////////////////////////////////////////////////////////////
QImage* ImageViewer::grayscale()
{
	QImage *grayImage = new QImage(image->width(), image->height(), QImage::Format_RGB32);

	for (int y = 0; y < image->height(); ++y)
	{
		for (int x = 0; x < image->width(); ++x)
		{
			int pixel = image->pixel(x, y);
			int gray = qGray(pixel);
			int alpha = qAlpha(pixel);
			grayImage->setPixel(x, y, qRgba(gray, gray, gray, alpha));
		}
	}

	return grayImage;
}

//////////////////////////////////////////////////////////////////////////////
QString ImageViewer::getName() {
	return name;
}
