/*
Polynomial view : "coef"x^power/y^power/z^power-"coef"x^power/y^power/z^power etc
Examples: 3x^4, y^4x-3z^3, 4, x^7yx
If power >9, when you enter power, you get error
*/

#include <Polinom.h>

int main(int argc, char *argv[])
{
	string s;
	Polinom param1;
	cin >> s;
	param1.create_pol(s);
	cin >> s;
	Polinom param2;
	param2.create_pol(s);
	Polinom param_sum = param1 + param2;
	param_sum.print();
	while (true);
}