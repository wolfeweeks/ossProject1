/**
 * @file worker.c
 * @author Wolfe Weeks
 * @date 2023-01-26
 */

int main(int argc, char* argv[]) {

  // check if command line argument is passed
  if (argc != 2) {
    printf("Error: missing command line argument for number of iterations\n");
    return 1;
  }

  // convert command line argument to integer
  int iterations = atoi(argv[1]);

  // loop for the specified number of iterations
  int i;
  for (i = 1; i <= iterations; i++) {
    printf("WORKER PID: %d PPID: %d Iteration: %d before sleeping\n", getpid(), getppid(), i);
    sleep(1);
    printf("WORKER PID: %d PPID: %d Iteration: %d after sleeping\n", getpid(), getppid(), i);
  }

  return 0;
}
