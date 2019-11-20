#ifndef VIGINERE_H
#define VIGINERE_H
#include "constants.h"
#include <vector>
#include <map>

class Viginere {

private:
	std::vector<std::vector<char>> m_matrix;
	int m_numSymbols;

	void initializeMatrix(int size, std::string symbols);

public:
	// Default Constructor
	Viginere();
};

#endif