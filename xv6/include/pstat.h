#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
	int inuse[NPROC];	// Whether this slot of the process table is in user (1 or 0)
	int pid[NPROC];		// The PID of each process
	int queue[NPROC];	// Current queue number
	int ticks[NPROC][2];	// The number of ticks for each queue;

};

#endif // _PSTAT_H
