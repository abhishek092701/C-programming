# C & C++ Programming Lab

> A collection of C and C++ programs written during introductory coursework — covering fundamentals through to file I/O, dynamic memory, and a full CRUD phone book application.

## Topics Covered

| Topic | Programs |
|---|---|
| **Basics** | Variables, loops, conditionals, `printf`/`scanf`, `cout`/`cin` |
| **Functions** | 4 variations — with/without parameters, with/without return |
| **Arrays & Sorting** | Bubble sort on primitives and struct arrays |
| **Strings** | Palindrome check, vowel/consonant/space counting |
| **Pointers** | Basic pointer declaration and dereferencing |
| **Structures** | Struct definition, array of structs, dynamic struct arrays |
| **Dynamic Memory** | `calloc`, `realloc`, `free` |
| **File Handling** | Binary read/write with `fwrite`/`fread`, `fseek`, `fclose` |
| **Recursion** | Fibonacci sequence |
| **ASCII / Type Casting** | Char-to-int conversions, ASCII table display |
| **Pattern Printing** | Star pyramids, numeric patterns |

## Highlights

- **Phone Book CRUD** (`Project 11.c`) — add, display, search, edit, delete, sort, save & load contacts via dynamic arrays + binary file persistence.
- **Systematic function demos** — four files (`functions.c` → `function-4.c`) each demonstrating one combination of parameter/return patterns.
- **Struct with DMA + File I/O** — employee records stored with `calloc`, sorted by salary, persisted to disk.

## Getting Started

Compile and run any program with a C or C++ compiler:

```bash
gcc program.c -o program && ./program
g++ program.cpp -o program && ./program
```

Pre-built `.bat` scripts are included for some programs (Windows).

## Build Scripts

| Script | Target |
|---|---|
| `1st ques_run.bat` | File handling demo |
| `6th ques_run.bat` | ASCII values |
| `Ascending_run.bat` | Bubble sort |
| `Ascii Value_run.bat` | ASCII display |

## Notes

- Written targeting Turbo C++ / Dev-C++ style conventions.
- Some files contain both C and C++ implementations (one commented out).
- File I/O examples use hardcoded paths — adjust for your system.
