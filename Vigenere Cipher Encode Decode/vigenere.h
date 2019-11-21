#ifndef VIGENERE_H
#define VIGENERE_H
#include "constants.h"
#include <vector>
#include <unordered_set>

class Vigenere {

private:
	std::unordered_set<char> legalNotAlpha;
	std::vector<std::vector<char>> m_alphaMatrix;
	std::vector<std::vector<char>> m_nonAlphaMatrix;
	std::string m_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string m_nonAlphaSymbols = ".,<>?!/\\'\"[]{}+=-_~`@#$%^&*0123456789";

	void printMatrix(const std::vector<std::vector<char>>& matrix, int n);

public:
	// Default Constructor
	Vigenere();

	// Debug Print
	void printAlphaMatrix();
	void printNonAlphaMatrix();

	// Encrypt message with given key
	std::string encrypt(std::string message, std::string key);
};

#endif
