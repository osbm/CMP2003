#include"Header_romanType.h"

void romanType::setRoman(std::string roman) {

	romanNumber = roman;
	romanToDecimal();
}

romanType::romanType() {
	romanNumber = "I";
	decimal = 1;
}
/*
XIV -> 

*/
void romanType::romanToDecimal() {
	decimal = 0;
	int previous = 1000;
	for (int i = 0; i < romanNumber.length(); i++)
	{
		switch (romanNumber[i])
		{
		case 'M': 
			decimal += 1000;
			if (previous < 1000)
			{
				decimal -= 2 * previous;
			}
			previous = 1000;
			break;
		case 'D':
			decimal += 500;
			if (previous < 500)
			{
				decimal -= 2 * previous;
			}
			previous = 500;
			break;
		case 'C':
			decimal += 100;
			if (previous < 100)
			{
				decimal -= 2 * previous;
			}
			previous = 100;
			break;
		case 'L':
			decimal += 50;
			if (previous < 50)
			{
				decimal -= 2 * previous;
			}
			previous = 50;
			break;
		case 'X':
			decimal += 10;
			if (previous < 10)
			{
				decimal -= 2 * previous;
			}
			previous = 10;
			break;
//IV
//decimal = 1 + 5 - 1 *2

		case 'V':
			decimal += 5;
			if (previous < 5)
			{
				decimal -= 2 * previous;
			}
			previous = 5;
			break;
		case 'I':
			decimal += 1;
			previous = 1;
			break;
		}
	}
}

void romanType::printDecimal() {
	std::cout << "Decimal : "
		<< decimal << std::endl;
}

void romanType::printRoman() {
	std::cout << "Roman : "
		<< romanNumber << std::endl;
}