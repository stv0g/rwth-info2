#ifndef Vektor_H
#define Vektor_H

class Vektor
{
public:
	/**
	 * Constructor
	 */
	Vektor(double x, double y, double z);

	/**
	 * Deconstructor
	 */
	~Vektor();

	/**
	 * Get X component
	 */
	double getX() const;

	/**
	 * Get Y component
	 */
	double getY() const;

	/**
	 * Get Z component
	 */
	double getZ() const;

	/**
	 * Calculate length
	 */
	double getLength() const;

	/**
	 * Substract another Vektor
	 */
	void substract(const Vektor v);

	/**
	 * Factory method to add two Vektor instances
	 */
	static Vektor add(const Vektor a, const Vektor b);

	/**
	 * Factory method to rotate a Vektor instance
	 */
	static Vektor rotate(Vektor v, double angle);

	/**
	 * Print Vektor
	 */
	void ausgabe();

private:
	//member
	double x;
	double y;
	double z;
};

#endif
