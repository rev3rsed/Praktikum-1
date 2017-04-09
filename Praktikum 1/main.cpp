#include <iostream>
#include <stdexcept>
#include "MastermindDigits.h"

using namespace std;

int main(void) {
	cout << "Testen(1) oder Spielen(2): ";

	unsigned int mode;

	cin >> mode;
	cin.ignore();

	if (mode == 1) {
		cout << endl << "Vierstellige Zahl eingeben: ";
		MastermindDigits test = MastermindDigits(1111);

		
		cin >> test;
		//cin.ignore();

		unsigned int trys = 0;

		cout << test;

		while (1) {
			++trys;
			cout << endl << trys << ". Versuch: ";

			MastermindDigits play = MastermindDigits(1111);
			
			cin >> play;
			cin.ignore();

			if (play == test) {
				cout << "Gewonnen !" << endl;
				break;
			}
			cout << endl << test.locationRight(play) << " an der richtigen Stelle;" << endl;
			cout << test.locationWrong(play) << " an der falschen Stelle." << endl;

		}
		cin.ignore();
	}
	else {
		unsigned int trys = 0;

		MastermindDigits test = MastermindDigits(1111);
		test.makeDigitsToGuess();

		while (1) {
			++trys;
			cout << endl << trys << ". Versuch: ";

			MastermindDigits play = MastermindDigits(1111);

			cin >> play;
			cin.ignore();

			if (play == test) {
				cout << "Gewonnen !" << endl;
				break;
			}
			cout << endl << test.locationRight(play) << " an der richtigen Stelle;" << endl;
			cout << test.locationWrong(play) << " an der falschen Stelle." << endl;

		}
		cin.ignore();
	}
}