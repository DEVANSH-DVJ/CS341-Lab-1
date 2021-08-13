#include <stdio.h>

int main() {
  printf("Enter the size of the array\n");

  int N = 0;
  scanf("%i", &N);

  printf("Enter the elements of the array\n");
  int i = 0;
  int prev=0, curr=0;
  scanf("%i", &curr);
  while (i < N) {
    prev = curr;
    scanf("%i", &curr);
    i++;
  }

  return 0;
}
