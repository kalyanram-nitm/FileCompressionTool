cmake_minimum_required(VERSION 3.15)

project(FileCompressionTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    FileCompressionTool

     add_executable(
    FileCompressionTool

    src/main.cpp
    src/FileManager.cpp
    src/FrequencyCounter.cpp
    src/HuffmanTree.cpp
    src/Compressor.cpp
    src/Statistics.cpp
    src/BinaryWriter.cpp
    src/Decompressor.cpp
)
)