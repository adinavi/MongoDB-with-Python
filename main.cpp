
#include "FileCompressor.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    FileCompressor compressor;
    if (compressor.compress(inputFile, outputFile)) {
        std::cout << "Compression successful!" << std::endl;
    } else {
        std::cerr << "Compression failed." << std::endl;
    }

    return 0;
}
