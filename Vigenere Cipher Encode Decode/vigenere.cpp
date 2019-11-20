#include "vigenere.h"
#include "constants.h"
#include <string>

using namespace std;

void Vigenere::initializeMatrix(int size, string symbols) {
	m_numSymbols = size;

	m_matrix.resize(size, vector<char>(size));

	// Fill matrix with values based on the symbol table
	for (int i = 0; i < m_numSymbols; i++) {
		for (int j = 0; j < m_numSymbols; j++) {

		}
	}
}

Viginere::Vigenere() {
	initializeMatrix(DEFAULT_TABLE.size());

}
