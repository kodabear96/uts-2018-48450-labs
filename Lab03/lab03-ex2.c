#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MESSLENGTH 80

/* Globals */
static const char PourIntoPipe[] = "This has been through the pipe!\n";
static char CollectFromPipe[MESSLENGTH];

int main(void)
{
  /* Array to store file descriptor */
  int fileDescriptor[2];

  /* Create pipe */
  if (pipe(fileDescriptor) == -1) {
    errno = -1;
    perror("Pipe creation failed");
    return EXIT_FAILURE;
  }

  /* Fork the process */
  switch (fork()) {
    case -1: /* Handle error */
      errno = -1;
      perror("Fork failed");
      return EXIT_FAILURE;

    case 0:  /* Child - reads from pipe */
      close(fileDescriptor[1]);
      read(fileDescriptor[0], CollectFromPipe, MESSLENGTH);
      printf("%s", CollectFromPipe);
      close(fileDescriptor[0]);  /* Close read */

    default:  /* Parent - writes to pipe */
        close(fileDescriptor[0]);
        write(fileDescriptor[1], PourIntoPipe, MESSLENGTH);
        close(fileDescriptor[1]);

    return EXIT_SUCCESS;
  }
}
