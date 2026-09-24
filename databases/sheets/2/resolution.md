# Ficha 2 - Modelo ER

## 1

**3, 6, 8, 11, 12**

- 3 - Roberto Antunes nasceu a 17-12-1980, logo tem 45 anos (ainda não fez 46).
- 6 - `Morada` é composto; "Porto" é um valor simples.
- 8 - `93X93Y93Z` não é um número de telefone válido.
- 11 - `Ano` não é opcional (não tem `?`), logo não pode ser `NULL`.
- 12 - Maria Carvalho e Maria Silveira têm o mesmo `NumMec` (chave duplicada).

Não são problemas:

- 1, 2, 4 - as idades estão corretas.
- 5 - `Andar?` é opcional, logo `NULL` é válido.
- 7, 9, 10 - `{NumTelefone}` e `{Habilitação}` são multivalor, sem mínimo nem máximo.
- 13 - telefone e morada não são chave.

## 2

### 2.1

See ./diagrams/1.er -> ./diagrams/out/1.png

### 2.2

See ./diagrams/1.er -> ./diagrams/out/1.png

| Relacionamento | Cardinalidade | Participação |
| --- | --- | --- |
| WORK_AT (Funcionário-Espaço) | N:1 | total em ambos |
| MANAGE (Funcionário-Espaço) | 1:1 | parcial no funcionário, total no espaço |
| SUPERVISE (Funcionário-Funcionário) | 1:N | parcial em ambos |
| HOSTS (Espaço-Evento) | M:N | parcial no espaço, total no evento |

## 3

See ./diagrams/2.er -> ./diagrams/out/2.png

## 4

### 4.1

See ./diagrams/3.er -> ./diagrams/out/3.png

### 4.2

See ./diagrams/1.er -> ./diagrams/out/1.png

### 4.3

See ./diagrams/2.er -> ./diagrams/out/2.png

## 5

See ./diagrams/4.er -> ./diagrams/out/4.png
