#include <iostream>
#include <string>
#include "vigenere.h"
// #include <cassert>

using namespace std;

void printEncDec(string plaintext, string otp, Vigenere* cipher);

int main() {

	Vigenere* cipher = new Vigenere;

	printEncDec("THIS IS SECRET", "XVHE UW NOPGDZ", cipher);
	printEncDec("This... is! a/ test?", "XVHE??//. UW NOPGDZ", cipher);
	printEncDec("THIS IS SECRET", "", cipher);
	printEncDec("Hello, there!", "GENERAL KENOBI!", cipher);

	delete cipher;
}

void printEncDec(string plaintext, string otp, Vigenere* cipher) {
	string enc = cipher->encrypt(plaintext, otp);
	string dec = cipher->decrypt(enc, otp);

	cout << "Plaintext: " << plaintext << '\n';
	cout << "Encrypted message: " << enc << "\n";
	cout << "Decrypted message: " << dec << "\n";
}