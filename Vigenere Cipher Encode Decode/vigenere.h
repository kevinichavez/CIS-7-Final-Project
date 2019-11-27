#ifndef VIGENERE_H
#define VIGENERE_H
#include <vector>
#include <unordered_map>

class Vigenere {

private:
	std::vector<std::string> m_alphaMatrix;
	std::vector<std::string> m_nonAlphaMatrix;
	std::string m_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string m_nonAlphaSymbols = ".,<>?!/\\'\"[]{}+=-_~`@#$%^&*0123456789:";
	std::unordered_map<char, int> m_alphaIndeces;
	std::unordered_map<char, int> m_nonAlphaIndeces;

	// void printMatrix(const std::vector<std::string>& matrix);
	void extractAlphaNonAlpha(std::string& keyAlpha, std::string& keyNonAlpha, std::string keyPhrase);

public:
	// Default Constructor
	Vigenere();

	// Debug Print
	// void printAlphaMatrix();
	// void printNonAlphaMatrix();

	// Encrypt message with given key
	std::string encrypt(std::string plaintext, std::string key);

	// Decrypt message with given key
	std::string decrypt(std::string ciphertext, std::string key);
};

#endif
