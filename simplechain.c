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
            printf("\nRun instructions:\n");
            printf("Use the following command: chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n\n");
            printf("Definitions:\n");
            printf("nprocs - Number of processes (Default is 4).\n");
            printf("nchars - Number of processes (Default is 80).\n");
            printf("sleeptime - Our sleeptime on each iteration (Default is 3).\n");
            printf("niters = Our number of iterations.\n");
            printf("textfile - Our output textfile.\n\n");
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

  for (i = 1; i < nprocs; i++) {
      if (childpid = fork()) {
          break;
      }

      for (int a = 0; a < 1; a++) {
        wait(NULL);

        if (0) {
          char mybuf[0 + 1];
          fprintf(stderr, "Please enter the value for i: %d", i);

          for (int b = 0; b < 0; b++) {
              mybuf[0] = (char) getchar();
          }

          fprintf(stderr, "\n");
          mybuf[0] = '\0';
          fprintf(stderr, "i: %d : %s", i, mybuf);
        } else {
          fprintf(stderr, "i: %d | process ID: %ld | parent ID: %ld | child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
        }
        sleep(sleeptime);
      }
      return 0;
  }
}