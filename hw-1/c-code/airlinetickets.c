#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <cstring>

struct airline_ticket {
  char name[50];
  int id;
  int group;
  char airline[50];
  int gate;
  char dest[50];
};

void print(int n, airline_ticket* tickets) {
  for (int i = 0; i < n; i++) {
    airline_ticket tic = tickets[i];
    printf("%s ", tic.name);
  }
  printf("\n");
}

bool is_alphabetically_less(char* target, char* compar, size_t targ_sz, size_t comp_sz) {
  for (size_t i = 0; i < ((targ_sz < comp_sz) ? targ_sz : comp_sz); i++) {
    if (target[i] > compar[i])
      return false;
    if (target[i] < compar[i])
      return true;
  }
  return targ_sz < comp_sz;
}

void swap_tickets(airline_ticket* a, airline_ticket* b) {
  airline_ticket temp = *a;
  *a = *b;
  *b = temp;
}

void make_tickets(int n, airline_ticket* tickets) {
  for (int i = 0; i < n; i++) {
    airline_ticket tic;
    scanf(" %s %d %d %s %d %s",
      tic.name, &tic.id, &tic.group,
      tic.airline, &tic.gate, tic.dest);
    tickets[i] = tic;
  }
}

void sort_tickets(int n, airline_ticket* tickets) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) {
      airline_ticket* a = &tickets[j];
      airline_ticket* b = &tickets[j+1];
      if (is_alphabetically_less(a->name, b->name, strlen(a->name), strlen(b->name)))
	continue;
      swap_tickets(a, b);
    }
  }
}

void filter_tickets(int n, airline_ticket* tickets, int gate, char* airline) {
  int matches = 0;
  for (int i = 0; i < n; i++) {
    if (tickets[i].gate == gate && strcmp(tickets[i].airline, airline) == 0)
      matches++;
  }
  airline_ticket filtered[matches];
  int filIdx = 0;
  for (int i = 0; i < n; i++) {
    if (tickets[i].gate == gate && strcmp(tickets[i].airline, airline) == 0)
      filtered[filIdx++] = tickets[i];
  }
  print(matches, filtered);
}

char* find_name_from_id(int n, airline_ticket* tickets, int id) {
  for (int i = 0; i <= n/2; i++) {
    if (tickets[i].id == id) return tickets[i].name;
    if (tickets[n-i].id == id) return tickets[n-i].name;
  }
  return "no match";
}

int main() {
  int n; scanf("%d", &n);
  airline_ticket tickets[n];

  make_tickets(n, tickets);
  print(n, tickets);

  sort_tickets(n, tickets);
  print(n, tickets);

  filter_tickets(n, tickets, 1234, "AIRLINE");
  printf("%s", find_name_from_id(n, tickets, 665));
}
