# λ Functional Programming

> Course materials for **Functional Programming** (Haskell — sheets and past tests) at [FCUP](https://www.fc.up.pt/).

[![Haskell](https://img.shields.io/badge/Haskell-5D4F85?style=for-the-badge&logo=haskell&logoColor=white)](https://www.haskell.org/)

## ℹ️ Overview

| Field | Value |
| --- | --- |
| Year | 1st |
| Semester | 2nd |
| Academic year | 2025/2026 |
| Language / Tools | Haskell |
| Status | ✅ Completed |

## 📂 Directory Structure

```txt
functional-programming/
├── 📁 sheets/           # Exercise sheets
│   ├── 1/
│   ├── 2/
│   ├── 3/
│   ├── 4/
│   ├── 5/
│   └── 6/
└── 📁 tests/            # Past test papers
    └── 2024-2025/
```

## 📝 Sheets

| Sheet | Topic                    | Exercises | Description                                                       |
| ----- | ------------------------ | --------- | ----------------------------------------------------------------- |
| 1     | Types, Functions & Lists         | 13        | Basic functions, list operations, type inference, and polymorphism       |
| 2     | Guards, Patterns & Recursion     | 8         | Guards, pattern matching, `where` clauses, tuples, and recursion        |
| 3     | List Comprehensions              | 10        | List comprehensions, number theory, tuples, and password validation     |
| 4     | Recursion & Algorithms           | 19        | Recursive functions, base conversions, sorting algorithms, and combinatorics |
| 5     | Higher-Order Functions           | 6         | `map`, `filter`, `foldr`/`foldl` — rebuilding list functions and sorts via folds |
| 6     | Infinite Lists & Laziness        | 5         | Lazy/infinite lists — Fibonacci, prefix sums, Pascal's triangle, string generation |

### Sheet 1 — Types, Functions & Lists

| Exercise | Description                                                                      |
| -------- | -------------------------------------------------------------------------------- |
| 2        | Triangle inequality validator                                                    |
| 3        | Triangle area using Heron's formula (`where` clause)                             |
| 4        | Split a list into two halves using `take` and `drop`                             |
| 5        | Custom `last` and `init` implementations (two approaches each)                   |
| 6        | Factorial and binomial coefficient (two implementations)                         |
| 7        | Determine types of expressions (lists, tuples, functions)                        |
| 8        | Infer function types from definitions                                            |
| 9        | Write type signatures for given function expressions                             |
| 10       | Define type-annotated functions (`second`, `swap`, `palindrome`, `twice`, etc.)  |
| 11       | Typed arithmetic functions (`inc`, `double`, `square`, `media`, `checkTriangle`) |
| 12       | Higher-order and type-class-constrained functions                                |
| 13       | Analyse polymorphic type `(a, [a]) -> Bool` with concrete applications           |
| 14       | Analyse polymorphic type `(a, [a]) -> a` with concrete applications              |

### Sheet 2 — Guards, Patterns & Recursion

| Exercise | Description                                                                   |
| -------- | ----------------------------------------------------------------------------- |
| 1        | `min3` and `max3` using guards and `min`/`max` (two approaches each)         |
| 2        | BMI classifier using guards and `where` clause                               |
| 3        | Median of three integers using guards                                        |
| 4        | XOR function using guards                                                    |
| 5        | `maxOccurs` (max + count) and `orderTriple` (sort a 3-tuple) using `where`  |
| 6        | `safetail` — three implementations (conditional, guards, pattern matching)   |
| 7        | `short` — check if list has at most 2 elements (two approaches)             |
| 8        | Number-to-words converter (integers up to 999 999) using string manipulation |

### Sheet 3 — List Comprehensions

| Exercise | Description                                                                      |
| -------- | -------------------------------------------------------------------------------- |
| 1        | Sum of squares from 1 to `n` using list comprehension                            |
| 2        | Two approximations of pi using Leibniz and Euler series                          |
| 3        | Proper divisors of an integer using list comprehension                           |
| 4        | Perfect numbers up to `n`                                                        |
| 5        | Primality test using list comprehension                                          |
| 6        | Pascal's triangle using binomial coefficients                                    |
| 7        | Dot product of two vectors using `zip`                                           |
| 8        | Pythagorean triples up to `n`                                                    |
| 9        | Password strength validator (length, lowercase, uppercase, digits)               |
| 10       | Integer power using list comprehension                                           |

### Sheet 4 — Recursion & Algorithms

| Exercise | Description                                                                       |
| -------- | --------------------------------------------------------------------------------- |
| 1        | Extract digits of an integer using power-of-10 decomposition                      |
| 2        | Decimal to binary conversion via powers of 2                                      |
| 3        | Binary to decimal conversion recursively                                          |
| 4        | Compute 2^n via simple recursion                                                  |
| 5        | Custom `replicate`, `(!!)`, and `elem` using recursion                            |
| 6        | Alternative `replicate` and `(!!)` using list comprehensions                      |
| 7        | Integer square root (`isqrt`) using iterative approximation                       |
| 8        | Factorial via range product recursion                                             |
| 9        | Euclidean GCD algorithm                                                           |
| 10       | Custom `nub` (duplicate removal) with helper `exists`                             |
| 11       | `intersperse` — insert separator between list elements                            |
| 12       | `maxFun` — find maximum function value over a range                               |
| 13       | `anyZero` — check if a function has a zero in a range                             |
| 14       | `sumFun` — sum function values over a range                                       |
| 15       | Insertion sort (`insert` and `isort`)                                             |
| 16       | Selection sort (`minimum`, `delete`, and `ssort`)                                 |
| 17       | Merge sort (`merge`, `half`, and `msort`)                                         |
| 18       | Generate all boolean vectors of length `n`                                        |
| 19       | Generate all permutations of a list                                               |

### Sheet 5 — Higher-Order Functions

| Exercise | Description                                                                  |
| -------- | ---------------------------------------------------------------------------- |
| 1        | Rewrite the comprehension `[f x \| x ← xs, p x]` using `map` and `filter`      |
| 2        | `(++)`, `concat`, and `reverse` implemented with `foldr`                      |
| 3        | `dec2int` — convert a digit list to an integer using `foldl`/`foldr`          |
| 4        | Custom `zipWith` via recursion                                                |
| 5        | Insertion sort built with `foldr` and `Data.List.insert`                      |
| 6        | `shift` and `rotate` (all rotations of a list) using `foldr`                  |

### Sheet 6 — Infinite Lists & Laziness

| Exercise | Description                                                              |
| -------- | ------------------------------------------------------------------------ |
| 1        | Infinite `factorial` and `fibonacci` lists via self-reference            |
| 2        | `merge` of two ordered lists (in progress)                               |
| 3        | `sums` — running prefix sums of a list                                   |
| 4        | Pascal's triangle as an infinite list of rows                            |
| 6        | `stringsN` — generate all strings of length `n` over the alphabet `a–z`  |

## 📄 Tests

| Academic Year | Contents                          |
| ------------- | --------------------------------- |
| 2024-2025     | Test #1 paper (`test.pdf`)        |

## 🔗 Resources

- [CIS 194: Introduction to Haskell](https://www.cis.upenn.edu/~cis1940/fall16/) — University of Pennsylvania course
- [Haskell Beginners 2022 Course Plan](https://github.com/haskell-beginners-2022/course-plan) — Structured beginner course on GitHub
- [Introduction to Functional Programming](https://ocw.tudelft.nl/courses/introduction-to-functional-programming/) — TU Delft OpenCourseWare
- [The Craft of Functional Programming](https://simonjohnthompson.github.io/craft3e/craft3e.pdf) — Simon Thompson (PDF)
