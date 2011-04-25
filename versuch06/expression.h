#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
#include <sstream>	// um double in string umzuwandeln.

/**
 * (Abstrakte) Interface Klasse
 */
class Expression
{
public:
	virtual ~Expression(){};
	virtual double evaluate() = 0;
	virtual std::string print() const = 0;
};

class Result: public Expression
{
private:
	Expression *exp;

public:
	Result(Expression *expIn)
	{
		this->exp = expIn;
	}

	~Result()
	{
		delete this->exp;
	}

	double evaluate()
	{
		return this->exp->evaluate();
	}

	std::string print() const
	{
		return this->exp->print();
	}
};

class Const: public Expression
{
private:
	double val;

public:
	Const(double valIn)
	{
		this->val = valIn;
	}

	double evaluate()
	{
		return this->val;
	}

	std::string print() const
	{
		std::stringstream string;
		string << this->val;
		return string.str();
	}
};

class BinaryOpExpression: public Expression
{
protected:
	Expression *a, *b;

public:
	BinaryOpExpression(Expression *aIn, Expression *bIn)
	{
		this->a = aIn;
		this->b = bIn;
	}

	~BinaryOpExpression()
	{

		delete this->a;
		delete this->b;
	}
};

class Add: public BinaryOpExpression
{
public:
	Add(Expression *a, Expression *b) : BinaryOpExpression(a, b) {}

	double evaluate()
	{
		return a->evaluate() + b->evaluate();
	}

	std::string print() const
	{
		return "(" + a->print() + " + " + b->print() + ")";
	}
};

class Sub: public BinaryOpExpression
{
public:
	Sub(Expression *a, Expression *b) : BinaryOpExpression(a, b) {}

	double evaluate()
	{
		return a->evaluate() - b->evaluate();
	}

	std::string print() const
	{
		return "(" + a->print() + " - " + b->print() + ")";
	}
};

class Mul: public BinaryOpExpression
{
public:
	Mul(Expression *a, Expression *b) : BinaryOpExpression(a, b) {}

	double evaluate()
	{
		return a->evaluate() * b->evaluate();
	}

	std::string print() const
	{
		return "(" + a->print() + " * " + b->print() + ")";
	}
};

class Div: public BinaryOpExpression
{
public:
	Div(Expression *a, Expression *b) : BinaryOpExpression(a, b) {}

	double evaluate()
	{
		return a->evaluate() / b->evaluate();
	}

	std::string print() const
	{
		return "(" + a->print() + " / " + b->print() + ")";
	}
};

#endif
