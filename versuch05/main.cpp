#include "Vektor.h"
#include <cmath>
#include <iostream>

int main()
{
	Vektor v1(1, -2, 3);
	Vektor v2(9.9, 0, 6);
	Vektor v3(4.1, 9.2, -2.3);
	Vektor v4 = Vektor::add(v1, v2);

	std::cout << "v1 = "; v1.ausgabe();
	std::cout << "v2 = "; v2.ausgabe();
	std::cout << "v3 = "; v3.ausgabe();
	std::cout << "v4 = "; v4.ausgabe();

	v3.substract(v4);
	std::cout << std::endl << "v3-4 = "; v3.ausgabe();

	std::cout << std::endl << "v4 = (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")" << std::endl;

	std::cout << std::endl << "||v2|| = " << v2.getLength() << std::endl;

	std::cout << std::endl << "Rotate pi/2 ccw: v2' = "; Vektor::rotate(v2, M_PI/2).ausgabe();
	std::cout << "Rotate 52° ccw: v2'' = "; Vektor::rotate(v2, 52*M_PI/180).ausgabe();

	/* Teilaufgabe 3: Berechnung der Sichtweite */
	double radius = 6371000;
	double size1 = 1.8;
	double size2 = 830;
	Vektor v5(0, radius + size1, 0);
	Vektor v6(0, radius + size2, 0);

	std::cout << std::endl << "Sichtweite bei " << size1 << "m über der Meeresoberfläche: "
			  << -Vektor::rotate(v5, acos(radius / (radius + size1))).getX() / 1000 << "km" << std::endl;
	std::cout << "Sichtweite bei " << size2 << "m über der Meeresoberfläche: "
				  << -Vektor::rotate(v6, acos(radius / (radius + size2))).getX() / 1000 << "km" << std::endl;

	return 0;
}
