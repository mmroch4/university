# Ficha 1

## 1 

- Os id's repetem-se.
- Email NULL
- Telefone não é um número (apesar de não haver restriçao quanto à família de caracteres da oluna telefone, não é coerente o valor registrado)

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
- Presidente: António das Coisas
- Docentes: António das Coisas


CC:
- Presidente: Alípio Jorge
- Docentes: Alípio Jorge, Eduardo Marques

F:
- Presidente: Eduardo Marques
- Docentes: Fátima Lopes, Eduardo Marques

### 3.2

1. Não existe esse docente
2. O Eduardo Marques não pertence ao Departamento de Física
3. O Departamento CC fica sem Presidente
4. Docentes ficarão sem Departamentos
5. O Departamento não existe
6. já existe docente com esse  numero mecanografico

## 4

### 4.1

1. CO: LC | CC: LCC, MIERS (mais que um curso) | F: LF, LC (mais que um curso). Cursos com mais que um departamento responsável: LC
2. BD: Alípio Jorge, Eduardo Marques | F1: Fátima Lopes | SC: António das Coisas
3. LC: Física I, Sociologia das Coisas

### 4.2

1. Não, o docente não faz parte do Departamento de Física
2. Não, fica a entrada duplicada
3. Sim, pode pois ele pertence ao departamento de fisica
4. sim, pode
5. nao pois os docentes daquela cadeira nao pertecem ao departamento de fisica
6. sim, pode
7. sim, pode
8. nao, a cadeira fica sem docentes associados
9. nao, a cadeira fica sem cursos associados

## Observação

O diagrama tem uma dependência circular entre DOCENTE e DEPARTAMENTO:

- `DOCENTE.Departamento` referencia `DEPARTAMENTO.Código` (o departamento tem de existir antes do docente);
- `DEPARTAMENTO.Presidente` referencia `DOCENTE.Nº Mec.` (o presidente tem de existir antes do departamento).

Assim, não é possível criar um novo departamento com um novo docente, pois nenhuma das duas entradas pode ser inserida primeiro. Este problema não era pretendido no enunciado.

