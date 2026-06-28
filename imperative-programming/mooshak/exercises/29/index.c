#include <stdio.h>

#define ECONOMIC_ACTIVITY_SIZE 100
#define COMPANY_NAME_MAX_LENGTH 100
#define ECONOMIC_ACTIVITY_NAME_MAX_LENGTH 100

typedef struct {
  long acc;
  long companies;
} economic_activity;

int N, FLAG;
long UNIQUE_ECONOMIC_ACTIVITY = 0;
economic_activity ECONOMIC_ACTIVITY[ECONOMIC_ACTIVITY_SIZE];

void swap(economic_activity *a, economic_activity *b) {
  economic_activity t = *a;
  *a = *b;
  *b = t;
}

void initializeEconomicActivity() {
  for (int i = 0; i < ECONOMIC_ACTIVITY_SIZE; i++) {
    ECONOMIC_ACTIVITY[i].acc = 0;
    ECONOMIC_ACTIVITY[i].companies = 0;
  }
}

void CLEAN_BUFFER() {
  while (getchar() != '\n') {
  }
}

void read_int(int *v) {
  scanf("%d", v);
  CLEAN_BUFFER();
}

void read_long(long *v) {
  scanf("%ld", v);
  CLEAN_BUFFER();
}

void read_string(char *v, long max_length) {
  char c;
  long i = 0;

  max_length--;

  while (max_length) {
    c = getchar();

    if (c == '\n' || c == '\0' || c == EOF)
      break;

    *(v + i) = c;

    i++;
    max_length--;
  }

  *(v + i) = '\0';
}

void processInput() {
  long vat, profit;
  int economic_activity_code;
  char name[COMPANY_NAME_MAX_LENGTH],
      economic_activity_name[ECONOMIC_ACTIVITY_NAME_MAX_LENGTH];

  read_long(&vat);
  read_string(name, COMPANY_NAME_MAX_LENGTH);
  read_string(economic_activity_name, ECONOMIC_ACTIVITY_NAME_MAX_LENGTH);
  read_int(&economic_activity_code);
  read_long(&profit);

  economic_activity_code--;

  if (ECONOMIC_ACTIVITY[economic_activity_code].companies == 0) {
    UNIQUE_ECONOMIC_ACTIVITY++;
  }

  ECONOMIC_ACTIVITY[economic_activity_code].companies++;
  ECONOMIC_ACTIVITY[economic_activity_code].acc += profit;
}

int main() {
  initializeEconomicActivity();
  scanf("%d %d", &N, &FLAG);
  CLEAN_BUFFER();

  while (N--) {
    processInput();
  }

  if (FLAG == 0) {
    printf("%ld\n", UNIQUE_ECONOMIC_ACTIVITY);
  } else {
    for (int i = 0; i < ECONOMIC_ACTIVITY_SIZE; i++) {
      for (int u = 0; u < ECONOMIC_ACTIVITY_SIZE - 1 - i; u++) {
        economic_activity a = ECONOMIC_ACTIVITY[u];
        economic_activity b = ECONOMIC_ACTIVITY[u + 1];

        if (a.acc > b.acc) {
          swap(&a, &b);
        }
      }
    }

    int i = 0;
    int j = UNIQUE_ECONOMIC_ACTIVITY;

    while (j) {
      if (ECONOMIC_ACTIVITY[i].companies == 0) {
        i++;
        continue;
      }

      printf("%ld %ld\n", (long)(i + 1), ECONOMIC_ACTIVITY[i].acc);

      j--;
      i++;
    }
  }

  return 0;
}
