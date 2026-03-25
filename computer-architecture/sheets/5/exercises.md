# Folha 5 - Programação em Asembly do MIPS R2000

# 1.

## a)

```asm
add $s0, $s1, $s2
add $s0, $s3, $s0
```

->

```c
f = g + h;
f = f + i;
```

## b)

```asm
sll $t0, $s0, 2
add $t0, $s6, $t0
lw $t1, 0($t0)
lw $t2, 4($t0)
add $t0, $t1, $t2
sll $t1, $s1, 2
add $t1, $s7, $t1
sw $t0, 0($t1)
```

->

```c
f << 2 // Isto é feito internamente pelo compilador
g << 2 // Isto é feito internamente pelo compilador

B[g] = A[f] + A[f + 1]
```

## c)

```asm
li $t2, 100
move $t1, $s6
li $s3, 0
loop:
lw $t0, 0($t1)
add $s0, $s0, $t0
addi $t1, $t1, 4
addi $s3, $s3, 1
blt $s3, $t2, loop
```

->

```c
t1 = &A

i = 0;

while (i < 100) {
    f = f + (*t1);

    t1 = t1 + 1;

    i = i + 1;
}
```

# 2.

## a) 

```c
h = A[0] << 4;
```

->

```asm
lw $t0, 0($s6)
sll $t0, $t0, 4
mv $s2, $t0
```

## b) 

```c
B[8] = A[i - j];
```

->

```asm
sub $t0, $s3, $s4
sll $t0, $t0, 2
add $t0, $t0, $s6
lw $t1, 0($t0)

li $t0, 8
sll $t0, $t0, 2
add $t0, $t0, $s7

sw $t1, 0($t0)
```

## c) 

```c
B[8] = A[i] + A[j];
```

->

```asm
sll $t0, $s3, 2
add $t0, $t0, $s6
lw $t1, 0($t0)


sll $t0, $s4, 2
add $t0, $t0, $s6
lw $t2, 0($t0)

add $t0, $t1, $t2

sw $t0, 32($s7)
```

## d)

```c
f = A[B[g] + 1]
```

->

```asm
sll $t0, $s1, 2
add $t0, $t0, $s7
lw $t1, 0($t0)

sll $t1, $t1, 2
add $t1, $t1, 4

add $t1, $t1, $s6

lw $s0, 0($t1)
```

# 3.

```asm
        .data
_msg1:  .asciiz "The result is "
_msg2:  .asciiz "\n"
        .text
_main:
        li $s0, 0
        li $s1, 100
        li $s2, 0
_loop:
        bge $s0, $s1, _end // while s0 (0) < s1 (100) 
        mul $t0, $s0, $s0 // t0 = s0 * s0
        add $s2, $s2, $t0 // s2 = s2 + t0
        addiu $s0, $s0, 1 // s0 = so + 1
        j _loop
_end:
        li $v0, 4
        la $a0, _msg1
        syscall
        li $v0, 1
        move $a0, $s2
        syscall
        li $v0, 4
        la $a0, _msg2
        syscall
        li $v0, 10
        syscall
```

->

```txt
Output:
The result is 338350
```

# 4.

```asm
        .data
_str:   .asciiz "abracadabra"
_msg1:  .asciiz "The result is "
_msg2:  .asciiz "\n"
        .text
_main:
        la $a0, _str
        jal _proc
        move $s0, $v0 // tamanho da _str 
        li $v0, 4
        la $a0, _msg1
        syscall
        li $v0, 1
        move $a0, $s0
        syscall
        li $v0, 4
        la $a0, _msg2
        syscall
        li $v0, 10
        syscall
_proc:
        li $v0, 0
_loop:
        lb $t0, 0($a0)
        beqz $t0, _end
        addiu $v0, $v0, 1
        addiu $a0, $a0, 1
        j _loop
_end:
        jr $ra
```

->

```txt
Output: The result is 11
```

# 5.

## a)

```asm
not $t1, $t2
```

-> 

```asm
li $t0, 0xFFFFFFFF
xori $t1, $t2, $t0
```

## b)

```asm
bge $t1, $t2, label
```

-> 

```asm
slt $t0, $t1, $t2
beq $t0, $zero. label
```

# 6.

## a)

```asm
li  $t0, 0xAAAAAAAA
li  $t1, 0x12345678
sll $t0, $t0, 4
or  $t2, $t0, $t1
```

->

```txt
$t2 = 0xBABEFEF8
```

## b)

```asm
li    $t0, 0xAAAAAAAA
sll   $t1, $t0, 4
andi  $t2, $t1, -1
```

->

```txt
$t2 = 0x0000AAA0
```

## c)

```asm
li    $t0, 0xAAAAAAAA
srl   $t1, $t0, 3
andi  $t2, $t1, 0xFFEF
```

->

```txt
$t2 = 0x00005545
```

## d)

```asm
li  $t0, 0x10010000
li  $t1, 0x11223344
sw  $t1, 0($t0)
lbu $t2, 0($t0)
```

->

```txt
$t2 = 0x11
```
