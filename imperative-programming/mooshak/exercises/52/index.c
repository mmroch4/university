#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  long value;
  struct Node *next;
} Node;

typedef struct {
  int size;
  Node *first;
} Stack;

void init(Stack *stack) {
  stack->size = 0;
  stack->first = NULL;
}

bool isEmpty(Stack *stack) { return stack->size == 0; }

bool push(long value, Stack *stack) {
  Node *node = (Node *)malloc(sizeof(Node));

  assert(node != NULL);

  node->value = value;
  node->next = NULL;

  if (stack->size > 0) {
    node->next = stack->first;
  }

  stack->first = node;

  stack->size++;

  return true;
}

bool pop(Stack *stack, long *removed) {
  if (isEmpty(stack)) {
    return false;
  }

  Node *t = stack->first;

  stack->first = stack->first->next;

  *removed = t->value;
  free(t);

  stack->size--;

  return true;
}

char *readInput(int *size) {
  char *input = (char *)malloc(sizeof(char));

  assert(input != NULL);

  int i = 0;
  char c;

  while ((c = getchar()) != '\n') {
    input[i++] = c;

    input = realloc(input, (i + 1) * sizeof(char));
  }

  input[i] = ' ';
  *size = i + 1;

  return input;
}

long processNum(char *input, int l, int r) {
  int factor = 1;
  long result = 0;

  if (input[l] == '-') {
    factor = -1;
    l++;
  }

  int i = l;
  int p = r - l - 1;

  while (i < r) {
    result += (input[i] - '0') * (long)pow(10, (double)p);

    p--;
    i++;
  }

  return result * factor;
}

bool processInput(char *input, int size, Stack *stack) {
  int i = 0;

  int l = 0;
  int r = 0;

  while (i < size) {
    if (input[i] == ' ') {
      if (r - l == 1 && (input[l] == '+' || input[l] == '-' ||
                             input[l] == '*' || input[l] == '/')) {
        if (stack->size < 2)
          return false;

        long *a = (long *)malloc(sizeof(long));
        long *b = (long *)malloc(sizeof(long));

        assert(a != NULL && b != NULL);

        pop(stack, a);
        pop(stack, b);

        switch (input[l]) {
        case '+':
          push(*b + *a, stack);
          break;
        case '-':
          push(*b - *a, stack);
          break;
        case '*':
          push(*b * *a, stack);
          break;
        case '/':
          push(*b / *a, stack);
          break;
        }

        free(a);
        free(b);
      } else {
        push(processNum(input, l, r), stack);
      }

      l = i + 1;
      r = l;
    } else {
      r++;
    }

    i++;
  }

  if (stack->size != 1)
    return false;

  return true;
}

int main() {
  int N;

  scanf("%d", &N);
  getchar();

  while (N--) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    assert(stack != NULL);

    init(stack);

    int *size = (int *)malloc(sizeof(int));

    assert(size != NULL);

    char *input = readInput(size);
    
    if (processInput(input, *size, stack)) {
      long *result = (long *)malloc(sizeof(long));

      assert(result != NULL);

      pop(stack, result);

      printf("%ld\n", *result);

      free(result);
    } else {
    
      printf("Expressao Incorreta\n");
    }

    free(size);
    free(input);
    free(stack);
  }

  return 0;
}
