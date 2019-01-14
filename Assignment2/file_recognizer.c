#include <stdio.h>
#include <file_recognizer.h>
int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Invalid Input\n");
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("File type unknown\n");
	}else{
		printf("%s\n", readfile(fp));
	}
	fclose(fp);
	return 0;
}