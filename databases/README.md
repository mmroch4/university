# 🗄️ Databases

> Course materials for **Databases** (Bases de Dados, CC2005 — data modeling, the Entity-Relationship model) at [FCUP](https://www.fc.up.pt/).

[![dbdia](https://img.shields.io/badge/dbdia-ER%20diagrams-blue?style=for-the-badge)](https://github.com/edrdo/dbdia)

## ℹ️ Overview

| Field | Value |
| --- | --- |
| Year | 2nd |
| Semester | 1st |
| Academic year | 2026/2027 |
| Language / Tools | ER model (dbdia) |
| Status | 🔄 Ongoing |

## 📂 Directory Structure

```txt
databases/
├── 📁 sheets/           # Practical class sheets
│   ├── 1/               # Data consistency (sheet.pdf + resolution.md)
│   └── 2/               # ER model (sheet.pdf, resolution.md, diagrams/)
│       └── diagrams/    # dbdia sources (.er) and generated images (out/*.png)
├── 📁 dbdia/            # dbdia tool (ER / relational diagram generator)
└── 📄 dbdia.sh          # Helper script to generate diagrams
```

## 📝 Sheets

| Sheet | Topic                          | Exercises | Description                                                                          |
| ----- | ------------------------------ | --------- | ------------------------------------------------------------------------------------ |
| 1     | Data Consistency               | 4         | Interpreting requirements and checking tabular data against them (keys, `NULL`, references) |
| 2     | Entity-Relationship (ER) Model | 5         | Entity types, attribute kinds, relationships, cardinality, participation, weak entities   |

### Sheet 1 — Data Consistency

Each exercise checks whether a set of tables is consistent with a set of requirements for a fictional faculty (teachers, departments, courses, subjects). Answers are in `sheets/1/resolution.md`.

| Exercise | Description                                                                                           |
| -------- | ----------------------------------------------------------------------------------------------------- |
| 1        | Find what is wrong in a `DOCENTE` table (repeated ids, missing mandatory email, invalid phone)       |
| 2        | True/false statements about departments, courses and subjects against the requirements (2.1–2.3)    |
| 3        | Read `DOCENTE` / `DEPARTAMENTO` data (3.1) and detect inconsistencies caused by updates, inserts and deletes (3.2) |
| 4        | Query the course/subject tables (4.1) and decide whether changes keep the database consistent (4.2) |

> **Note:** `DOCENTE.Departamento` and `DEPARTAMENTO.Presidente` reference each other, so a new department and its first teacher cannot be inserted one before the other. This circular dependency was not intended by the sheet.

### Sheet 2 — Entity-Relationship (ER) Model

Introduction to the ER model in its textual and visual syntax. Diagrams are written in the [dbdia](https://github.com/edrdo/dbdia) DSL (`sheets/2/diagrams/*.er`) and rendered to `sheets/2/diagrams/out/*.png`.

| Exercise | Diagram        | Description                                                                                                  |
| -------- | -------------- | ------------------------------------------------------------------------------------------------------------ |
| 1        | —              | Spot the data that disagrees with the `ALUNO` entity type (keys, composite, multivalued, optional, derived attributes) |
| 2.1      | `1.er`         | Event company: `EMPLOYEE`, `VENUE` and `EVENT` entity types with key and attribute classification            |
| 2.2      | `1.er`         | Relationships `WORK_AT`, `MANAGE`, `SUPERVISE` and `HOSTS` with cardinality and participation                |
| 3        | `2.er`         | Social network ("Livro das Caras"): users, follows, posts, likes, and comments as a weak entity of posts     |
| 4.1      | `3.er`         | dbdia diagram for the `ALUNO` entity type                                                                    |
| 4.2      | `1.er`         | dbdia version of exercise 2                                                                                  |
| 4.3      | `2.er`         | dbdia version of exercise 3                                                                                  |
| 5        | `4.er`         | Online document sharing: users, documents, links, sharing with access level, and versions as a weak entity   |

## 🛠️ Usage

From the `databases/` folder (requires Java and [Graphviz](https://graphviz.org)):

```bash
./dbdia.sh sheets/2/diagrams/1.er   # writes sheets/2/diagrams/out/1.png
```

## 🔗 Resources

- [dbdia](https://github.com/edrdo/dbdia) — ER / relational diagram generator by Eduardo R. B. Marques (bundled in `dbdia/`)
- [dbdia DSL reference](https://github.com/edrdo/dbdia/blob/master/DSL.md#er-models) — syntax for ER models
- [Fundamentals of Database Systems](https://www.pearson.com/us/higher-education/program/Elmasri-Fundamentals-of-Database-Systems-7th-Edition/PGM189052.html) — Elmasri & Navathe
