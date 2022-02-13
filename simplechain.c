/*
This is our initial simplechain function.
*/

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

int main(int argc, char * argv[]) {
  pid_t childpid = 0;
  int i, n;

  if (argc != 2) {
    /* check for valid number of command-line arguments */
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
  }
  n = atoi(argv[1]);

  for (i = 1; i < n; i++)
    if (childpid = fork())
      break;

  sleep(3);
  wait();

  for(j = 1; j <= 1; j++){
      fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
        i, (long) getpid(), (long) getppid(), (long) childpid);
  }

  return 0;
}
