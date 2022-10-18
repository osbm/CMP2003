
#include <iostream>
#include"Header_romanType.h"

int main()
{
	romanType a, b;

	a.printDecimal();
	a.printRoman();

	std::cout << "Change roman number of a : "<<std::endl;
	a.setRoman("XCIX");
	a.printDecimal();
	a.printRoman();
}
