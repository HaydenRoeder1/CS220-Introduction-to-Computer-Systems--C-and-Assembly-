#include <stdio.h>
extern unsigned long rotate(unsigned long val, unsigned long num, unsigned long direction);
int main(){
	unsigned long val1 = 0xDEADBEEFDEADBEEF;
	unsigned long val2 = 0x1;
	printf("0x%lx  -> 0x%lx\n", val1, rotate(val1, 2, 1));
	printf("0x%lx  -> 0x%lx\n", val1, rotate(val1, 2, 0));
	printf("0x%lx  -> 0x%lx\n", val1, rotate(val1, 66, 1));
	printf("0x%lx  -> 0x%lx\n", val2, rotate(val2, 1, 0));
}