# Folha 7 - Programação em Asembly do MIPS R2000 (III)

# 1.

```c
int fib(int n) {
  if (n < 2)
    return n;
  else
    return fib(n - 1) + fib(n - 2);
}
int main() {
  int i;
  scanf("%d", &i);
  printf("fib(%d) = %d\n", i, fib(i));
  return 0;
}
```

-->

```asm
.data
_output_text_1:
	.asciiz "fib("
_output_text_2:
	.asciiz ") = "
_endl:
	.asciiz "\n"
	.text
_main:
	li $v0, 5
	syscall
	
	move $s0, $v0 # s0 = input()
	
	move $a0, $s0 # s1 = fib(i)
	jal _fib
	move $s1, $v0
	
_print:	
	la $t0, _output_text_1
	move $a0, $t0
	li $v0, 4 # print string
	syscall
	
	move $a0, $s0
	li $v0, 1 # print i
	syscall	
	
	la $t0, _output_text_2
	move $a0, $t0
	li $v0, 4 # print string
	syscall
	
	
	move $a0, $s1
	li $v0, 1 # print fib(i)
	syscall	
	
	la $t0, _endl
	move $a0, $t0
	li $v0, 4 # print string
	syscall
_exit:
	li $v0, 10
	syscall

_fib:
	move $t0, $a0
	
	bge $t0, 2, _fib_else
	move $v0, $t0
	j _fib_end
_fib_else:
	sub $sp, $sp, 12
	sw $ra, 0($sp)
	sw $t0, 4($sp)

	sub $t1, $t0, 1
	move $a0, $t1
	jal _fib
	move $t1, $v0
	
	lw $ra, 0($sp)
	lw $t0, 4($sp)
	sw $t1, 8($sp)
	
	
	sub $t2, $t0, 2
	move $a0, $t2
	jal _fib
	move $t2, $v0
	
	lw $ra, 0($sp)
	lw $t0, 4($sp)
	lw $t1, 8($sp)
	
	add $t3, $t1, $t2
	move $v0, $t3
	
	lw $ra, 0($sp)
	add $sp, $sp, 12
	
_fib_end:
	jr $ra
```

# 2.

```c
int memFibs[1024] = {0, 1, 1};
int fib(int n) {
  if (memFibs[n] == 0)
    memFibs[n] = fib(n - 1) + fib(n - 2);
  return memFibs[n];
}
int main() {
  int i;
  scanf("%d", &i);
  printf("fib(%d) = %d\n", i, fib(i));
  return 0;
}
```

-->

```asm
.data
_memFibs:
	.word 0:1024
_output_text_1:
	.asciiz "fib("
_output_text_2:
	.asciiz ") = "
_endl:
	.asciiz "\n"
	.text
_main:
	la $s3, _memFibs
	
	# initialize memFib
	li $s0, 0 
	sw $s0, 0($s3)
	li $s0, 1
	sw $s0, 4($s3)	
	li $s0, 1
	sw $s0, 8($s3)

	li $v0, 5
	syscall
	move $s0, $v0 # s0 = i
	
	move $a0, $s0
	move $a1, $s3
	jal _fib
	move $s1, $v0 # s1 = fib(i)

_prints:
	la $t0, _output_text_1
	move $a0, $t0
	li $v0, 4
	syscall
	
	move $a0, $s0
	li $v0, 1
	syscall
	
	la $t0, _output_text_2
	move $a0, $t0
	li $v0, 4
	syscall
	
	move $a0, $s1
	li $v0, 1
	syscall
	
	la $t0, _endl
	move $a0, $t0
	li $v0, 4
	syscall
_exit:
	li $v0, 10
	syscall

_fib:
	sub $sp, $sp, 36
	sw $t0, 0($sp)
	sw $t1, 4($sp)
	sw $t2, 8($sp)
	sw $t3, 12($sp)
	sw $t4, 16($sp)
	sw $t5, 20($sp)
	sw $t6, 24($sp)
	sw $t7, 28($sp)
	sw $ra, 32($sp)
		
	move $t0, $a0 # t0 = n
	move $t7, $a1 # t1 = memFibs
	
	sll $t4, $t0, 2
	add $t4, $t7, $t4 # t4 = memFibs + n
	
	lw $t3, 0($t4) # memFibs[n]
	seq $t5, $t3, 0 # memFibs[n] == 0
	seq $t6, $t0, 0 # n == 0
	
	not $t6, $t6 # n != 0
	and $t5, $t5, $t6 # memFibs[n] == 0 && n != 0
	
	beq $t5, 1, _fib_else
	move $v0, $t3
	j _fib_end
_fib_else:	
	sub $t1, $t0, 1
	move $a0, $t1
	move $a1, $t7
	jal _fib # fib(n - 1)
	
	move $t1, $v0

	sub $t2, $t0, 2
	move $a0, $t2
	move $a1, $t7
	jal _fib # fib(n - 1)
	
	move $t2, $v0
	
	add $t2, $t2, $t1
	
	sw $t2, 0($t4)
	move $v0, $t2
_fib_end:
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	lw $t3, 12($sp)
	lw $t4, 16($sp)
	lw $t5, 20($sp)
	lw $t6, 24($sp)
	lw $t7, 28($sp)
	lw $ra, 32($sp)
	add $sp, $sp, 36

	jr $ra
```
