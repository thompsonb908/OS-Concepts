#include "types.h"
#include "user.h"

int
main(int argc, char* argv[])
{
	int* p = 0;
	printf(1, "hello [%x]\n",*p); // should give segmentation fault
	exit();
}
