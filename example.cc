#include "timer.h"
#include "unistd.h"
int main() {
  // first start a thread that prints all timers periodically
  perf_timer::Reporter::StartReportThread(1000);

  // Case 1: the simple case
  perf_timer::Timer timer_simple("simple");
  // do something that we concern
  usleep(100);
  timer_simple.end();

  // Case 2: the cumulative case
  perf_timer::Timer timer_cumulative("cumulative");
  for (int i = 0; i < 1000; i++) {
    // do something
    usleep(10);
    {
      timer_cumulative.CumStart();
      // do something that we concern
      usleep(i * 10);
      timer_cumulative.CumEnd();
    }
    // do something
    usleep(10);
  }
  timer_cumulative.CumReport();

  // Case 3: record a perf counter
  for (int i = 0; i < 10; i++) {
    perf_timer::PerfCounter::Record("throughput", i * 100);
  }

  // manually print all data
  perf_timer::Reporter::Report();
  
  return 0;
}