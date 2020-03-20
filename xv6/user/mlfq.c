#include "types.h"
#include "user.h"
#include "pstat.h"

struct pstat* initPstat(struct pstat *p){
  int i;
  for(i = 0; i < NPROC; i++) {
    p->inuse[i] = 0; 
    p->pid[i] = 0;
    p->queue[i] = 0;
    p->ticks[i][0] = 0;
    p->ticks[i][1] = 0;
  }
  return p;
}

void printPstat(struct pstat *p) {
  int i;
  int info = getpinfo(p);
  
  if(info == -1){
    printf(1,"Error, getpinfo returned -1");
    exit();
  }
  printf(1, "-----------------------------------------\n");
  printf(1, "| Inuse\t|  PID\t| Queue\t| T[0]\t| T[1]\t|\n");
  for(i = 0; i < 6; i++) {
    printf(1, "-----------------------------------------\n");
    printf(1, "|   %d\t|   %d\t|   %d\t|  %d \t|  %d \t|\n",
    p->inuse[i], p->pid[i], p->queue[i], p->ticks[i][0], p->ticks[i][1]);
  }
  printf(1, "-----------------------------------------\n");
}

int
main(int argc, char *argv[])
{
  struct pstat *p = malloc(sizeof(struct pstat));
  p = initPstat(p);
  printf(1,"mlfq.c test\n");
  int i;
  int j;

  for(j=0; j<1; j++)
  {
    printPstat(p);
  }
  
  for(i = 0; i<2; i++)
  {
    if(fork() == 0){
      printf(1, "Child %d\n",i);
      int x = 1;
      for(j=1; j < 10; j=j+2) {
        x = (x * (i * j * 4000 * 256) / 52);
	printf(1, "Calculated value: %d\n",x);
	printPstat(p);
      }
      printf(1, "Exiting child %d\n",i);
      exit();
    } else{
      wait();
      printf(1, "In parent\n");
      printPstat(p);
    }
  }
  exit();
}
