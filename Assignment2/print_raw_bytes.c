void print_main(){
	unsigned char * printChar = (char*)&main; //Creates a char pointer containing the address of main
	while(*(printChar - 1) != 0xc3){ //Loops through the main function until the return statement
		printf("%x ", *(printChar++)); //Increments printChar and prints the byte at its address
	}
	printf("/n");
}