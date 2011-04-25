//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 10: Anwendung von Filterfunktionen
//
// Datei:  EdgeDetection.cpp
// Inhalt: Klasse EdgeDetector zur Detektierung von Kanten in Farb-/Graubildern
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
///////////////////////////////// INCLUDES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include <iostream>
#include <QtGui/QImage>

#include "EdgeDetector.h"
#include "Matrix3x3.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
///////////////////////// Funktions-Implementierung //////////////////////////
//////////////////////////////////////////////////////////////////////////////

EdgeDetector::EdgeDetector()
{
	/* initialize sobol filter */
	filter.setMatrix(1, 0, -1, 2, 0, -2, 1, 0, -1);

	direction = BOTH;
	normalize = true;
	sensivity = 1;
}

void EdgeDetector::setFilter(int a11, int a12, int a13, int a21, int a22,
		int a23, int a31, int a32, int a33)
{
	filter.setMatrix(a11, a12, a13, a21, a22, a23, a31, a32, a33);
}

void EdgeDetector::setSensivity(double newSensivity)
{
	sensivity = newSensivity;
}

void EdgeDetector::setNormalize(bool newNormalize)
{
	normalize = newNormalize;
}

void EdgeDetector::setFilterDirection(FilterDirection newDir)
{
	direction = newDir;
}

void EdgeDetector::applyFilter(QImage *in, QImage *out)
{
	int width = in->width();
	int height = in->height();
	long unsigned int max = 0; /* required for normalization */
	double raw[width][height];

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			/* outPixel[0] => HORIZONTAL
			 * outPixel[1] => VERTICAL */
			double outPixel[2] = {0};

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					/* exceeding image dimensions? */
					if (x + i - 1 >= 0 && x + i - 1 < width && y + j - 1 >= 0 && y + j - 1 < height)
					{
						int inPixel = in->pixel(x + i - 1, y + j - 1);
						int gray = qGray(inPixel);

						if (direction == HORIZONTAL || direction == BOTH)
						{
							outPixel[HORIZONTAL] += filter.getMatrixWert(i, j) * gray * sensivity;
						}

						if (direction == VERTICAL || direction == BOTH)
						{
							outPixel[VERTICAL] += filter.transpose().getMatrixWert(i, j) * gray * sensivity;
						}
					}
				}
			}

			/* take absolute value */
			raw[x][y] = sqrt(pow(outPixel[HORIZONTAL], 2) + pow(outPixel[VERTICAL], 2));

			if (raw[x][y] > max)
			{
				max = raw[x][y];
			}
		}
	}

	double scale = (max > 255 && normalize) ? 255 / (double) max : 1;
	std::cout << "sensivity: " << sensivity << std::endl
			<< "max pixel value: " << max << std::endl
			<< "scaling now with: " << scale << std::endl;

	/* normalize and create output image */
	for (int y = 0; y < out->height(); ++y)
	{
		for (int x = 0; x < out->width(); ++x)
		{
			raw[x][y] *= scale;
			out->setPixel(x, y, qRgb(round(raw[x][y]), round(raw[x][y]), round(raw[x][y])));
		}
	}

	out->invertPixels(QImage::InvertRgba); /* edges => black not white! */
}
