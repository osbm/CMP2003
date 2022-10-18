#pragma once
#include<string>
#include<iostream>

class romanType {
	std::string romanNumber;

	int decimal;
public:
	romanType();
	void setRoman(std::string);
	void romanToDecimal();
	void printRoman();
	void printDecimal();
};
