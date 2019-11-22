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

	// Program main loop
	while (running) {
		// Ask user whether to encrypt or decrypt
		cout << "Would you like to encrypt or decrypt a message? (Enter 'e' or 'd')\n";
		getline(cin, input);

		// Catch invalid input; return to beginning of loop if invalid
		if (input != "d" && input != "D" && input != "e" && input != "E") {
			cout << "You did not enter 'e' or 'd'\n";
			continue;
		}

		// Get user message
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
			cout << "Your encrypted message:\n\n" << processedMessage << "\n\n";

			// Write to log
			if (output.is_open())
				output << LOG_ENCRYPTION_SEPERATOR << "Plaintext:\n" << message << "\n\nKey:" << key << "\n\nEncrypted Message:\n" << processedMessage;
			break;

		case 'd':
		case 'D':
			cout << "Decrypting message...";
			cout << '\n' << LOCK_UNLOCKED << '\n';
			processedMessage = cipher->decrypt(message, key);
			cout << "Your decrypted message:\n\n" << processedMessage << "\n\n";

			// Write to log
			if (output.is_open())
				output << LOG_DECRYPTION_SEPERATOR << "Ciphertext:\n" << message << "\n\nKey:\n" << key << "\n\nDecrypted Message:\n" << processedMessage;
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
			cout << "\n##################################################################\n\n";
			break;
		}
	}
	
	delete cipher;
}

// Gets multiple lines of input from keyboard by looping until a blank line is entered
string getMultiLineInput() {
	string temp = "temp";
	string result;

	while (temp != "") {
		getline(cin, temp);
		result += ('\n' + temp);
	}
	if (result == "")
		return "";
	// Strips newline from beginning of message
	return result.substr(1, result.size());
}