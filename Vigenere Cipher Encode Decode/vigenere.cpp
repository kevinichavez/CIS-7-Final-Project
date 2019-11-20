#include "vigenere.h"
#include "constants.h"
#include <iostream>
#include <string>

using namespace std;

void Vigenere::initializeMatrix(string symbols) {

	m_numSymbols = symbols.size();

	if (m_numSymbols < 2) {
		cerr << "Symbol table was too small.\n";
		return;
	}


	m_matrix.resize(m_numSymbols, vector<char>(m_numSymbols));

	// Fill matrix with values based on the symbol table
	for (int i = 0; i < m_numSymbols; i++) {
		for (int j = 0; j < m_numSymbols; j++)
			m_matrix[i][j] = symbols[j];

		symbols = symbols.substr(1, m_numSymbols - 2) + symbols[0];
	}
}

Vigenere::Vigenere() {
	initializeMatrix(DEFAULT_TABLE);

}
