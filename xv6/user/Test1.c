#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
int main(int argc, char *argv[])
{
int ppid = getpid();
int pid = fork();
if (pid < 0)
{
printf(1, "TEST FAILED\n:");
exit();
}
else if (pid == 0)
{
uint * nullp = (uint*)0;
printf(1, "null dereference: ");
printf(1, "%x %x\n", nullp, *nullp);
printf(1,"TEST FAILED\n");
kill(ppid);
exit();
}
else
{
wait();
printf(1, "TEST PASSED\n");
exit();
}
}
