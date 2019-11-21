#include "vigenere.h"
#include "constants.h"
#include <iostream>
#include <string>

using namespace std;

void genMatrix(string s, vector<vector<char>>& matrix) {
	matrix.resize(s.size(), vector<char>(s.size()));

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++)
			matrix[i][j] = s[j];
		s = s.substr(1, s.size() - 1) + s[0];
	}


}

Vigenere::Vigenere() {
	for (int i = 0; i < m_nonAlphaSymbols.size(); i++)
		legalNotAlpha.insert(m_nonAlphaSymbols[i]);

	genMatrix(m_alphabet, m_alphaMatrix);
	genMatrix(m_nonAlphaSymbols, m_nonAlphaMatrix);
}

void Vigenere::printAlphaMatrix() {
	printMatrix(m_alphaMatrix, m_alphabet.size());
}

void Vigenere::printNonAlphaMatrix() {
	printMatrix(m_nonAlphaMatrix, m_nonAlphaSymbols.size());
}

void Vigenere::printMatrix(const vector<vector<char>>& matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

std::string Vigenere::encrypt(std::string message, std::string key) {
	return std::string();
}
