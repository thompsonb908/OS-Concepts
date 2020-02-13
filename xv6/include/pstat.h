#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
	int inuse[NPROC];	// Whether this slot of the process table is in user (1 or 0)
	int pid[NPROC];		// The PID of each process
	int hticks[NPROC];	// The number of ticks in the high queue.
	int lticks[NPROC];	// Number of ticks in the low queue.

};

#endif // _PSTAT_H
