
cmake_minimum_required(VERSION 3.10)

project(MultithreadedFileCompressionTool)

set(CMAKE_CXX_STANDARD 11)
find_package(ZLIB REQUIRED)

add_executable(MultithreadedFileCompressionTool main.cpp FileCompressor.cpp)

target_link_libraries(MultithreadedFileCompressionTool ZLIB::ZLIB)
