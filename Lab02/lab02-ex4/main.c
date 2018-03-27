#include <stdio.h>
#include <unistd.h>
#include "sum.h"
#include <sys/types.h>

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