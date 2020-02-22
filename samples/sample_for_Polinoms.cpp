/*
Polynomial view : "coef"x^power/y^power/z^power-"coef"x^power/y^power/z^power etc
Examples: 3x^4, y^4x-3z^3, 4, x^7yx
If power >9, when you enter power, you get error
*/

#include <Polinom.h>

int main(int argc, char *argv[])
{
	
	string s;
	cin >> s;
	Polinom param;
	param.create_pol(s);
	param.print();
	while (true);
}