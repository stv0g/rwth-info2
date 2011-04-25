#include "Vektor.h"
#include <cmath>
#include <iostream>

int main()
{
	/* create Vektor instances */
	Vektor v1(1, -2, 3);
	Vektor v2(9.9, 0, 6);
	Vektor v3(4.1, 9.2, -2.3);
	Vektor v4 = Vektor::add(v1, v2);

	/* print Vektors */
	std::cout << "v1 = "; v1.ausgabe();
	std::cout << "v2 = "; v2.ausgabe();
	std::cout << "v3 = "; v3.ausgabe();
	std::cout << "v4 = "; v4.ausgabe();

	/* vector calculus */
	v3.substract(v4);
	std::cout << std::endl << "v3-4 = "; v3.ausgabe();

	std::cout << std::endl << "v4 = (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")" << std::endl;

	std::cout << std::endl << "||v2|| = " << v2.getLength() << std::endl;

	std::cout << std::endl << "Rotate pi/2 ccw: v2' = "; Vektor::rotate(v2, M_PI/2).ausgabe();
	std::cout << "Rotate 52° ccw: v2'' = "; Vektor::rotate(v2, 52*M_PI/180).ausgabe();
	std::cout << std::endl;

	/* Teilaufgabe 3: Berechnung der Sichtweite */
	double radius = 6371000;
	double sizes[2] = {1.8, 830};

	for (int i = 0; i < 2; i++)
	{
		Vektor v5(0, radius + sizes[i], 0);

		/* Vektoren drehen */
		Vektor v6 = Vektor::rotate(v5, acos(radius / (radius + sizes[i])));

		/* Differenz bilden */
		Vektor v7(v6.getX(),v6.getY() - radius, v6.getZ());

		std::cout << "Sichtweite bei " << sizes[i] << "m über der Meeresoberfläche: "
				  << v7.getLength() / 1000 << "km" << std::endl;
	}

	return 0;
}
