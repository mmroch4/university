// Libraries
#include <malloc.h>
#include <stdio.h>
#include <string.h>
// Constants
#define MAXCONTACTS 1000
#define MAXNAME 100
#define MAXEMAIL 30
#define EOL '\n'
#define SKIPEOL                                                                \
  {                                                                            \
    while (getchar() != '\n')                                                  \
      ;                                                                        \
  }

// new data types
typedef struct {
  char *name, *email;
  int birth, phone;
} Contact;

// Global variables
Contact myContacts[MAXCONTACTS]; // array with my contacts list
int nContacts;                   // number of contacts in myContacts list

// prototype functions
void printContact(int);
Contact readContact();
void inputMyContacts();
void printContactsWithBirth(int);
char *readName();
void sortContacts();

void swap(Contact *a, Contact *b) {
  Contact t = *a;
  *a = *b;
  *b = t;
}

int main() {
  inputMyContacts();

  int flag;

  scanf("%d", &flag);

  if (flag == 0) {
    int month;

    scanf("%d", &month);

    printContactsWithBirth(month); // to be implemented
  } else if (flag == 1) {          // sort
    sortContacts();

    for (int i = 0; i < nContacts; i++)
      printContact(i);
  }
}

// print 1 contact
void printContact(int index) {
  Contact contact = myContacts[index];

  printf("%s\n", contact.name);
  printf("%s\n", contact.email);
  printf("%d\n", contact.birth);
  printf("%d\n", contact.phone);
}

// reads a name (line of characters) from standard input
char *readName() {
  char ch, aux[MAXNAME], *name;

  int ctr = 0;

  while ((ch = getchar()) != EOL)
    aux[ctr++] = ch;

  aux[ctr] = '\0';

  name = (char *)malloc(ctr + 1);

  strcpy(name, aux);

  return name;
}

// read 1 contact
Contact readContact() {
  Contact c;

  c.name = readName();
  c.email = readName();

  scanf("%d %d", &c.birth, &c.phone);

  SKIPEOL;

  return c;
}

// read a set of contacts
void inputMyContacts() {
  scanf("%d", &nContacts);
  SKIPEOL;
  for (int i = 0; i < nContacts; i++)
    myContacts[i] = readContact();
}

void printContactsWithBirth(int month) {
  int exists = 0;
  for (int i = 0; i < nContacts; i++) {
    int b = myContacts[i].birth;
    int a = (b / 100);

    int k = a - (a / 100) * 100;

    if (k == month) {
      exists = 1;
      printf("%s %d\n", myContacts[i].name, myContacts[i].phone);
    }
  }
  
  if (!exists) {
      printf("NONE\n");
  }
}

int getSmaller(Contact *a, Contact *b) {
  int i = 0;

  while (*(a->name + i) != '\0') {
    if (*(b->name + i) == '\0')
      return 1;

    if (*(a->name + i) == *(b->name + i)) {
      i++;
      continue;
    } else if (*(a->name + i) > *(b->name + i)) {
      return 1;
    } else {
      return 0;
    }

    i++;
  }

  return 0;
}

void sortContacts() {
  for (int i = 0; i < nContacts; i++) {
    for (int u = 0; u < nContacts - 1 - i; u++) {
      Contact *a = myContacts + u;
      Contact *b = myContacts + u + 1;

      if (getSmaller(a, b)) {
        swap(a, b);
      }
    }
  }
}
