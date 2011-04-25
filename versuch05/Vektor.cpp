#include "Vektor.h"

#include <cmath>
#include <iostream>

Vektor::Vektor(double inX, double inY, double inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

Vektor::~Vektor()
{

}

double Vektor::getX() const
{
	return this->x;
}

double Vektor::getY() const
{
	return this->y;
}

double Vektor::getZ() const
{
	return this->z;
}

double Vektor::getLength() const {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

void Vektor::substract(const Vektor v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

Vektor Vektor::add(const Vektor a, const Vektor b)
{
	return *new Vektor(a.x+b.x, a.y+b.y, a.z+b.z);
}

Vektor Vektor::rotate(Vektor v, double angle)
{
	/* Rotationsmatrix */
	double L[3][3] = {
		{cos(angle), -sin(angle), 0},
		{sin(angle), cos(angle),  0},
		{0,			 0,			  1}
	};

	/* Matrix Multiplikation */
	return *new Vektor(
			round(1000 * (L[0][0] * v.getX() + L[0][1] * v.getY() + L[0][2] * v.getZ())) / 1000,
			round(1000 * (L[1][0] * v.getX() + L[1][1] * v.getY() + L[1][2] * v.getZ())) / 1000,
			round(1000 * (L[2][0] * v.getX() + L[2][1] * v.getY() + L[2][2] * v.getZ())) / 1000
	);
}

void Vektor::ausgabe()
{
	std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}
