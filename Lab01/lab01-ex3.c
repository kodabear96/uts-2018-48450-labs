#include <stdio.h>
void help()
{
  printf("The program should have one input parameter,\n");
  printf("the parameter is the document to be read.\n");
  printf("Usage: exe text_file_path\n");
  printf("Example: exe txt_file_path\n");
}
int main(int argc, char **argv)
{
  if (argc != 2)
    help();
  else
  {
    // open a text file
    FILE *file = fopen(argv[1], "r");
    char strLine[256];
    char ch;
    if (file != NULL)
    {
      fgets(strLine, 256, file); //read a line from the text file.
      printf("%s\n", strLine);
      //read two characters
      fread(&ch, sizeof(char), 1, file);
      printf("%c", ch);
      fread(&ch, sizeof(char), 1, file);
      printf("%c", ch);
      //read the remaining content of the line.
      fgets(strLine, 256, file); //read a line from the text file.
      printf("%s\n", strLine);
    }
  }
}