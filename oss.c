/**
 * @file oss.c
 * @author Wolfe Weeks
 * @date 2023-01-26
 */

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  // Initialize variables to hold command line options
  int proc = 1, simul = 1, iter = 3;

  // iterStr used for execl command
  char iterStr[2];

  // Use getopt() function to parse command line options
  int opt;
  while ((opt = getopt(argc, argv, "n:s:t:h")) != -1) {
    switch (opt) {
    case 'n':
      proc = atoi(optarg);
      break;
    case 's':
      simul = atoi(optarg);
      break;
    case 't':
      iter = atoi(optarg);
      // convert iteration number to a string for execl command
      snprintf(iterStr, sizeof(iterStr), "%d", iter);
      break;
    case 'h':
      printf("Usage: oss [-h] [-n proc] [-s simul] [-t iter]\n");
      return 0;
    default:
      printf("Invalid option\n");
      return 1;
    }
  }

  pid_t pid;
  int status;

  // fork a child process
  pid = fork();

  if (pid < 0) {
    // fork failed
    printf("Fork failed!\n");
    exit(1);
  } else if (pid == 0) {
    //exec .worker process
    execl("./worker", "./worker", iterStr, NULL);
  } else {
    // wait for child process to finish
    waitpid(pid, &status, 0);
  }

  return 0;
}
