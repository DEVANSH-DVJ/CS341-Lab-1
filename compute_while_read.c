#include <stdio.h>

int main() {
  printf("Enter the size of the array\n");

  int N = 0;
  scanf("%i", &N);

  printf("Enter the elements of the array\n");
  int prev=0, curr=0;
  scanf("%i", &curr);
  int i = 1;
  while (i < N) {
    prev = curr;
    scanf("%i", &curr);
    i++;
  }

  return 0;
}
