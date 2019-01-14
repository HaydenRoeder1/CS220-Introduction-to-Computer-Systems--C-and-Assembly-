#include <stdio.h>
char * readfile(FILE * file){
	//Creates byte arrays to check input against
	char gifCheck1[6] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61};
	char gifCheck2[6] = {0x47, 0x49, 0x46, 0x38, 0x37, 0x61};
	char elfCheck[4] = {0x7F, 0x45, 0x4C, 0x46};
	char pdfCheck[4] = {0x25, 0x50, 0x44, 0x46};
	char zipCheck[2] = {0x50, 0x4B};
	char jClassCheck[4] = {0xCA, 0xFE, 0xBA, 0xBE};
	char pngCheck[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
	
	int i;
	int test = 0;
	char bytes[8];
	fread(bytes, 1, 8, file); //Reads first 8 bytes of the given file into an array
	//Check GIF1
	for(i = 0; i < 6; i++){
		if(bytes[i] != gifCheck1[i]){test = 1; break;}
	}if(test == 0){
		return "This is a GIF file.";
	}test = 0;
	
	//Check GIF2
	for(i = 0; i < 6; i++){
		if(bytes[i] != gifCheck2[i]){test = 1; break;}
	}if(test == 0){
		return "This is a GIF file.";
	}test = 0;
	
	//Check ELF
	for(i = 0; i < 4; i++){
		if(bytes[i] != elfCheck[i]){test = 1; break;}
	}if(test == 0){
		return "This is an ELF file.";
	}test = 0;
	//Check PDF
	for(i = 0; i < 4; i++){
		if(bytes[i] != pdfCheck[i]){test = 1; break;}
	}if(test == 0){
		return "This is a PDF file.";
	}test = 0;
	//Check ZIP
	for(i = 0; i < 2; i++){
		if(bytes[i] != zipCheck[i]){test = 1; break;}
	}if(test == 0){
		return "This is a ZIP file.";
	}test = 0;
	//Check Java Class File
	for(i = 0; i < 4; i++){
		if(bytes[i] != jClassCheck[i]){test = 1; break;}
	}if(test == 0){
		return "This is a Java class file.";
	}test = 0;
	//Check PNG
	for(i = 0; i < 8; i++){
		if(bytes[i] != pngCheck[i]){test = 1; break;}
	}if(test == 0){
		return "This is a PNG file.";
	}test = 0;
	return "File type unknown.";
}