all: output

output: file_recognizer.o
	gcc file_recognizer.o -std=c99 -o output
file_recognizer.o: file_recognizer.c file_recognizer.h
	gcc -I . -std=c99 -c file_recognizer.c
clean:
	rm -rf *.o
	rm output
