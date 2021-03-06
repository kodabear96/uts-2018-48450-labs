#include <stdio.h>

typedef struct {
  char elem;
} item;

static const int BUFFER_SIZE = 15;

static const char *INPUT_TEXT = "This text will cut here";

int main()
{
	item buffer[BUFFER_SIZE];

  printf("Begin produce:\n");
  for (int in = 0; in < BUFFER_SIZE; in++) {
    buffer[in].elem = INPUT_TEXT[in]; /* Note there is a potential for buffer overflow */
    printf("%c", buffer[in].elem);
  }
  printf("\nFull.\n");

  printf("Begine consume:\n");
  for (int out = 0; out < BUFFER_SIZE; out++) {
    printf("%c", buffer[out].elem);
  }
  printf("\nConsume complete.\n");
}
