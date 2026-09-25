# 🌳 Data Structures

> Course materials for **Data Structures** (Java — exercise sheets and Mooshak problems) at [FCUP](https://www.fc.up.pt/).

[![Course Page](https://img.shields.io/badge/Course-Material-blue?style=for-the-badge)](https://www.dcc.fc.up.pt/~fds/aulas/EDados/2627/)
[![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)](https://www.java.com/)

## ℹ️ Overview

| Field            | Value      |
| ---------------- | ---------- |
| Year             | 2nd        |
| Semester         | 1st        |
| Academic year    | 2026/2027  |
| Language / Tools | Java       |
| Status           | 🔄 Ongoing |

## 📂 Directory Structure

```txt
data-structures/
├── 📁 mooshak/          # Mooshak problems (Class 2 — I/O with Scanner)
│   ├── 120/             # main.java
│   ├── 121/             # main.java, sample inputs
│   ├── 183/             # main.java, sample inputs
│   ├── 243/             # main.java, sample inputs
│   └── 244/             # main.java, naive.java, sample inputs
└── 📁 sheets/           # Exercise sheets
    └── 1/               # Sheet 1 — Introduction to Java (Main.java)
```

## 📝 Sheets

| Sheet | Topic                                     | Language | Status      |
| ----- | ----------------------------------------- | -------- | ----------- |
| 1     | Introduction to Java (Introdução ao Java) | Java     | In Progress |

> **Note:** Sheet 1 only has a `Main.java` skeleton (empty `main`) so far.

## ⚖️ Mooshak

`mooshak/` holds the problems solved on [Mooshak](https://mooshak.dcc.fc.up.pt/~edados/), the online judge used in the course, from practical class 2 (*I/O com a classe Scanner*). They are numbered to match the judge's problem set. Each folder contains `main.java` (the solution) and, for most problems, `*.txt` sample inputs used to test locally.

| Problem | Idea                                                                                                   | Language |
| ------- | ------------------------------------------------------------------------------------------------------ | -------- |
| 120     | Print an `N × N` diamond of `#` on a `.` background                                                     | Java     |
| 121     | Check whether each of `N` lines is a palindrome, ignoring case and non-letters (`sim` / `nao`)         | Java     |
| 183     | Read `N` numbers and print their average (2 decimal places) and the range (`max - min`)                | Java     |
| 243     | Count how many dishes can be ordered, given a set of banned ingredients (`HashSet` lookup)             | Java     |
| 244     | Count the primes in `[A, B]` with a sieve of Eratosthenes (`naive.java` is a trial-division reference) | Java     |

> **Note:** The problem statements are not in the repo, so the descriptions above are inferred from the code and sample inputs.

## 🛠️ Usage

```bash
# Sheets
cd sheets/1
javac Main.java
java Main

# Mooshak problems
cd mooshak/121
javac main.java
java main < 1.txt
```

## 🔗 Resources

- [Course Page](https://www.dcc.fc.up.pt/~fds/aulas/EDados/2627/): lecture summaries, slides, practical classes and schedules
- [Mooshak](https://mooshak.dcc.fc.up.pt/~edados/): the course's online judge
- [Introduction to Programming in Java](http://www.cs.princeton.edu/introcs/home/): Princeton's Java tutorial, recommended on the course page
- [Building Java Programs](http://www.buildingjavaprograms.com/) and [Practice-It!](http://practiceit.cs.washington.edu/): book and practice system recommended on the course page
