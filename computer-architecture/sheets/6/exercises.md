# Folha 6 - Programação em Asembly do MIPS R2000 (II)

# 1.

```c
int main() {
    int i, upTo, sum;
    scanf("%d", &upTo);
    sum = 0;
    for (i = 0; i < upTo ; i++) {
        sum += i * i;
    }
    printf("The result is %d\n", sum);
    return 0;
}
```

->

```asm
          .data
_rl:      .asciiz "The result is "
_endl:    .asciiz "\n"
          .text
          li $s0, 0
          li $s1, 0
          li $v0, 5
          syscall
          mv $s2, $v0
_loop:
          bge $s0, $s2, _endloop
          mul $t0, $s0, $s0
          add $s1, $s1, $t0
          addi $s0, $s0, 1
          j _loop
_endloop:
          li $v0, 4
          la $a0, _rl
          syscall
          li $v0, 1
          mv $a0, $s2
          syscall
          li $v0, 4
          la $a0, _endl
          syscall
          li $v0, 10
          syscall
```

# 2.

```c
int squares[100];
int main() {
    int i, upTo;
    scanf("%d", &upTo);
    for (i = 0; i < upTo ; i++)
    squares[i] = i * i;
    return 0;
}
```

->

```asm
            .data
_squares:   .word 0:100
            .text
            li $s0, 0
            li $v0, 5
            syscall
            mv $s1, $v0
_loop:      bge $s0, $s1, _endloop
            la $t1, _squares
            sll $t2, $s0, 2
            add $t1, $t1, $t2
            mul $t0, $s0, $s0
            sw $t0, 0($t1)
            addi $s0, $s0, 1
            j _loop
_endloop:   li $v0, 10
            syscall
```

# 3.

```c
int squares[100];

void storeValues(int n) {
    int i;
    for (i = 0; i < n; i++)
    squares[i] = i * i;
    return;
}

int computeSum(int n) {
    int i, sum;
    sum = 0;
    for (i = 0; i < n; i++)
    sum += squares[i];
    return sum;
}

int main() {
    int upTo;
    scanf("%d", &upTo);
    storeValues(upTo);
    printf("The result is %d\n", computeSum(upTo));
    return 0;
}
```

->

```asm
    .data
_squares:
	  .word 0:100
_message:
	  .asciiz "The result is "
_endl:
	  .asciiz "\n"
		.text
_main:
	  li $v0, 5
		syscall
    move $s0, $v0
    move $s1, $zero
    la $s2, _squares

    move $a0, $s0
    move $a1, $s2
    jal _fn_sv

		jal _fn_cs
		move $s1, $v0

_print:
	  li $v0, 4
    la $a0, _message
    syscall
    li $v0, 1
    move $a0, $s1
    syscall
    li $v0, 4
    la $a0, _endl
    syscall
_exit:
	  li $v0, 10
_main_end:
	  syscall

_fn_sv:
	  move $t0, $a0
			move $t1, $a1

	  li $t2, 0

_fn_sv_loop:
	  beq $t2, $t0, _fn_sv_loop_end
		sll $t3, $t2, 2
		add $t4, $t1, $t3
		mul $t5, $t2, $t2
		sw $t5, 0($t4)
		addi $t2, $t2, 1
		j _fn_sv_loop
_fn_sv_loop_end:

_fn_sv_end:
	  jr $ra

_fn_cs:
    move $t0, $a0
    move $t3, $a1
    li $t1, 0
    li $t2, 0
_fn_cs_loop:
    beq $t2, $t0, _fn_cs_loop_end
    sll $t4, $t2, 2
    add $t5, $t3, $t4
   	lw $t6, 0($t5)
   	add $t1, $t1, $t6
    addi $t2, $t2, 1
    j _fn_cs_loop
_fn_cs_loop_end:
    move $v0, $t1
_fn_cs_end:
	  jr $ra
```

# 4.

```c
#include <stdio.h>

char text[] = "This is the string to be used to generate the histogram";
int histogram[26] = {0};

void computeHistogram() {
  int i = 0;
  while (text[i] != '\0') {
    if (text[i] >= 'A' && text[i] <= 'Z')
      histogram[text[i] - 65]++;
    if (text[i] >= 'a' && text[i] <= 'z')
      histogram[text[i] - 97]++;
    i++;
  }
  return;
}

void printHistogram() {
  int i;
  for (i = 0; i < 26; i++)
    printf("%c -> %d\n", i + 97, histogram[i]);
  return;
}
int main() {
  computeHistogram();
  printHistogram();
  return 0;
}
```

--> 

