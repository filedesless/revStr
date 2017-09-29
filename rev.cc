#include <string>
#include <iostream>
#include <fstream>

// Swaps two char from a std string in place
inline void swap(std::string &line, int i, int j) {
	line[i] ^= line[j];
	line[j] ^= line[i];
	line[i] ^= line[j];
}

// Reverses a string in place
inline std::string& revStr(std::string &line) {
	int n(line.length());
	for (int i(0); i < n / 2; ++i)
		swap(line, i, n-i-1);
	return line;
}

// Reverses a file line by line in place
inline void readFile(std::istream &file) {
	std::string line;

	while ( std::getline(file, line) )
		std::cout << revStr(line) << std::endl;
}

int main(int argc, char** argv) {
	if (argc > 1) // file(s) from args
		for (int i(1); i < argc; ++i)
		{
			std::string filename(argv[i]);
			std::ifstream file(filename);
			if ( file.is_open() )
				readFile(file);
			file.close();
		}
	else // read from stdin
		readFile(std::cin);

	return 0;
}
