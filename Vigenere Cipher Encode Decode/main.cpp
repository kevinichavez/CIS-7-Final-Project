#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

int main() {

	Vigenere* cipher = new Vigenere("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	cipher->printMatrix();

	delete cipher;
}
