/**
 * @file oss.c
 * @author Wolfe Weeks
 * @date 2023-01-26
 */

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
  // Initialize variables to hold command line options
  int proc = 1, simul = 1, iter = 3;

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
      break;
    case 'h':
      printf("Usage: oss [-h] [-n proc] [-s simul] [-t iter]\n");
      return 0;
    default:
      printf("Invalid option\n");
      return 1;
    }
  }

  // Print out parsed options
  printf("proc = %d, simul = %d, iter = %d\n", proc, simul, iter);
  return 0;
}
