#include <stdio.h>

int main() {
  printf("Enter the size of the array\n");

  int N = 0;
  scanf("%i", &N);

  printf("Enter the elements of the array\n");
  int prev = 0, curr = 0;
  scanf("%i", &curr);
  int i = 1;
  int prev_sign = 0, curr_sign = 0;
  int length = 1;
  while (i < N) {
    prev = curr;
    prev_sign = curr_sign;

    scanf("%i", &curr);

    if (prev == curr) {
      curr_sign = 0;
      ++i;
      continue;
    } else {

      if (curr > prev) {
        curr_sign = 1;
      } else {
        curr_sign = -1;
      }

      if (curr_sign == prev_sign) {
        ++i;
        continue;
      } else {
        ++length;
        ++i;
        continue;
      }
    }
  }

  printf("%i\n", length);

  return 0;
}
