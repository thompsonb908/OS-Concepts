#include <stdio.h>
#include <stdlib.h>

/*
 * Linear page table
 *   PTE for VPN 0         [ valid = 0 | prot | present | Phys Frame Num ]
 *   PTE for VPN 1
 *   PTE for VPN 2
*/

int
main(int argc, char* argv[])
{
	int* p = (int*) malloc(sizeof(int)); 
	printf("code address: %p\n", main);
	printf("stack address: %p\n", &p);
	printf("heap address: %p\n", p);
	
	p = 0;
	printf("%p\n", p);
	*p = 100; // Go to address 0 and put 100 (Segmentation fault)
	return 0;
}
