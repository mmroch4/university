# λ Functional Programming

> Course materials for **Functional Programming** (Haskell) at [FCUP](https://www.fc.up.pt/) — 1st year, 2nd semester.

[![Haskell](https://img.shields.io/badge/Haskell-5D4F85?style=for-the-badge&logo=haskell&logoColor=white)](https://www.haskell.org/)

## 📂 Directory Structure

```txt
functional-programming/
└── 📁 sheets/           # Exercise sheets
    ├── 1/
    ├── 2/
    └── 3/
```

## 📝 Sheets

| Sheet | Topic                    | Exercises | Description                                                       |
| ----- | ------------------------ | --------- | ----------------------------------------------------------------- |
| 1     | Types, Functions & Lists         | 13        | Basic functions, list operations, type inference, and polymorphism       |
| 2     | Guards, Patterns & Recursion     | 8         | Guards, pattern matching, `where` clauses, tuples, and recursion        |
| 3     | List Comprehensions              | 10        | List comprehensions, number theory, tuples, and password validation     |

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

## 🔗 Resources

- [CIS 194: Introduction to Haskell](https://www.cis.upenn.edu/~cis1940/fall16/) — University of Pennsylvania course
- [Haskell Beginners 2022 Course Plan](https://github.com/haskell-beginners-2022/course-plan) — Structured beginner course on GitHub
- [Introduction to Functional Programming](https://ocw.tudelft.nl/courses/introduction-to-functional-programming/) — TU Delft OpenCourseWare
- [The Craft of Functional Programming](https://simonjohnthompson.github.io/craft3e/craft3e.pdf) — Simon Thompson (PDF)
