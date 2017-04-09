#include "MastermindDigits.h"
#include <iomanip>
#include <stdexcept>
#include <random>


// Function to test if all digits of one int are between 1 and 6
bool MastermindDigits::isLegit(unsigned int x) {
	bool first = (x % 10) >= 1 && (x % 10) <= 6;
	bool second = ((x % 100) / 10) >= 1 && ((x % 100) / 10) <= 6;
	bool third = ((x % 1000) / 100) >= 1 && ((x % 1000) / 100) <= 6;
	bool fourth = (x / 1000) >= 1 && (x / 1000) <= 6;

	return first && second && third && fourth;
}

MastermindDigits::MastermindDigits(unsigned int nums)
{
	
	if(isLegit(nums)) {
		digits = new unsigned int[size] {(nums/1000),(nums%1000)/100,(nums%100)/10,nums%10};
	}
}

MastermindDigits::~MastermindDigits()
{
	delete[] digits;
}

MastermindDigits::MastermindDigits(const MastermindDigits& copy) {
	digits = new unsigned int[size];
	for (size_t i=0; i < 4; ++i) {
		digits[i] = copy.digits[i];
	}
}

const MastermindDigits& MastermindDigits::operator=(const MastermindDigits& right) {
	if (&right != this) {
		for (size_t i = 0; i < 4; ++i) {
			digits[i] = right.digits[i];
		}
	}
	return *this;
}

bool MastermindDigits::operator== (const MastermindDigits& right) const{
	for (size_t i = 0; i < 4; ++i) {
		if (digits[i] != right.digits[i]) return false;
	}
	return true;
}

unsigned int& MastermindDigits::operator[](size_t subscript) {
	if (subscript < 0 || subscript > 3) throw out_of_range("Array out Range!");
	return digits[subscript];
}

unsigned int MastermindDigits::operator[](size_t subscript) const{
	if (subscript < 0 || subscript > 3) throw out_of_range("Array out Range!");
	return digits[subscript];
}

istream& operator>>(istream& input, MastermindDigits& mD) {
	/*unsigned int x = 0;
	input >> x;
	for (size_t i = 4; i > 0; --i) {
		 mD.digits[4-i] = (x % (10^i)) / (10^(i-1));
	}*/

	for (size_t i = 0; i < 4; ++i) {
		input >> mD.digits[i];
	}
	return input;
}

ostream& operator<<(ostream& output,const MastermindDigits& mD) {
	for (size_t i = 0; i < 4; ++i) {
		output << mD.digits[i];
	}
	return output;
}

MastermindDigits::operator unsigned int() const{
	unsigned int number = 0, factor = 1;
	for (int i = 3; i >= 0; i--) {
		number += digits[i] * factor;
		factor *= 10;
	}
	return number;
}

void MastermindDigits::makeDigitsToGuess() {
	for (size_t i = 0; i < 4; ++i) {
		digits[i] = (rand() % 6)+1 ;
	}
}

unsigned int MastermindDigits::locationRight(MastermindDigits mD) {
	unsigned int count = 0;
	for (size_t i = 0; i < 4; ++i) {
		if (digits[i] == mD.digits[i]) ++count;
	}
	return count;
}

unsigned int MastermindDigits::locationWrong(MastermindDigits mD) {
	unsigned int count = 0;
	unsigned int* copy = new unsigned int [4];

	for (size_t i = 0; i < 4; ++i) {
		copy[i] = digits[i];
		if (mD.digits[i] == copy[i]) copy[i] = 0;
	}
	
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			if (mD.digits[j] == copy[i]) {
				++count;
				break;
			}
		}
	}
	return count;
}