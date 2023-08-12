#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int tsp(int cost[MAX][MAX], int n, int mask, int city) {
  int i, min_cost, min_city;
  if (mask == (1 << n) - 1) {
    return cost[city][0];
  }
  min_cost = 99999;
  for (i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      int new_cost = cost[city][i] + tsp(cost, n, mask | (1 << i), i);
      if (new_cost < min_cost) {
        min_cost = new_cost;
        min_city = i;
      }
    }
  }
  return min_cost;
}

int main() {
  int n, i, j, cost[MAX][MAX];
  printf("Enter the number of cities: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter the cost between city %d and city %d: ", i + 1, j + 1);
      scanf("%d", &cost[i][j]);
    }
  }
  int min_cost = tsp(cost, n, 1, 0);
  printf("The minimum cost is: %d", min_cost);
  return 0;
}
