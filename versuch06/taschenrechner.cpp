#include "expression.h"

#include <iostream>

int main(int, char**)
{
	/* initialize expressions */
	Result result1(new Mul(new Const(3), new Add(new Const(2), new Const(9))));
	Result result2(new Div(new Const(3), new Const(4)));
	Result result3(new Div(new Const(3), new Sub(new Const(4), new Mul(new Const(1.2), new Const(3)))));

	/* print results */
	std::cout << result1.print() << " = " << result1.evaluate() << std::endl;
	std::cout << result2.print() << " = " << result2.evaluate() << std::endl;
	std::cout << result3.print() << " = " << result3.evaluate() << std::endl;

	return 0;
}
