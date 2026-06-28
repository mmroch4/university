#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char *value;
  struct Node *next;
} Node;

typedef struct {
  int size;
  Node *first;
  Node *last;
} Queue;

Queue *initQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));

  assert(queue != NULL);

  queue->size = 0;
  queue->first = NULL;
  queue->last = NULL;

  return queue;
}

short isEmpty(Queue *queue) { return queue->size == 0; }

char *first(Queue *queue) { return queue->first->value; }

void enqueue(char *value, Queue *queue) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  if (isEmpty(queue)) {
    queue->first = node;
    queue->last = node;
  } else if (queue->size == 1) {
    queue->first->next = node;
    queue->last = node;
  } else {
    queue->last->next = node;
    queue->last = node;
  }

  queue->size++;
}

void dequeue(Queue *queue) {
  if (isEmpty(queue))
    return;

  if (queue->size == 1) {
    free(queue->first);
    queue->first = NULL;
    queue->last = NULL;
  } else if (queue->size == 2) {
    Node *t = queue->first;
    queue->first = queue->first->next;
    free(t);
    queue->last = queue->first;
  } else {
    Node *t = queue->first;
    queue->first = queue->first->next;
    free(t);
  }

  queue->size--;
}

char *readName() {
  char *name = (char *)malloc(sizeof(char));

  int i = 0;
  char ch;

  while ((ch = getchar()) != '\n') {
    name[i] = ch;
    i++;
    name = realloc(name, (i + 1) * sizeof(char));
  }

  name[i] = '\0';

  return name;
}

void printQueue(Queue *queue) {
  Node *current = queue->first;
  if (current == NULL) {
      printf("---");
  }
  while (current != NULL) {
    printf("%s ", current->value);
    current = current->next;

    if (current != NULL) {
      printf("--> ");
    }
  }
  printf("\n");
}

// int main() {
//   char name1[] = "Miguel";
//   char name2[] = "Matheus";
//   char name3[] = "Gabriella";
//   char name4[] = "Luíza";

//   Queue *queue = initQueue();

//   printQueue(queue);

//   enqueue(name1, queue);

//   printQueue(queue);

//   enqueue(name2, queue);

//   printQueue(queue);

//   dequeue(queue);

//   printQueue(queue);

//   enqueue(name3, queue);

//   printQueue(queue);

//   enqueue(name4, queue);

//   printQueue(queue);

//   dequeue(queue);
//   printQueue(queue);

//   dequeue(queue);
//   printQueue(queue);
  
//   dequeue(queue);
//   printQueue(queue);
// }

int main() {
  int N;

  scanf("%d", &N);
  getchar(); // clear buffer

  Queue *A = initQueue();
  Queue *B = initQueue();
  Queue *C = initQueue();

  int t;

  while (N--) {
    scanf("%d", &t);
    getchar(); // clear buffer

    Queue *queue = NULL;

    if (t) {
      if (!isEmpty(A)) {
        queue = A;
      } else if (!isEmpty(B)) {
        queue = B;
      } else if (!isEmpty(C)) {
        queue = C;
      } else {
        continue;
      }

      printf("%s\n", first(queue));

      dequeue(queue);
    } else {
      char *name = readName();

      char urgency = getchar();
      getchar(); // clear buffer

      switch (urgency) {
      case 'A':
        queue = A;
        break;
      case 'B':
        queue = B;
        break;
      case 'C':
        queue = C;
        break;
      }

      enqueue(name, queue);
    }
  }

  return 0;
}
