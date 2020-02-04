#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int
main(int argc, char *argv[])
{
  printf(1, "Pid of process: %d\n",getpid());
  printf(1, "Number of getpid calls: %d\n",getpidcount());
  exit();
}
