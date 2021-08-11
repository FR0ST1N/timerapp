#include "include/timer.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Timer *GetTimer() {
  Timer *timer = malloc(sizeof(Timer));
  timer->minutes = 0;
  timer->seconds = 0;
  return timer;
}

void Stopwatch() {
  Timer *timer = GetTimer();
  while (1) {
    PrintTimer(timer);
    timer->seconds++;
    if (timer->seconds == 60) {
      timer->seconds = 0;
      timer->minutes++;
    }
    sleep(1);
  }
}

void Countdown(int minutes) {
  Timer *timer = GetTimer();
  timer->minutes = minutes;
  while (1) {
    PrintTimer(timer);
    if (timer->seconds == 0) {
      if (timer->minutes == 0) {
        time_t t = time(NULL);
        struct tm *t_info = localtime(&t);
        printf("\rCountdown completed at %s", asctime(t_info));
        exit(EXIT_SUCCESS);
      }
      timer->seconds = 60;
      timer->minutes--;
    }
    timer->seconds--;
    sleep(1);
  }
}

void PrintTimer(Timer *timer) {
  char *c = FormatOutput(timer);
  printf(c, timer->minutes, timer->seconds);
  fflush(stdout);
}

char *FormatOutput(Timer *timer) {
  if (timer->minutes < 10 && timer->seconds < 10)
    return "\r0%d:0%d";
  else if (timer->minutes < 10)
    return "\r0%d:%d";
  else if (timer->seconds < 10)
    return "\r%d:0%d";
  else
    return "\r%d:%d";
}
