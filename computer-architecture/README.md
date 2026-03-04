# 🖥️ Computer Architecture

> Course materials for **Computer Architecture** (computer organization, hardware/software interface) at [FCUP](https://www.fc.up.pt/) — 1st year, 2nd semester.

[![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))
[![x86-64](https://img.shields.io/badge/x86--64-Assembly-red?style=for-the-badge)](https://en.wikipedia.org/wiki/X86-64)

## 📂 Directory Structure

```txt
computer-architecture/
└── 📁 sheets/           # Exercise sheets
    ├── 1/
    └── 2/
```

## 📝 Sheets

| Sheet | Topic                    | Exercises | Description                                                                     |
| ----- | ------------------------ | --------- | ------------------------------------------------------------------------------- |
| 1     | C Compilation Pipeline   | 3         | GCC stages (preprocessing, compilation, assembly, linking) and optimizations    |
| 2     | Integer Representation   | 7         | Binary/decimal/hex conversions, signed/unsigned, sign extension, and arithmetic |

### Sheet 1 — C Compilation Pipeline

Each exercise includes the full compilation artifacts (`.i`, `.s`, `-optimized.s`, `.o`, `.out`):

| Exercise | Description                                                                 |
| -------- | --------------------------------------------------------------------------- |
| 1        | Multiplication table stored in an array — demonstrates dead code elimination when optimized |
| 2        | Multiplication table with `printf` output — linking with standard I/O       |
| 3        | String encryption with `crypt()` — conditional compilation (`#ifdef DEBUG`) and linking with `-lcrypt` |

### Sheet 2 — Integer Representation

| Exercise | Description                                                                     |
| -------- | ------------------------------------------------------------------------------- |
| 1        | Decimal to binary conversion (8 bits, unsigned)                                 |
| 2        | Binary to decimal conversion (8 bits, unsigned)                                 |
| 3        | Decimal to binary conversion (8 bits, signed / two's complement)                |
| 4        | Binary to decimal conversion (8 bits, signed / two's complement)                |
| 5        | Sign extension from 8 bits to 16 bits (signed)                                  |
| 6        | Binary to hexadecimal conversion (32 bits)                                      |
| 7        | Arithmetic operations with overflow detection (8 bits, signed)                  |

## 🔗 Resources

- [Computer Organization and Design: The Hardware/Software Interface](https://shuyuej.com/books/Computer%20Organization%20and%20Design-%20The%20Hardware%3ASoftware%20Interface.pdf) — Patterson & Hennessy (PDF)
