#include "vigenere.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

using namespace std;

void genMatrix(string s, vector<vector<char>>& matrix) {
	matrix.resize(s.size(), vector<char>(s.size()));

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++)
			matrix[i][j] = s[j];
		s = s.substr(1, s.size() - 1) + s[0];
	}
}

void setupIndexMap(unordered_map<char, int>& map, string s) {
	for (int i = 0; i < s.size(); i++)
		map.insert({ s[i], i });
}

int findColumn(vector<vector<char>> matrix, int row, char key) {
	for (int i = 0; i < matrix.size(); i++)
		if (matrix[i][row] == key)
			return i;

	return -1;
}

Vigenere::Vigenere() {
	genMatrix(m_alphabet, m_alphaMatrix);
	genMatrix(m_nonAlphaSymbols, m_nonAlphaMatrix);
	setupIndexMap(m_alphaIndeces, m_alphabet);
	setupIndexMap(m_nonAlphaIndeces, m_nonAlphaSymbols);
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


void Vigenere::extractAlphaNonAlpha(string& keyAlpha, string& keyNonAlpha, string keyPhrase) {
	for (int i = 0; i < keyPhrase.size(); i++) {
		if (isalpha(keyPhrase[i]))
			keyAlpha += keyPhrase[i];
		else if (m_nonAlphaIndeces.find(keyPhrase[i]) != m_nonAlphaIndeces.end())
			keyNonAlpha += keyPhrase[i];
	}
}

std::string Vigenere::encrypt(string plaintext, string key) {
	string encrypted;

	string keyAlpha, keyNonAlpha;

	extractAlphaNonAlpha(keyAlpha, keyNonAlpha, key);

	// If no alphabetic characters are in key, do not encrypt alphabetic characters in plaintext
	if (keyAlpha == "") {
		keyAlpha = m_alphaMatrix[0][0];
	}

	// If no non-alphabetic characters are in key, do not encrypt non-alphabetic characters in plaintext
	if (keyNonAlpha == "") {
		keyNonAlpha = m_nonAlphaMatrix[0][0];
	}

	unordered_map<char, int>::iterator it;
	for (int i = 0, totalAlpha = 0, totalNonAlpha = 0, col, row; i < plaintext.size(); i++) {
		if (isalpha(plaintext[i])) {
			it = m_alphaIndeces.find(toupper(plaintext[i]));
			col = it->second;
			it = m_alphaIndeces.find(keyAlpha[totalAlpha % keyAlpha.size()]);
			row = it->second;
			if (islower(plaintext[i]))
				encrypted += tolower(m_alphaMatrix[col][row]);
			else encrypted += m_alphaMatrix[col][row];
			totalAlpha++;
		}
		else if (m_nonAlphaIndeces.find(plaintext[i]) != m_nonAlphaIndeces.end()) {
			it = m_nonAlphaIndeces.find(plaintext[i]);
			col = it->second;
			it = m_nonAlphaIndeces.find(keyNonAlpha[totalNonAlpha % keyNonAlpha.size()]);
			row = it->second;
			encrypted += m_nonAlphaMatrix[col][row];
			totalNonAlpha++;
		}
		else encrypted += plaintext[i];
	}

	return encrypted;
}

std::string Vigenere::decrypt(std::string ciphertext, std::string key) {
	string decrypted;

	string keyAlpha, keyNonAlpha;

	extractAlphaNonAlpha(keyAlpha, keyNonAlpha, key);

	// If no alphabetic characters are in key, do not decrypt alphabetic characters in ciphertext
	if (keyAlpha == "") {
		keyAlpha = m_alphaMatrix[0][0];
	}

	// If no non-alphabetic characters are in key, do not decrypt non-alphabetic characters in ciphertext
	if (keyNonAlpha == "") {
		keyNonAlpha = m_nonAlphaMatrix[0][0];
	}

	unordered_map<char, int>::iterator it;
	for (int i = 0, totalAlpha = 0, totalNonAlpha = 0, col, row; i < ciphertext.size(); i++) {
		if (isalpha(ciphertext[i])) {
			it = m_alphaIndeces.find(keyAlpha[totalAlpha % keyAlpha.size()]);
			row = it->second;
			col = findColumn(m_alphaMatrix, row, toupper(ciphertext[i]));
			// We use the 0th col because it is guarenteed to be in alphabetical order
			if (islower(ciphertext[i]))
				decrypted += tolower(m_alphaMatrix[0][col]);
			else decrypted += m_alphaMatrix[0][col];
			totalAlpha++;
		}
		else if (m_nonAlphaIndeces.find(ciphertext[i]) != m_nonAlphaIndeces.end()) {
			it = m_nonAlphaIndeces.find(keyNonAlpha[totalNonAlpha % keyNonAlpha.size()]);
			row = it->second;
			col = findColumn(m_nonAlphaMatrix, row, ciphertext[i]);
			decrypted += m_nonAlphaMatrix[0][col];
			totalNonAlpha++;
		}
		else decrypted += ciphertext[i];
	}

	return decrypted;
}
