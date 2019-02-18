#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

int main(int argc, char * argv[])
{
	int size;
	int width = 8;
	if (argc == 5) {
		width = atoi(argv[4]);
	}
	if (argc >= 4) {
		size = atoi(argv[3]);
	}
	else if (argc == 3) {
		size = 256; // Default GB BROM Size
	}
	else {
		cout << "Usage: bin2mif <input.bin> <output.mif> [size] [width]" << endl;
		return -1;
	}

	ifstream inFile(argv[1], ios::in | ios::binary);
	ofstream outFile(argv[2], ios::out | ios::trunc);

	char * buffer;

	buffer = (char *)malloc(size);
	inFile.read(buffer, size);
	for (int i = 0; i < size; i++) {
		outFile << hex << uppercase << setw(2) << setfill('0') << int((uint8_t)buffer[i]);
		if (i % (width / 8) == (width / 8 - 1))
			outFile << endl;
	}

	inFile.close();
	outFile.close();

    return 0;
}
