#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct {
  int top;
  char *nodes;
} Stack;

bool isEmpty(Stack *stack) {
    return stack->top == 0;
}

int top(Stack *stack) {
    return stack->nodes[stack->top - 1];
}

void push(Stack *stack, char value) {
    stack->nodes[stack->top] = value;
    stack->top++;
}

void pop(Stack *stack) {
    stack->top--;
}

bool balanced(char *input) {
    char nodes[MAX_SIZE];
    
    Stack stack = {
        0, nodes
    };
    
    int p = 0;

    while (input[p] != '\0') {
        if (input[p] == ')' || input[p] == ']') {
            if (isEmpty(&stack)) return false;

            int t = top(&stack);

            if (t == '(' && input[p] == ']') return false;
            else if (t == '[' && input[p] == ')') return false;

            pop(&stack);
        }
        else {
            push(&stack, input[p]);
        }
        
        p++;
    }

    return stack.top == 0;
}

int main() {
    if (balanced("]")) {
        printf("OK!");
    }
    else {
        printf("No!");
    }
}