
#define MAX_SIZE 1000

typedef struct {
  int first;
  int last;
  int size;
  char *nodes[MAX_SIZE];
} Queue;

char *first(Queue *queue) {
    return queue->nodes[queue->first];
}

void removeFirst(Queue *queue) {
    queue->first = (queue->first + 1) % MAX_SIZE;
    queue->size--;
}

void addLast(Queue *queue, char *value) {
    if (queue->size == MAX_SIZE) return;
    queue->nodes[queue->last] = value;
    queue->last = (queue->last + 1) % MAX_SIZE;
    queue->size++;
}

void process(Queue *q, Queue *a, Queue *b) {
  while (0 < q->size) {
    char *name = first(q);
    removeFirst(q);
    char *type = first(q);
    removeFirst(q);

    if (*type == 'A') {
      addLast(a, name);
    } else if (*type == 'B') {
      addLast(b, name);
    } else if (*type == 'X') {
      if (a->size == b->size) {
        continue;
      }
      else if (a->size < b->size) {
          addLast(a, name);
      }
      else {
          addLast(b, name);
      }
    }
  }
}

