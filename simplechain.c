/*
This is our initial simplechain function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t childpid = 0;
  int opt;
  int i;
  int nprocs = 4;
  int nchars = 80;
  int sleeptime = 3;
  int niters = 1;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
  }

  while((opt = getopt(argc, argv, "hp:c:s:i:")) != -1)
  {
    switch(opt)
    {
          case 'h':
            printf("Run instructions:\n");
            printf("Use the following command: chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n\n");
            printf("Definitions:\n");
            printf("nprocs - Number of processes (Default is 4).\n");
            printf("nchars - Number of processes (Default is 80).\n");
            printf("sleeptime - Our sleeptime on each iteration (Default is 3).\n");
            printf("niters = Our number of iterations.\n");
            printf("textfile - Our output textfile.\n");
            break;

          case 'p':
            nprocs = atoi(optarg);
            if (0) printf("We have a detected nprocs: %d.\n", nprocs);
            break;

          case 'c':
            nchars = atoi(optarg);
            if (0) printf("We have a detected nchars: %d.\n", nchars);
            break;

          case 's':
            sleeptime = atoi(optarg);
            if (0) printf("We have a detected sleeptime: %d.\n", sleeptime);
            break;

          case 'i':
            niters = atoi(optarg);
            if (0) printf("We have a detected niters: %d.\n", niters);
            break;

          default:
            break;
    }
  }

  for (i = 1; i < nprocs; i++)
    if (childpid = fork())
      break;
    if (childpid < 0) {
      perror("The fork on our /chain command has failed.");
    }

  for (int a = 1; a <= 1; a++) {
      sleep(sleeptime);
      wait(NULL);
      fprintf(stderr, "i: %d | ", i);
      fprintf(stderr, "Process ID: %ld | ", (long) getpid());
      fprintf(stderr, "Parent ID: %ld | ", (long) getppid());
      fprintf(stderr, "Child ID: %ld | \n", (long) childpid);
  }

  return 0;
}
