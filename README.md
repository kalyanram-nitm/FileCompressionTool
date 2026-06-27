 # File Compression Tool

A C++ implementation of the Huffman Coding algorithm for lossless file compression and decompression.

## Features

- Read text files
- Count character frequencies
- Build Huffman Tree
- Generate Huffman Codes
- Compress text
- Decompress compressed files
- Display compression statistics

## Technologies Used

- C++
- STL
- CMake

## Data Structures

- Binary Tree
- Priority Queue
- Unordered Map

## Algorithm

- Huffman Coding (Greedy Algorithm)

## Project Structure

```
FileCompressionTool/
│
├── include/
├── src/
├── input/
├── output/
├── docs/
├── tests/
├── CMakeLists.txt
└── README.md
```

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

```bash
./FileCompressionTool
```

## Sample Workflow

```
sample.txt
      │
      ▼
Read File
      │
      ▼
Count Frequencies
      │
      ▼
Build Huffman Tree
      │
      ▼
Generate Codes
      │
      ▼
Compress
      │
      ▼
compressed.huff
      │
      ▼
Decompress
      │
      ▼
Original Text
```

## Concepts Learned

- Object-Oriented Programming
- File Handling
- Dynamic Memory
- Priority Queue
- Trees
- Recursion
- Greedy Algorithms

## Future Improvements

- Binary bit-level compression
- Store Huffman Tree in compressed file
- Support multiple file types
- Interactive menu
- GUI

## Authors
- Avireddy Naga Venkata Kalyan Ram
- Ghanta Pothan Sai Vamsi
- Pentakota Shyam Sai Durga Mallikarjun 