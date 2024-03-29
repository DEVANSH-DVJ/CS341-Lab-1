#include <stdio.h>

int main() {
  int N = 0, i = 1,                 // For input count
      prev = 0, curr = 0,           // For storing elements
      prev_sign = 0, curr_sign = 0, // For storing signs
      length = 1;                   // For length of subsequence

start:
  printf("Enter the size of the array\n");
  scanf("%i", &N);
  goto first;

first:
  printf("Enter the elements of the array\n");
  scanf("%i", &prev);

  goto cond;

cond:
  if (i < N) {
    goto loop;
  } else {
    goto end;
  }

loop:
  scanf("%i", &curr);

  if (prev == curr) {
    curr_sign = 0;
    goto next;
  }

  if (prev < curr) {
    curr_sign = 1;
    if (curr_sign != prev_sign) {
      prev_sign = curr_sign;
      ++length;
    }
    goto next;
  } else {
    curr_sign = -1;
    if (curr_sign != prev_sign) {
      prev_sign = curr_sign;
      ++length;
    }
    goto next;
  }

next:
  prev = curr;
  ++i;
  goto cond;

end:
  printf("%i\n", length);

  return 0;
}
