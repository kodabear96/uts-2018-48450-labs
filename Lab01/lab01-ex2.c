#include <stdio.h>
void help()
{
  printf("The program should have one input parameter,\n");
  printf("the parameter is the content of display.\n");
  printf("Usage: exe content\n");
  printf("Example: exe \" I am the first program!\"\n");
}
int main(int argc, char **argv)
{
  if (argc != 2)
    help();
  else
  {
    printf("The display content is:\n");
    printf("%s\n", argv[1]);
  }
  return 0;
}