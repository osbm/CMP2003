#include <iostream>
#include <string>

class romanType {
    private:
        std::string romanNumeral; // roman numeral
        int decimal; // decimal equivalent

    public:
        romanType();
        romanType(std::string);
        void romanToDecimal();
        void print();

};
