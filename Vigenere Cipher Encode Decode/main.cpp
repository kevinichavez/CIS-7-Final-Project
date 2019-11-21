#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

int main() {

	Vigenere* cipher = new Vigenere;

	string otp = "X V H E   U W   N O P G D Z";
	string enc = cipher->encrypt("T H I S  I S  S E C R E T", otp);
	string dec = (enc, otp);

	cout << "Encrypted message: " << enc << "\n";
	cout << "Decrypted message: " << dec << "\n";

	delete cipher;
}
