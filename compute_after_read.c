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
    ++i;
  }

  int prev_sign = 0, length = 1;

  for (int i = 1; i < N; ++i) {
    int curr_sign = 0;
    if (arr[i] == arr[i - 1]) {
      curr_sign = 0;
    } else if (arr[i] > arr[i - 1]) {
      curr_sign = 1;
    } else {
      curr_sign = -1;
    }
    if (curr_sign != prev_sign && curr_sign != 0) {
      prev_sign = curr_sign;
      ++length;
    }
  }
  printf("%i\n", length);

  return 0;
}
