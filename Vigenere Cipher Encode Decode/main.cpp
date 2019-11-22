#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "vigenere.h"
#include "ASCII_art.h"
// #include <cassert>

using namespace std;

string getMultiLineInput();

int main() {
	cout << "Welcome to the Vigenere Cipher tool!\n";

	Vigenere* cipher = new Vigenere;

	string input, message, key, processedMessage;

	ofstream output;

	bool running = true;

	while (running) {
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

		output.open("output.log", ios::out | ios::app);

		switch (input[0]) {
		case 'e':
		case 'E':
			cout << "Encrypting message...";
			cout << '\n' << LOCK_LOCKED << '\n';
			processedMessage = cipher->encrypt(message, key);
			cout << "Your encrypted message is:\n" << processedMessage << "\n";
			if (output.is_open())
				output << LOG_ENCRYPTION_SEPERATOR << "Plaintext:" << message << "\nKey:" << key << "\nEncrypted Message:" << processedMessage;
			break;

		case 'd':
		case 'D':
			cout << "Decrypting message...";
			cout << '\n' << LOCK_UNLOCKED << '\n';
			processedMessage = cipher->decrypt(message, key);
			cout << "Your decrypted message is:\n" << processedMessage << "\n";
			if (output.is_open())
				output << LOG_DECRYPTION_SEPERATOR << "Ciphertext:" << message << "\nKey:" << key << "\nDecrypted Message:" << processedMessage;
			break;

		default:
			// Default case should never be called
			break;
		}
		if (output.is_open())
			output.close();
		else cout << "Could not write to output file.\n";

		while (input != "y" && input != "Y" && input != "n" && input != "N") {
			cout << "Would you like to process another message? (y/n)\n";
			getline(cin, input);
			if (input != "y" && input != "Y" && input != "n" && input != "N")
				cout << "Enter 'y' or 'n'\n";
		}

		switch (input[0]) {
		case 'n':
		case 'N':
			cout << "Goodbye!\n";
			running = false;
			break;
		default:
			cout << "\n############################################################\n\n";
			break;
		}
	}
	
	delete cipher;
}

string getMultiLineInput() {
	string temp = "temp";
	string result;

	while (temp != "") {
		getline(cin, temp);
		result += ('\n' + temp);
	}
	return result;
}