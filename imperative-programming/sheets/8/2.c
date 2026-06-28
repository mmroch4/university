#include <stdio.h>

#define MAX 10
#define MAXNAME 100
#define MAXPLAYERS 100
#define MAXTEAMS 20
#define MAXTOURNAMENTS 20

typedef struct player {
  char nome[MAXNAME];
  char id[MAX]; // unique code (eg: J045612)
  int tournaments[MAX], nt;
} PLAYER;

typedef struct team {
  char name[MAXNAME];
  int players[MAX], nj;
} TEAM;

typedef struct tournament {
  char name[MAXNAME];
  int year;
} TOURNAMENT;

int NTournaments = 5;
TOURNAMENT Tournaments[MAXTOURNAMENTS] = {{"World eSports Cup", 2023},
                                          {"Pro League", 2024},
                                          {"Elite Battle", 2023},
                                          {"Champions Arena", 2024},
                                          {"Global Masters", 2023}};

int NPlayers = 6;
PLAYER Players[MAXPLAYERS] = {{"Diogo Lopes", "J045612", {0, 2, 4}, 3},
                              {"Andreia Silva", "J012345", {1, 3}, 2},
                              {"Rui Matos", "J098765", {0, 1, 2}, 3},
                              {"Sofia Costa", "J078901", {3, 4}, 2},
                              {"Marco Silva", "J067890", {2, 4}, 2},
                              {"Tiago Rocha", "J023456", {1, 2, 3}, 3}};

int NTeams = 3;
TEAM Teams[MAXTEAMS] = {{"Shadow Dragons", {0, 2, 4}, 3},
                        {"Phoenix Reborn", {1, 3}, 2},
                        {"Iron Wolves", {5}, 1}};

int contains(char *a, char *b) {
  int i = 0;
  int j = 0;

  while (a[i] != '\0') {
    if (a[i] == b[j]) {
      j++;

      if (b[j] == '\0')
        return 1;
    } else {
      j = 0;
    }

    i++;
  }

  return 0;
}

int equals(char *a, char *b) {
  int i = 0;

  while (a[i] != '\0') {
    if (a[i] != b[i])
      return 0;

    i++;
  }

  return 1;
}

void writeTo(char *s, char *to) {
  int i = 0;

  while (to[i] != '\0') {
    if (s[i] != '\0') {
      to[i] = s[i];
    } else {
      to[i] = '\0';
    }

    i++;
  }
}

void searchPlayer(char *nameWord) {
  printf("Players whose name includes \"%s\":\n", nameWord);

  for (int i = 0; i < NPlayers; i++) {
    if (contains(Players[i].nome, nameWord)) {
      printf("%s %s\n", Players[i].id, Players[i].nome);
    }
  }
}

int id2Player(char *id, char *name) {
  for (int i = 0; i < NPlayers; i++) {
    if (equals(Players[i].id, id)) {
      writeTo(name, Players[i].nome);

      return 1;
    }
  }

  return 0;
}

int teamPlayers(char *teamName) {
  for (int i = 0; i < NTeams; i++) {
    if (equals(Teams[i].name, teamName)) {
      for (int u = 0; u < Teams[i].nj; u++) {
        printf("%s\n", Players[Teams[i].players[u]].nome);
      }

      return Teams[i].nj;
    }
  }

  return 0;
}

int playersInTournament(char *tournamentName, int *indices) {
  int j = 0;

  for (int i = 0; i < NPlayers; i++) {
    for (int u = 0; u < Players[i].nt; u++) {
      if (equals(Tournaments[Players[i].tournaments[u]].name, tournamentName)) {
        indices[j] = i;
        j++;
      }
    }
  }

  return j;
}

int averageTournamentsPerPlayer() {
  int acc = 0;

  for (int i = 0; i < NPlayers; i++) {
    acc += Players[i].nt;
  }

  return acc / NPlayers;
}

int mostActivePlayers(int *indices) {
  int j = 0;

  int average = averageTournamentsPerPlayer();

  for (int i = 0; i < NPlayers; i++) {
    if (Players[i].nt > average) {
      indices[j] = i;
      j++;
    }
  }

  return j;
}

int maxTournamentsPerYear(int year) {
  int m = 0;

  for (int i = 0; i < NPlayers; i++) {
    int c = 0;

    for (int u = 0; u < Players[i].nt; u++) {
      if (Tournaments[Players[i].tournaments[u]].year == year) {
        c++;
      }
    }

    if (c > m) {
      m = c;
    }
  }

  return m;
}

int playerTournamentsYear(int playerPos, int year) {
  int c = 0;

  for (int u = 0; u < Players[playerPos].nt; u++) {
    if (Tournaments[Players[playerPos].tournaments[u]].year == year) {
      c++;
    }
  }

  return c;
}

int participatedInMultipleYears(int playerPos) {
  int prev = 0;
  
  for (int u = 0; u < Players[playerPos].nt; u++) {
    if (!prev) {
        prev = Tournaments[Players[playerPos].tournaments[u]].year;
      continue;
    }

    if (Tournaments[Players[playerPos].tournaments[u]].year != prev) {
      return 1;
    }
  }

  return 0;
}

int main() {
  return 0;
}
