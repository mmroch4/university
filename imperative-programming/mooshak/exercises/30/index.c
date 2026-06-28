#include <math.h>
#include <stdio.h>
#include <string.h>

#define CANDIDATES_NAME_MAX_LENGTH (80 + 1)
#define INSTITUTIONS_NAME_MAX_LENGTH (80 + 1)
#define INSTITUTIONS_CODE_RANGE 300

typedef struct {
  long applications;
  long acc_grades;
  int code;
  char name[INSTITUTIONS_NAME_MAX_LENGTH];
} institution;

unsigned long UNIQUE_INSTITUTIONS = 0;
institution INSTITUTIONS[INSTITUTIONS_CODE_RANGE];

typedef struct {
  long BI;
  char name[CANDIDATES_NAME_MAX_LENGTH];
  int grade;
} candidate;

unsigned short FLAG;
unsigned long N;

void initInstitutions() {
  for (int i = 0; i < INSTITUTIONS_CODE_RANGE; i++) {
    INSTITUTIONS[i].code = i + 1;
    INSTITUTIONS[i].acc_grades = 0;
    INSTITUTIONS[i].applications = 0;
  }
}

void initCandidates(candidate *candidates) {
  for (long i = 0; i < N; i++) {
    candidates[i].BI = 0;
    candidates[i].grade = 0;
  }
}

void CLEAN_BUFFER() {
  while (getchar() != '\n') {
  }
}

void read_long(long *v) {
  scanf("%ld", v);
  CLEAN_BUFFER();
}

void read_int(int *v) {
  scanf("%d", v);
  CLEAN_BUFFER();
}

void read_string(char *v, long max_size) {
  char c;
  int i = 0;
  max_size--;

  while (max_size) {
    c = getchar();

    if (c == '\n' || c == EOF || c == '\0')
      break;

    *(v + i) = c;

    i++;
    max_size--;
  }

  *(v + i) = '\0';
}

void swap(institution *a, institution *b) {
  institution t = *a;
  *a = *b;
  *b = t;
}

void processInput(candidate *candidate) {
  long candidate_BI;
  int candidate_grade, institution_code;
  char candidate_name[CANDIDATES_NAME_MAX_LENGTH],
      institution_name[INSTITUTIONS_NAME_MAX_LENGTH];

  read_long(&candidate_BI);
  read_string(candidate_name, CANDIDATES_NAME_MAX_LENGTH);
  read_string(institution_name, INSTITUTIONS_NAME_MAX_LENGTH);
  read_int(&institution_code);
  read_int(&candidate_grade);

  institution_code--;

  institution *institution = INSTITUTIONS + institution_code;

  if (!institution->applications) {
    strcpy(institution->name, institution_name);

    UNIQUE_INSTITUTIONS++;
  }

  institution->applications++;
  institution->acc_grades += candidate_grade;

  candidate->BI = candidate_BI;
  candidate->grade = candidate_grade;

  strcpy(candidate->name, candidate_name);
}

long average(long acc, long n) { return round((double)acc / (double)n); }

int main() {
  scanf("%ld %hu", &N, &FLAG);

  candidate CANDIDATES[N];

  initInstitutions();
  initCandidates(CANDIDATES);

  long i = 0;

  while (i < N) {
    processInput(CANDIDATES + i);

    i++;
  }

  if (FLAG == 0) {
    printf("%ld\n", UNIQUE_INSTITUTIONS);
  } else if (FLAG == 1) {
    long possible_candidates[N];
    possible_candidates[0] = 0;
    long possible_candidates_counter = 1;
    int max_grade = CANDIDATES[0].grade;

    for (int i = 1; i < N; i++) {
      candidate *candidate = CANDIDATES + i;

      if (candidate->grade > max_grade) {
        max_grade = candidate->grade;
        possible_candidates[0] = i;
        possible_candidates_counter = 1;
      } else if (candidate->grade == max_grade) {
        possible_candidates[possible_candidates_counter] = i;
        possible_candidates_counter++;
      }
    }

    printf("%d\n", max_grade);

    for (int i = 0; i < possible_candidates_counter; i++) {
      printf("%s\n", CANDIDATES[possible_candidates[i]].name);
    }
  } else {
    for (int i = 0; i < INSTITUTIONS_CODE_RANGE; i++) {
      for (int u = 0; u < INSTITUTIONS_CODE_RANGE - 1 - i; u++) {
        institution *a = INSTITUTIONS + u;
        institution *b = INSTITUTIONS + u + 1;

        if (average(a->acc_grades, a->applications) >
            average(b->acc_grades, b->applications)) {
          swap(a, b);
        }
      }
    }

    int i = INSTITUTIONS_CODE_RANGE;
    i--;
    int j = UNIQUE_INSTITUTIONS;

    while (j) {
      institution *institution = INSTITUTIONS + i;

      if (!institution->applications) {
        i--;
        continue;
      }

      printf("%s %ld %ld\n", institution->name, institution->applications,
             average(institution->acc_grades, institution->applications));

      i--;
      j--;
    }
  }

  return 0;
}
