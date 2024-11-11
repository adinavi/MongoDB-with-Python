
#ifndef FILECOMPRESSOR_H
#define FILECOMPRESSOR_H

#include <string>
#include <vector>
#include <thread>

class FileCompressor {
public:
    bool compress(const std::string& inputFile, const std::string& outputFile);

private:
    void compressChunk(const std::vector<char>& inputChunk, std::vector<char>& outputChunk);
    static constexpr size_t CHUNK_SIZE = 1024 * 1024; // 1MB
};

#endif
