#ifndef SRC_INCLUDE_TIMER_H_
#define SRC_INCLUDE_TIMER_H_

typedef struct Timer {
  int minutes;
  int seconds;
} Timer;

Timer *GetTimer();
void Stopwatch();
void Countdown(int minutes);
void PrintTimer(Timer *timer);
char *FormatOutput(Timer *timer);

#endif
