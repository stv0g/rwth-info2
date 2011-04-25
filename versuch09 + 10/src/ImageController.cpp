#include "ImageController.h"
#include "EdgeDetector.h"

#include <iostream>
#include <typeinfo>
#include <algorithm>

ImageController::ImageController()
{
	ui.setupUi(this);
	viewers = new std::vector<ImageViewer*>;

	/* setup signal & slots */
	QObject::connect(this->ui.loadButton, SIGNAL(clicked()), this,
			SLOT(loadImage()));
	QObject::connect(this->ui.saveButton, SIGNAL(clicked()), this,
			SLOT(saveImage()));
	QObject::connect(this->ui.strokeButton, SIGNAL(clicked()), this,
			SLOT(strokeImage()));
	QObject::connect(this->ui.frameButton, SIGNAL(clicked()), this,
			SLOT(frameImage()));
	QObject::connect(this->ui.grayscaleButton, SIGNAL(clicked()), this,
			SLOT(grayscaleImage()));
	QObject::connect(this->ui.edgeButton, SIGNAL(clicked()), this,
			SLOT(detectEdges()));
	QObject::connect(this->ui.viewersCombo, SIGNAL(currentIndexChanged(int)),
			this, SLOT(viewerSelected(int)));

	loadImage(); /* load first image */
}

void ImageController::loadImage()
{
	ImageViewer * newImage = new ImageViewer;
	newImage->open();
	showImage(newImage);
}

void ImageController::saveImage()
{
	current->save();
}

void ImageController::showImage(ImageViewer * newImage)
{
	current = newImage;
	viewers->push_back(current); /* add pointer to list of images */
	ui.viewersCombo->addItem(current->getName()); /* add to combobox */
	ui.viewersCombo->setCurrentIndex(viewers->size() - 1); /* select in combobox */
	QObject::connect(current, SIGNAL(destroyed(QObject *)), this, SLOT(viewerClosed(QObject *)));
}

void ImageController::strokeImage()
{
	showImage(new ImageViewer(current->stroke(Qt::red)));
}

void ImageController::frameImage()
{
	showImage(new ImageViewer(current->frame(20, Qt::green)));
}

void ImageController::grayscaleImage()
{
	showImage(new ImageViewer(current->grayscale()));
}

void ImageController::detectEdges()
{
	EdgeDetector edge;

	/* configure EdgeDetector */
	switch (ui.edgeFilter->currentIndex())
	{
	case 0: /* Sobol */
		edge.setFilter(1, 0, -1, 2, 0, -2, 1, 0, -1);
		break;

	case 1: /* Prewitt */
		edge.setFilter(1, 0, -1, 1, 0, -1, 1, 0, -1);
		break;

	case 2: /* Laplace */
		edge.setFilter(-1, -1, -1, -1, 8, -1, -1, -1, -1);
		break;
	}

	edge.setNormalize((bool) ui.normalizeCheckbox->checkState());
	edge.setSensivity(ui.edgeSensivity->value() / 100.0);

	if (ui.edgeFilter->currentIndex() == 2)
	{ /* special case for laplace filter */
		edge.setFilterDirection(EdgeDetector::HORIZONTAL);
	}
	else if (ui.verCheckbox->checkState() && ui.horCheckbox->checkState())
	{
		edge.setFilterDirection(EdgeDetector::BOTH);
	}
	else if (ui.horCheckbox->checkState())
	{
		edge.setFilterDirection(EdgeDetector::HORIZONTAL);
	}
	else if (ui.verCheckbox->checkState())
	{
		edge.setFilterDirection(EdgeDetector::VERTICAL);
	}
	else
	{
		edge.setFilterDirection(EdgeDetector::NONE);
	}

	/* allocate memory for filter images */
	QImage *curImage = current->getImage();
	QImage *newImage = new QImage(curImage->width(), curImage->height(),
			QImage::Format_RGB32);

	edge.applyFilter(curImage, newImage);

	showImage(new ImageViewer(newImage));
}

void ImageController::viewerClosed(QObject * obj)
{
	std::vector<ImageViewer *>::iterator pos = std::find(viewers->begin(), viewers->end(), obj); /* using std algorithms */

	ui.viewersCombo->removeItem(pos - viewers->begin());
	viewers->erase(pos);

	current = (viewers->size()) ? viewers->at(viewers->size() - 1) : NULL; /* update current viewer */
	ui.viewersCombo->setCurrentIndex(viewers->size() - 1);
}

void ImageController::viewerSelected(int index)
{
	if (index >= 0)
	{
		current = viewers->at(index);
	}
	else /* no opened ImageViewer left */
	{
		current = NULL;
	}
}

void ImageController::closeEvent(QCloseEvent *e)
{
	if (viewers->size() == 0) /* no ImageViewers to close */
	{
		e->accept();
	}
	else if (QMessageBox::question(this,
			tr("Close all windows?"), tr("Close all windows?"),
			QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
	{ /* should we close all remaining ImageViewers? */
		for (std::vector<ImageViewer*>::iterator it = viewers->begin(); it
				!= viewers->end(); viewers++)
		{
			(*it)->close();
		}

		e->accept();
	}
	else /* dont close them! */
	{
		e->ignore();
	}
}
