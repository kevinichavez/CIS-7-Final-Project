#ifndef VIGENERE_H
#define VIGENERE_H
#include "constants.h"
#include <vector>
#include <map>

class Vigenere {

private:
	std::vector<std::vector<char>> m_matrix;
	int m_numSymbols;

	void initializeMatrix(std::string symbols);

public:
	// Default Constructor
	Vigenere();
};

#endif
