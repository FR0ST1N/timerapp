#include <stdio.h>
#include <stdlib.h>

#include "include/timer.h"

int main(int argc, char *argv[]) {
  switch (argc) {
    case 1:
      Stopwatch();
      break;
    case 2:
      Countdown(atoi(argv[1]));
      break;
    default:
      printf("Unknown arguments...");
      exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
