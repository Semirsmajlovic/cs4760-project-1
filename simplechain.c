/*
This is our initial simplechain function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
  pid_t childpid = 0;
  int opt, i;
  int nprocs = 4;
  int nchars = 80;
  int sleeptime = 3;
  int niters = 1;

  if (argc != 2) {
    /* check for valid number of command-line arguments */
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
  }

  while((opt = getopt(argc, argv, "hp:c:s:i:")) != -1)
  {
    switch(opt)
    {
          case'h':
            printf("Run instructions:\n");
            printf("Use the following command: chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n\n");
            printf("Definitions:\n");
            printf("nprocs - Number of processes (Default is 4).\n");
            printf("nchars - Number of processes (Default is 80).\n");
            printf("sleeptime - Our sleeptime on each iteration (Default is 3).\n");
            printf("niters = Our number of iterations.\n");
            printf("textfile - Our output textfile.\n");
          break;

          case'p':
            nprocs = atoi(optarg);
          break;

          case'c':
            nchars = atoi(optarg);
          break;

          case's':
            sleeptime = atoi(optarg);
          break;

          case'i':
            niters = atoi(optarg);
          break;
    }
  }

  for (i = 1; i < nprocs; i++)
    if (childpid = fork())
      break;
    if (childpid < 0) {
      perror("The fork on our /simplechain command has failed.")
    }

  for(j = 1; j <= 1; j++) {

      sleep(sleeptime);
      wait(NULL);

      fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
        i, (long) getpid(), (long) getppid(), (long) childpid);
  }

  return 0;
}
