# 🏆 Competitive Programming

> Course materials for **Competitive Programming** (CC3032 — Python, C++, C: class problems, contests, and practice exercises) at [FCUP](https://www.fc.up.pt/).

[![Course Page](https://img.shields.io/badge/Course-Material-blue?style=for-the-badge)](https://www.dcc.fc.up.pt/~pribeiro/aulas/pc2627/index.html)
[![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))

## ℹ️ Overview

| Field | Value |
| --- | --- |
| Year | 2nd |
| Semester | — |
| Academic year | 2025/2026 (extracurricular), 2026/2027 (enrolled) |
| Language / Tools | Python, C++, C |
| Status | 🔄 Ongoing |

> **Note:** In 2025/2026 I was **not officially enrolled**; I attended informally because I enjoyed the subject, so most of that content is incomplete.

## 📂 Directory Structure

```txt
competitive-programming/
├── 📁 2025-2026/
│   ├── 📁 classes/problems/   # Class problems
│   ├── 📁 contests/           # Contest submissions
│   └── 📁 tempo/              # Practice problems
└── 📁 2026-2027/
    ├── 📁 mooshak/            # Mooshak problems (1–13)
    └── 📁 codeforces/         # Codeforces problems (by problem id)
```

Inside each problem folder, `index.<ext>` is the solution and `1.txt`, `2.txt`, … (or `input-N.txt`) are sample inputs.

## 📅 2025/2026 (extracurricular)

### 📝 Exercises

| #  | Topic                             | Language | Status      |
| -- | --------------------------------- | -------- | ----------- |
| 38 | Flood Fill / Connected Components | Python   | In Progress |

### 🏅 Contests

#### Contest #1

| Problem | Language | Status      |
| ------- | -------- | ----------- |
| A       | Python   | Complete    |
| B       | Python   | Complete    |
| C       | Python   | Complete    |
| D       | Python   | In Progress |
| E       | Python   | In Progress |

### 🧩 Practice

| Problem         | Source                                                    | Language     | Status      |
| --------------- | --------------------------------------------------------- | ------------ | ----------- |
| independent-set | [AtCoder DP P](https://atcoder.jp/contests/dp/tasks/dp_p) | C++          | Complete    |
| partition       | —                                                         | C++          | In Progress |
| pokemon         | —                                                         | C++          | In Progress |
| removal-game    | [CSES 1097](https://cses.fi/alon/submit/1097/)            | C++ / Python | Complete    |

## 📅 2026/2027 (enrolled)

### ⚖️ Mooshak

| Problem | Idea                                                                                          | Language     |
| ------- | --------------------------------------------------------------------------------------------- | ------------ |
| 1       | Minimum number of moves to fix a sequence, summing the differences between adjacent values    | C++          |
| 2       | Check whether one string is a subsequence of another, over several test cases                 | C++          |
| 3       | Count the trailing zeros of `N!` by counting factors of 5 (with `helper.py` and `checker.py` used to explore and verify the idea) | C++ / Python |
| 4       | Minimum removals so that every remaining value `x` appears exactly `x` times (sort and count runs) | C++          |
| 5       | Count the students enrolled in the most popular combination(s) of 5 courses (sorted combination as a `map` key) | C++          |
| 6       | Longest contiguous run of distinct values, with a sliding window and a `map` of last occurrences | C++          |
| 7       | Simulate a battle between two armies over `B` battlefields per round, strongest against strongest, and print the winner and its survivors (`map` as a counted multiset) | C++          |
| 8       | Longest stretch of street without a traffic light after each light is added (`set` of positions and a `map` counting gap lengths) | C++          |
| 9       | Minimum cost to make every window of size `K` equal, tracking the median with two `multiset`s and their running sums | C++          |
| 10      | Give each customer the most expensive ticket not above their maximum price (`multiset` with `lower_bound`) | C++          |
| 11      | Sort numbers by number of set bits (descending), breaking ties by smaller value first          | C++          |
| 12      | Given `N` machines and a target `T`: reads and sorts the machine times                         | C++          |
| 13      | Share `N` circular pies among `F + 1` people: computes each area and the average share         | C++          |

> **Note:** Problems 12 and 13 are still in progress: 12 only reads and sorts the input, and 13 only prints intermediate values. The problem statements are not in the repo, so the descriptions above are inferred from the code and sample inputs.

### 🌐 Codeforces

| Problem                                                            | Language |
| ------------------------------------------------------------------ | -------- |
| [1627A — Not Shading](https://codeforces.com/problemset/problem/1627/A)        | C / C++  |
| [2118B — Make It Permutation](https://codeforces.com/problemset/problem/2118/B) | C++      |

## 🔗 Resources

- [Course Page 2026/2027](https://www.dcc.fc.up.pt/~pribeiro/aulas/pc2627/index.html) — Evaluation, class schedule, rankings, and study materials (current edition)
- [Course Page 2025/2026](https://www.dcc.fc.up.pt/~pribeiro/aulas/pc2526/) — Lecture notes, exercises, and announcements (previous edition)
