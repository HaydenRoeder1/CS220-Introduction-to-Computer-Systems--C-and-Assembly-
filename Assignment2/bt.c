#include <stdio.h>
void print_backtrace(int count);
extern long * get_rbp();
/*Test Functions for backtrace
void func4(int count){
	print_backtrace(count);
}
void func3(int count){
	//print_backtrace(count);
	func4(count);
}
void func2(int count){
	//print_backtrace(count);
	func3(count);
}
void func1(int count){
	//print_backtrace(count);
	func2(count);
}
*/


int main(){
	print_backtrace(0x9);
	return 0;
}
long findMainEnd(){
	unsigned char * printChar = (char*)&main; //Creates a char pointer containing the address of main
	while(*(printChar) != 0xc3){ //Loops through the main function until the return statement
		printChar++; 
	}
	return (long)printChar;
}
void print_backtrace(int count){
	long mainEnd = findMainEnd();
	long * curr_rbp = get_rbp();
	while(count > 0){
		long ret_addr = *(curr_rbp + 1);
		printf("%lx\n", ret_addr);
		if((mainEnd > ret_addr)&&((long)&main < ret_addr)){
			return;
		}
		curr_rbp = (long*)*(curr_rbp);
		count--; 
	}
}
