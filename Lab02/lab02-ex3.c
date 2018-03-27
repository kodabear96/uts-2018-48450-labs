#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int sum(int start, int end);

int main() {
  pid_t pid;
  switch (pid=fork()) {
    case 0:
      printf("Child calc: %d\n", sum(1, 10000));
      break;
    default:
      printf("Parent calc: %d\n", sum(-10000, -1));
  }
  return 0;
}

int sum(int start, int end) {
  int sum = 0;
  for (int i = start; i <= end; i++) {
    sum += i;
  }
  return sum;
}