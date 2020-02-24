#include "types.h"
#include "user.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{
  struct pstat p;
  printf(1, "mlfq.c test\n");
  int i;
  int j;
  for(i = 0; i<5; i++)
  {
    if(!fork()){
      for(;;){
        }
    }
  }
  for(i = 0; i < 63; i++) {
    p.inuse[i] = 0;
    p.pid[i] = 0;
    p.queue[i] = 0;
    p.ticks[i][0] = 0;
    p.ticks[i][1] = 0;
  }

  for(j=0; j<5; j++)
  {
    int info = getpinfo(&p);
    if(info == -1){
      printf(1, "Error, getpinfo() returned -1");
      exit();
    }

    printf(1, "-----------------------------------\n");
    printf(1, "| Inuse | PID | Queue | Ticks[0] | Ticks[1] |\n");
    for(i = 0; i < 10; i++) {
      printf(1, "---------------------------------\n");
      printf(1, "|   %d  |  %d  |  %d  |  %d  |  %d |\n",
      p.inuse[i], p.pid[i], p.queue[i], p.ticks[i][0], p.ticks[i][1]);
    }
    printf(1, "-----------------------------------\n");
    sleep(0.2);
  }
  exit();
}
