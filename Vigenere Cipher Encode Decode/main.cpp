#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

int main() {

	Vigenere* cipher = new Vigenere;

	cipher->printAlphaMatrix();
	cout << "------------------------------------\n";
	cipher->printNonAlphaMatrix();

	delete cipher;
}
