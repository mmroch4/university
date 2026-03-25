# 🖥️ Computer Architecture

> Course materials for **Computer Architecture** (computer organization, hardware/software interface) at [FCUP](https://www.fc.up.pt/) — 1st year, 2nd semester.

[![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))
[![x86-64](https://img.shields.io/badge/x86--64-Assembly-red?style=for-the-badge)](https://en.wikipedia.org/wiki/X86-64)

## 📂 Directory Structure

```txt
computer-architecture/
└── 📁 sheets/           # Exercise sheets
    ├── 1/
    ├── 2/
    ├── 3/
    ├── 4/
    └── 5/
```

## 📝 Sheets

| Sheet | Topic                    | Exercises | Description                                                                     |
| ----- | ------------------------ | --------- | ------------------------------------------------------------------------------- |
| 1     | C Compilation Pipeline              | 3         | GCC stages (preprocessing, compilation, assembly, linking) and optimizations              |
| 2     | Integer Representation              | 7         | Binary/decimal/hex conversions, signed/unsigned, sign extension, and arithmetic           |
| 3     | Floating-Point Representation       | 2         | IEEE 754 float ↔ decimal conversions (single precision)                                   |
| 4     | MIPS R2000 Instruction Representation | 2       | Encoding/decoding MIPS instructions (R-type, I-type, J-type) in binary                   |
| 5     | MIPS R2000 Assembly Programming     | 6         | Assembly ↔ C translation, MIPS programs with syscalls, pseudo-instructions, bit operations |

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

### Sheet 3 — Floating-Point Representation

| Exercise | Description                                                        |
| -------- | ------------------------------------------------------------------ |
| 1        | IEEE 754 single-precision binary → decimal conversion (5 values)   |
| 2        | Decimal → IEEE 754 single-precision binary conversion (2 values)   |

### Sheet 4 — MIPS R2000 Instruction Representation

| Exercise | Description                                                                              |
| -------- | ---------------------------------------------------------------------------------------- |
| 1        | Decode binary machine code into MIPS assembly (R, I, J formats)                          |
| 2        | Encode MIPS assembly sequences into binary machine code with address/offset calculations  |

### Sheet 5 — MIPS R2000 Assembly Programming

| Exercise | Description                                                                                    |
| -------- | ---------------------------------------------------------------------------------------------- |
| 1        | Translate MIPS assembly to C — register arithmetic, array access with offsets, and loop patterns |
| 2        | Translate C to MIPS assembly — shifts, array indexing, and nested array lookups                  |
| 3        | Trace a MIPS program that computes the sum of squares (0–99) with syscall I/O                   |
| 4        | Trace a MIPS program that computes string length using a procedure call (`jal`/`jr`)            |
| 5        | Rewrite pseudo-instructions (`not`, `bge`) using base MIPS instructions                        |
| 6        | Evaluate MIPS bitwise/shift sequences and determine final register values                       |

## 🔗 Resources

- [Computer Organization and Design: The Hardware/Software Interface](https://shuyuej.com/books/Computer%20Organization%20and%20Design-%20The%20Hardware%3ASoftware%20Interface.pdf) — Patterson & Hennessy (PDF)