```asm
.data
_text:
	.asciiz "This is the string to be used to generate the histogram"
_histogram:
	.word 0:26
_divider:
	.asciiz " -> "
_endl:
	.asciiz "\n"

	.text
_main:
	jal _fn_compute_histogram
	jal _fn_print_histogram
_exit:
	li $v0, 10 
	syscall

_fn_compute_histogram:
	li $t0, 0 # i = 0
	la $t1, _text # arr text
_fn_compute_histogram_loop:
	add $t2, $t1, $t0 # pointer text + i
	lb $t3, 0($t2) # *(text + i)
	beq $t3, $zero, _fn_compute_histogram_loop_end
	li $t6, 0
_if_1:
	sge $t4, $t3, 65
	sle $t5, $t3, 90
	and $t4, $t4, $t5
	bne $t4, 1, _if_1_end
	sub $t3, $t3, 65
	li $t6, 1	
_if_1_end:

_if_2:
	sge $t4, $t3, 97
	sle $t5, $t3, 122
	and $t4, $t4, $t5	
	bne $t4, 1, _if_2_end
	sub $t3, $t3, 97
	li $t6, 1
_if_2_end:

_if_3:
	bne $t6, 1, _if_3_end
	sll $t3, $t3, 2
	la $t4, _histogram
	add $t4, $t4, $t3
	lw $t5, 0($t4)
	addiu $t5, $t5, 1
	sw $t5, 0($t4)
_if_3_end:

	addiu $t0, $t0, 1
	j _fn_compute_histogram_loop
_fn_compute_histogram_loop_end:
	
_fn_compute_histogram_end:
	jr $ra


_fn_print_histogram:
	li $t0, 0 # i = 0
	la $t1, _histogram
_fn_print_histogram_loop:
	beq $t0, 26, _fn_print_histogram_loop_end
	sll $t2, $t0, 2
	add $t3, $t1, $t2
	lw $t3, 0($t3)
	addiu $t4, $t0, 97
	
	move $a0, $t4
	li $v0, 11
	syscall
	
	la $t5, _divider
	move $a0, $t5
	li $v0, 4
	syscall
	
	move $a0, $t3
	li $v0, 1
	syscall
	
	la $t5, _endl
	move $a0, $t5
	li $v0, 4
	syscall
	
	addiu $t0, $t0, 1
	j _fn_print_histogram_loop
_fn_print_histogram_loop_end:

_fn_print_histogram_end:
	jr $ra

```


# 5.

```c
#include <stdio.h>

int size = 10;
int array[] = {32, 6, 51, 63, 22, 29, 91, 39, 66, 47};
void bsort(int v[], int n) {
  int i, j;
  for (j = 0; j < n; j++) {
    for (i = 0; i < n - 1; i++) {
      if (v[i + 1] < v[i]) {
        int tmp;
        tmp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = tmp;
      }
    }
  }
  return;
}
int main() {
  int i;
  bsort(array, size);
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
```

-->

```asm
.data
_array: 
	.word 32  6  51  63  22  29  91  39  66  47
_size:
	.word 10
_endl:
	.asciiz "\n"
_space:
	.asciiz " "
	
	.text
_main:
	li $s0, 0 # i = 0
	la $s1, _array # array
	la $t0, _size
	lw $s2, 0($t0) # size
	
	# bsort(array, size)
	move $a0, $s1
	move $a1, $s2
	jal _bsort
	
_main_loop:
	beq $s0, $s2, _main_loop_end
	sll $t1, $s0, 2
	add $t3, $s1, $t1
	lw $t3, 0($t3) # array[i]

	# Print array[i]	
	move $a0, $t3
	li $v0, 1
	syscall
		
	# Print space
	la $t0, _space
	move $a0, $t0
	li $v0, 4
	syscall
					
	addiu $s0, $s0, 1
	j _main_loop
_main_loop_end:

	# Print end of line
	la $t0, _endl
	move $a0, $t0
	li $v0, 4
	syscall
_exit:
	li $v0, 10
	syscall
		
_bsort:
	li $t0, 0 # j = 0
	
	sub $t3, $a1, 1
	
_bsort_loop_1:
	beq $t0, $a1, _bsort_loop_1_end
	li $t1, 0 # i = 0
	
_bsort_loop_2:
	beq $t1, $t3, _bsort_loop_2_end
	
	sll $t4, $t1, 2
	add $t5, $t4, 4
	
	add $t4, $a0, $t4 # v + i
	add $t5, $a0, $t5 # v + i + 1	

	lw $t6, 0($t4) # v[i]
	lw $t7, 0($t5) # v[i + 1]

	# if v[i + 1] < v[i]	
	bge $t7, $t6, _bsort_loop_2_condition_end
	sw $t7, 0($t4)
	sw $t6, 0($t5)

_bsort_loop_2_condition_end:
									
	addiu $t1, $t1, 1	
	j _bsort_loop_2
_bsort_loop_2_end:

	addiu $t0, $t0, 1
	j _bsort_loop_1
_bsort_loop_1_end:

_bsort_end:
	jr $ra
```
