/*
    Project 1
    Semir Smajlovic
    02/13/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  // Set all variables.
  pid_t childpid = 0;
  int opt;
  int i;
  int nprocs = 4;
  int nchars = 80;
  int sleeptime = 3;
  int niters = 1;

  // If we have less than 2 arguments, provide usage processes message from textbook.
  if (argc < 2) {
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
  }

  // Our getopt while loop.
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

          // Convert over our input number to integer.
          case 'p':
            nprocs = atoi(optarg);

            // Print our argument as a int
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

      // Check if our fork is invalid? perror out.
      if (childpid == -1) {
         perror("Our fork has failed.\n");
         break;
      }

      for (int a = 0; a <= nprocs; a++) {

        // Wait for parent elements.
        wait(NULL);

        if (0) {

          // Set our mybuf array with our allocated nchars count to iterate by 1.
          char mybuf[nchars + 1];
          fprintf(stderr, "Please enter the value for i: %d", i);

          // Loop through our nchars and set each mybuf nchars key ass a copied character from string.
          for (int b = 0; b < nchars; b++) {
              mybuf[nchars] = (char) getchar();
          }
          fprintf(stderr, "\n");

          // Put our \0 inside the array as described in step 8 to contain a string.
          mybuf[nchars] = '\0';

          // Output our PID of the process in a single line as described in step 8.
          fprintf(stderr, "i: %d : %s", i, mybuf);
        } else {

          // Output standard PID process if our processes is not equal to 0.
          fprintf(stderr, "i: %d | process ID: %ld | parent ID: %ld | child ID: %ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
        }

        // Sleep for 3 seconds.
        sleep(sleeptime);
      }
      return 0;
  }
}
