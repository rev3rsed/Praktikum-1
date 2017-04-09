#include <iostream>

using namespace std;

class MastermindDigits
{
	friend ostream &operator<<(std::ostream &, const MastermindDigits &);
	friend istream &operator>>(std::istream &, MastermindDigits &);

public:
	MastermindDigits(unsigned int = 4);
	MastermindDigits(const MastermindDigits &);
	~MastermindDigits();

	const MastermindDigits &operator = (const MastermindDigits &);
	//size_t getSize() const;

	bool operator==(const MastermindDigits &) const;
	bool operator!=(const MastermindDigits &right) const {
		return !(*this == right);
	}

	unsigned int& operator[](size_t);
	unsigned int operator[](size_t ) const;
	operator unsigned int() const;

	void makeDigitsToGuess();
	unsigned int locationRight(MastermindDigits mD);
	unsigned int locationWrong(MastermindDigits mD);
	bool isLegit(unsigned int x);

private:
	unsigned int* digits;
	size_t size = 4;
};


