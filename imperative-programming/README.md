# ⌨️ Imperative Programming

> Course materials for **Imperative Programming** (C — sheets and Mooshak problems) at [FCUP](https://www.fc.up.pt/).

[![Course Page](https://img.shields.io/badge/Course-Material-blue?style=for-the-badge)](https://www.dcc.fc.up.pt/~fds/aulas/pi/2526/)
[![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))

## ℹ️ Overview

| Field | Value |
| --- | --- |
| Year | 1st |
| Semester | 2nd |
| Academic year | 2025/2026 |
| Language / Tools | C |
| Status | ✅ Completed |

## 📂 Directory Structure

```txt
imperative-programming/
├── 📁 sheets/             # Classroom exercise sheets
│   ├── 1/                 # one folder per exercise (index.c)
│   ├── 2/                 # sub-exercises split as 1.c, 2.c, …
│   ├── 3/
│   └── 8/
└── 📁 mooshak/            # Solutions to the Mooshak online judge
    └── exercises/         # one folder per problem (index.c + sample I/O)
```

Compiled binaries (`index.out`, `*.out`) and sample input files (`*.txt`) are kept
alongside each source for quick local testing.

## 📝 Sheets

Selected classroom sheets. Coverage is partial — only the sheets worked through are included.

| Sheet | Topic                          | Description                                                                 |
| ----- | ------------------------------ | --------------------------------------------------------------------------- |
| 1     | Loops & Output                 | Print odd numbers and their sum; draw an `n × n` checkerboard pattern        |
| 2     | Patterns & Geometry            | Staircase/triangle patterns; box volume; quadratic equation solver (`math.h`) |
| 3     | Stream Processing & Simulation | Character-by-character input until EOF (digit/word counting); a grid animation |
| 8     | Functions, Assertions & Data   | GCD, min/max-of-3, string→integer parsing, char removal, structs, sorted insertion (using `assert`) |

## ⚖️ Mooshak

`mooshak/exercises/` holds **52 solved problems** from [Mooshak](https://mooshak.dcc.fc.up.pt/),
the online judge used to grade the course. Problems are numbered to match the judge's
problem set. Each folder contains:

- `index.c` — the accepted solution (a few problems split parts into `1.c` / `2.c`)
- `*.txt` — sample input cases used to test the program locally
- `index.out` — the locally compiled binary

## 🔗 Resources

- [Course Page](https://www.dcc.fc.up.pt/~fds/aulas/pi/2526/) — Lecture notes, exercise sheets, and announcements
- [C Programming: A Modern Approach](https://www.amazon.com/C-Programming-Modern-Approach-2nd/dp/0393979504) — K. N. King, 2nd edition (2008)
- [Learn-C.org](https://www.learn-c.org/) — Interactive C tutorial
- [W3Schools C Tutorial](https://www.w3schools.com/c/) — C programming reference and examples
- [Programiz C Programming](https://www.programiz.com/c-programming/getting-started) — Getting started with C
