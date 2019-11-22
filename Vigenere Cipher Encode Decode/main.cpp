#include <iostream>
#include <string>
#include <cctype>
#include "vigenere.h"
// #include <cassert>

using namespace std;

void printEncDec(string plaintext, string otp, Vigenere* cipher);
string getMultiLineInput();

int main() {

	Vigenere* cipher = new Vigenere;

	string input, message, key;

	cout << "Welcome to the Vigenere Cipher tool!\n";
	cout << "Would you like to encrypt or decrypt a message? (Enter 'e' or 'd')\n";
	getline(cin, input);

	if (input != "d" && input != "D" && input != "e" && input != "E") {
		delete cipher;
		cout << "You did not enter 'e' or 'd'\n";
		return 0;
	}

	cout << "Enter your message. When you are done, press enter on a blank line.\n";
	message = getMultiLineInput();
	cout << "Now enter your key. Enter a blank line when you are done.\n";
	key = getMultiLineInput();
	
	switch (input[0]) {
	case 'e':
	case 'E':
		cout << "Your encrypted message is:\n" << cipher->encrypt(message, key);
		break;

	case 'd':
	case 'D':
		cout << "Your decrypted message is:\n" << cipher->decrypt(message, key);
		break;

	default:
		// Default case should never be called
		break;
	}
	delete cipher;
}

void printEncDec(string plaintext, string otp, Vigenere* cipher) {
	string enc = cipher->encrypt(plaintext, otp);
	string dec = cipher->decrypt(enc, otp);

	cout << "Plaintext: " << plaintext << '\n';
	cout << "Encrypted message: " << enc << "\n";
	cout << "Decrypted message: " << dec << "\n";
}

string getMultiLineInput() {
	string temp = "temp";
	string result;

	while (temp != "") {
		getline(cin, temp);
		result += temp;
	}
	return result;
}