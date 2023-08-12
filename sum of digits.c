#include <stdio.h>

int sumOfDigits(int n) {
  int sum = 0, digit;
  while (n > 0) {
    digit = n % 10;
    sum += digit;
    n /= 10;
  }
  return sum;
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  int sum = sumOfDigits(n);
  printf("The sum of digits is: %d", sum);
  return 0;
}
