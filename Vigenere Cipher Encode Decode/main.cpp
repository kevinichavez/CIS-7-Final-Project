#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "vigenere.h"
// #include <cassert>

using namespace std;

void printEncDec(string plaintext, string otp, Vigenere* cipher);
string getMultiLineInput();

int main() {

	Vigenere* cipher = new Vigenere;

	string input, message, key, processedMessage;

	ofstream output;

	bool running = true;

	while (running) {
		output.open("output.log", ios::out | ios::app);
		cout << "Welcome to the Vigenere Cipher tool!\n";
		cout << "Would you like to encrypt or decrypt a message? (Enter 'e' or 'd')\n";
		getline(cin, input);

		if (input != "d" && input != "D" && input != "e" && input != "E") {
			cout << "You did not enter 'e' or 'd'\n";
			continue;
		}

		cout << "Enter your message. When you are done, press enter on a blank line.\n";
		message = getMultiLineInput();
		cout << "Now enter your key. Enter a blank line when you are done.\n";
		key = getMultiLineInput();

		switch (input[0]) {
		case 'e':
		case 'E':
			processedMessage = cipher->encrypt(message, key);
			cout << "Your encrypted message is:\n" << processedMessage << '\n';
			if (output.is_open())
				output << "ENCRYPTION OUTPUT\n------------------------------\nPlaintext:\n" << message << "\nKey:\n" << key << "\nEncrypted Message:\n" << processedMessage << "\n------------------------------";
			break;

		case 'd':
		case 'D':
			processedMessage = cipher->decrypt(message, key);
			cout << "Your decrypted message is:\n" << processedMessage << '\n';
			if (output.is_open())
				output << "DECRYPTION OUTPUT\n------------------------------\nCiphertext:\n" << message << "\nKey:\n" << key << "\nDecrypted Message: " << processedMessage << "\n------------------------------";
			break;

		default:
			// Default case should never be called
			break;
		}
		if (!output.is_open())
			cout << "Could not write to output file.\n";
		else output.close();

		while (input != "y" && input != "Y" && input != "n" && input != "N") {
			cout << "Would you like to process another message? (y/n)\n";
			getline(cin, input);
			if (input != "y" && input != "Y" && input != "n" && input != "N")
				cout << "Enter 'y' or 'n'\n";
		}

		output.close();

		switch (input[0]) {
		case 'n':
		case 'N':
			cout << "Goodbye!\n";
			running = false;
			break;
		default:
			break;
		}
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