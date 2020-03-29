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
uint * badp = (uint*)4095;
printf(1, "bad dereference (0x0fff): ");
printf(1, "%x %x\n", badp, *badp); // Traps here
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
