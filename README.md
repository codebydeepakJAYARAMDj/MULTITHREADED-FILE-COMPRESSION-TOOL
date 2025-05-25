# MULTITHREADED-FILE-COMPRESSION-TOOL

*COMPANY* : CODTECH IT SOLUTIONS

*NAME* : VANKAPATI DEEPAK JAYA RAM YADAV

*INTERN ID* : CT08DN1557

*DOMAIN NAME* : C++ PROGRAMMING

*DURATION* : 8 WEEKS

*MENTOR* : NEELA SANTOSH

# Huffman File Compressor and Decompressor

This is a C++ console-based application that compresses and decompresses files using the **Huffman Coding Algorithm**. It supports both **text and binary files** and uses a lossless compression method.

---

## 📦 Features

- ✅ Compress any text or binary file
- ✅ Decompress files back to original with no data loss
- ✅ Handles large files with efficient memory usage
- ✅ Easy to use CLI interface
- ✅ Organized code with separate header and implementation files

---

## 📁 File Structure

/project-folder
│
├── main.cpp # Entry point - handles user interaction
├── Huffman.h # Header file for Huffman class
├── Huffman.cpp # Implementation of Huffman encoding/decoding logic
└── README.md # Project documentation


---

## 🧠 How It Works

The compressor works in three stages:

1. **Frequency Analysis** – Reads the file and counts the frequency of each byte.
2. **Huffman Tree Construction** – Builds a binary tree where more frequent bytes have shorter codes.
3. **Encoding** – Replaces each byte with its Huffman binary code and writes the compressed output.

The decompressor does the reverse:

1. **Deserializes the tree**
2. **Reads encoded bits**
3. **Decodes them using the tree**

---

## 🛠️ How to Compile and Run

### 🔧 Requirements

- C++11 or later
- Compatible with:
  - Dev-C++
  - Code::Blocks with MinGW
  - g++ (Linux/macOS/Windows)

### ✅ Compile (Using g++)

```bash
g++ main.cpp Huffman.cpp -o huff_compressor
./huff_compressor
```

Or in Dev-C++:

Create a new Console Project

Add all .cpp and .h files to the project

Press F9 to compile and run

📥 Usage
1️⃣ Compress a File
```bash
Huffman Compressor/Decompressor
1. Compress
2. Decompress
Enter your choice: 1
Enter input file path: C:\path\to\your\input.txt
Enter output (compressed) file path: C:\path\to\compressed.huff
```

2️⃣ Decompress a File
Huffman Compressor/Decompressor
```bash
1. Compress
2. Decompress
Enter your choice: 2
Enter compressed file path: C:\path\to\compressed.huff
Enter output (decompressed) file path: C:\path\to\restored.txt
```

🔐 Compression Format
The output file stores:

Serialized Huffman tree

Padding bit count

Encoded binary data

Decompression uses this structure to reverse the process exactly.

🚀 Future Improvements
✅ Add multi-threading support for performance

⬜ Add GUI (Qt or Electron)

⬜ Compress entire folders recursively

⬜ Integrate with ZIP formats

📚 References
Wikipedia - Huffman Coding

GitHub Refs for Multithreading & Compression

Bit Manipulation in C++

👨‍💻 Author
Vankapati Deepak Jaya Ram Yadav
Feel free to fork, contribute, or reach out for improvements.
