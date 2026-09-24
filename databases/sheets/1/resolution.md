# Sheet 1

## 1

- The ids are repeated.
- Email is NULL.
- The phone is not a number (although there is no restriction on the character set of the phone column, the recorded value is not coherent).

## 2

### 2.1

1. False
2. True
3. True
4. False
5. False
6. False
7. False

### 2.2

1. False
2. True
3. True

### 2.3

1. False
2. False
3. True
4. True
5. False
6. True

## 3

### 3.1

CO:
- President: António das Cenas
- Teachers: António das Cenas

CC:
- President: Alípio Jorge
- Teachers: Alípio Jorge, Eduardo Marques

F:
- President: Eduardo Marques
- Teachers: Fátima Lopes, Eduardo Marques

### 3.2

1. That teacher does not exist
2. Eduardo Marques does not belong to the Physics Department
3. The CC Department is left without a President
4. Teachers would be left without Departments
5. The Department does not exist
6. A teacher with that employee number already exists

## 4

### 4.1

1. CO: LC | CC: LCC, MIERSI (more than one course) | F: LF, LC (more than one course). Courses with more than one responsible department: LC
2. BD: Alípio Jorge, Eduardo Marques | F1: Fátima Lopes | SC: António das Cenas
3. LC: Física I, Sociologia das Coisas

### 4.2

1. No, the teacher is not part of the Physics Department
2. No, the entry would be duplicated
3. Yes, it can, since he belongs to the Physics Department
4. Yes, it can
5. No, since the teachers of that subject do not belong to the Physics Department
6. Yes, it can
7. Yes, it can
8. No, the subject is left without associated teachers
9. No, the subject is left without associated courses

## Note

The diagram has a circular dependency between DOCENTE and DEPARTAMENTO:

- `DOCENTE.Departamento` references `DEPARTAMENTO.Código` (the department must exist before the teacher);
- `DEPARTAMENTO.Presidente` references `DOCENTE.Nº Mec.` (the president must exist before the department).

Therefore, it is not possible to create a new department together with a new teacher, since neither entry can be inserted first. This problem was not intended by the sheet.
