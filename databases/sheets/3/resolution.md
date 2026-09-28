# Ficha 3

## 1

### 1.1

ESPAÇO -> CodEspaço
FUNCIONÁRIO -> NumCC

### 1.2

ESPAÇO -> Gestor
FUNCIONÁRIO -> Supervisor e Espaço


### 1.3

- INSERE FUNCIONÁRIO(‘ABCDEF’, ‘Roberto Pires’, ‘CP’, 12345678,…) -> viola a integridade de domínio
- INSERE FUNCIONÁRIO(12345678, ‘Roberto Pires’, ‘CP’, 22444552,…) -> viola a integridade da chave
- INSERE FUNCIONÁRIO(23884312, ‘Roberto Pires’, ‘CP’, 12345679,…) -> viola a integridade referencial
- INSERE ESPAÇO(NULL,‘Null All Night’, …) -> viola a integridade de entidade
- REMOVE ESPAÇO(‘CP’) -> viola a integridade referencial
- REMOVE FUNCIONÁRIO(12345678) -> viola a integridade referencial
- REMOVE FUNCIONÁRIO(18923444) -> viola a integridade referencial
- ACTUALIZA FUNCIONÁRIO(22444552, Espaço → ‘XPTO’) -> viola a integridade referencial
- ACTUALIZA ESPAÇO(CP,Nome → NULL) -> viola a integridade de domínio
- ACTUALIZA ESPAÇO(TR,Gestor → 12345679) -> viola a integridade referencial

## 2

See ./diagrams/1.er -> ./diagrams/out/1.png

## 3

See ./diagrams/2.er -> ./diagrams/out/2.png

## 4

### 4.1

See ./diagrams/3.er -> ./diagrams/out/3.png

### 4.2

See ./diagrams/1.er -> ./diagrams/out/1.png

### 4.3

See ./diagrams/2.er -> ./diagrams/out/2.png
