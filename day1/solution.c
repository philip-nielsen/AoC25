#include <stdio.h>
#include <stdlib.h>

int *solution() {
  char ch;
  int right = 1;
  int *result = calloc(2, sizeof(int));
  int day1 = 0;
  int day2 = 0;
  int tmp = 0;
  int dial = 50;
  while ((ch = getchar()) != EOF) {
    if (ch == 'L') {
      right = 0;
    } else if (ch == 'R') {
      right = 1;
    } else if (ch >= '0' && ch <= '9') {
      tmp = tmp * 10 + ch - '0';
    } else if (ch == '\n') {
      if (right) {
        dial += tmp % 100;
      } else {
        dial -= tmp % 100;
      }

      if (tmp >= 100) {
        day2 += tmp / 100;
      }

      if (dial < 0) {
        if (dial + tmp % 100 != 0)
          day2++;
        dial = 100 + dial;
      } else if (dial > 100) {
        day2++;
        dial = dial % 100;
      }

      if (dial == 0 || dial == 100) {
        day1++;
        dial = dial % 100;
      }
      printf("curent = %d dial = %d and result2 = %d\n", tmp, dial,
             day2 + day1);
      tmp = 0;
    }
  }
  result[0] = day1;
  result[1] = day2 + day1;
  return result;
}

int main() {
  int *result = solution();
  printf("day1 = %d\n", result[0]);
  printf("day2 = %d\n", result[1]);
  free(result);
}