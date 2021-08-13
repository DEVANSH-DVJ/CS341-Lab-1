#include <stdio.h>

int main() {
  printf("Enter the size of the array\n");

  int N = 0;
  scanf("%i", &N);

  printf("Enter the elements of the array\n");
  int i = 0;
  int arr[N];
  while (i < N) {
    scanf("%i", arr + i);
    i++;
  }

  return 0;
}
