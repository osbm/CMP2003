#include <iostream>
#include "romanType.h"

//using namespace std;

romanType::romanType() {
    romanNumeral = "I";
    decimal = 1;
}

romanType::romanType(std::string roman) {
    romanNumeral = roman;
    romanToDecimal();
}

romanType::romanToDecimal() {
    int length = romanNumeral.length();
    int number = 0;
    int i = 0;
    int value = 0;
    int nextValue = 0;

    while (i < length) {
        switch (romanNumeral[i]) {
            case 'I':
                value = 1;
                break;
            case 'V':
                value = 5;
                break;
            case 'X':
                value = 10;
                break;
            case 'L':
                value = 50;
                break;
            case 'C':
                value = 100;
                break;
            case 'D':
                value = 500;
                break;
            case 'M':
                value = 1000;
                break;
            default:
                value = 0;
        }

        if (i + 1 < length) {
            switch (romanNumeral[i + 1]) {
                case 'I':
                    nextValue = 1;
                    break;
                case 'V':
                    nextValue = 5;
                    break;
                case 'X':
                    nextValue = 10;
                    break;
                case 'L':
                    nextValue = 50;
                    break;
                case 'C':
                    nextValue = 100;
                    break;
                case 'D':
                    nextValue = 500;
                    break;
                case 'M':
                    nextValue = 1000;
                    break;
                default:
                    nextValue = 0;
            }
        } else {
            nextValue = 0;
        }

        if (value >= nextValue) {
            number += value;
        } else {
            number += nextValue - value;
            i++;
        }
        i++;
    }

    decimal = number;
}


int main() {
    romanType roman;
    romanType roman2("XVI");

    std::cout << "Roman numeral: " << roman.getRoman() << endl;
    std::cout << "Decimal equivalent: " << roman.getDecimal() << endl;
    return 0;
}
