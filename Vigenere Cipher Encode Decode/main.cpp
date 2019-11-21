#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

int main() {

	Vigenere* cipher = new Vigenere;

	cout << cipher->encrypt("T H I S  I S  S E C R E T", "X V H E   U W   N O P G D Z") << "\n";

	delete cipher;
}
