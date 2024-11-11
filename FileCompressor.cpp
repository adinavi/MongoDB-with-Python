
#include "FileCompressor.h"
#include <fstream>
#include <iostream>
#include <zlib.h>

bool FileCompressor::compress(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);
    if (!input || !output) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    std::vector<std::thread> threads;
    std::vector<char> buffer(CHUNK_SIZE);
    std::vector<char> compressedData;
    
    while (input.read(buffer.data(), buffer.size()) || input.gcount() > 0) {
        size_t bytesRead = input.gcount();
        std::vector<char> inputChunk(buffer.begin(), buffer.begin() + bytesRead);
        compressedData.resize(compressBound(bytesRead));
        
        threads.emplace_back(&FileCompressor::compressChunk, this, inputChunk, std::ref(compressedData));
    }
    
    for (auto& t : threads) t.join();

    for (auto& chunk : compressedData) {
        output.write(chunk.data(), chunk.size());
    }

    return true;
}

void FileCompressor::compressChunk(const std::vector<char>& inputChunk, std::vector<char>& outputChunk) {
    uLongf compressedSize = outputChunk.size();
    compress(reinterpret_cast<Bytef*>(outputChunk.data()), &compressedSize, 
             reinterpret_cast<const Bytef*>(inputChunk.data()), inputChunk.size());
    outputChunk.resize(compressedSize);  // Adjust size to actual compressed data size
}
