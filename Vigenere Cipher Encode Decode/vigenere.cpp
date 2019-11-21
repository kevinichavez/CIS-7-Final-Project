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

Vigenere::Vigenere() {
	for (int i = 0; i < m_nonAlphaSymbols.size(); i++)
		legalNonAlphaSet.insert(m_nonAlphaSymbols[i]);

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

std::string Vigenere::encrypt(string message, string key) {
	string encrypted;

	string keyAlpha, keyNonAlpha;

	for (int i = 0; i < key.size(); i++) {
		if (isalpha(key[i]))
			keyAlpha += key[i];
		else if (legalNonAlphaSet.find(key[i]) != legalNonAlphaSet.end())
			keyNonAlpha += key[i];
	}

	unordered_map<char, int>::iterator it;
	for (int i = 0, totalAlpha = 0, totalNonAlpha = 0, col, row; i < message.size(); i++) {
		if (isalpha(message[i])) {
			it = m_alphaIndeces.find(message[i]);
			col = it->second;
			it = m_alphaIndeces.find(keyAlpha[totalAlpha % keyAlpha.size()]);
			row = it->second;
			encrypted += m_alphaMatrix[col][row];
			totalAlpha++;
		}
		else if (legalNonAlphaSet.find(message[i]) != legalNonAlphaSet.end()) {
			it = m_nonAlphaIndeces.find(message[i]);
			col = it->second;
			it = m_nonAlphaIndeces.find(keyNonAlpha[totalNonAlpha % keyNonAlpha.size()]);
			row = it->second;
			if (islower(message[i]))
				encrypted += tolower(m_nonAlphaMatrix[col][row]);
			else encrypted += m_nonAlphaMatrix[col][row];
			totalNonAlpha++;
		}
		else encrypted += message[i];
	}

	return encrypted;
}
