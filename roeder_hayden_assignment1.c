#include <stdio.h>
#include <stdlib.h>
int ** custom_allocator(unsigned int n){
	int ** start = malloc(sizeof(int*) * ((2*n) - 1));

	for(int i = 0; i < (2 * n); i++){
		if(i <= n){
			*(start + i) = malloc(sizeof(int) * i);
			for(int j = 0; j < i; j++){
				*(*(start + i) + j) = i;
			}
		}else{
			*(start + i) = malloc(sizeof(int) * ((2*n) - 1 - i));
			for(int j = 0; j <= ((2*n) - 1 - i); j++){
				*(*(start + i) + j) = i;
			}
		}
	}
	return start;
}

unsigned char transition_vector(unsigned char v){
	unsigned char ret = 0;
	unsigned char bitMask[8] = {1,2,4,8,16,32,64,128};
	unsigned char bit[8];
	for(int i = 0; i < 8; i++){
		bit[i] = (v & bitMask[i]) >> i;
	}
	unsigned char toAdd = 0;
	//bit0 = bit5 OR bit6 
	toAdd = bit[5] | bit[6];
	ret = toAdd;

	//bit1 = bit1 AND bit2
	toAdd = bit[1] & bit[2];
	ret = ret | (toAdd << 1);

	//bit2 = bit0 XOR bit1 XOR bit2....
	toAdd = bit[0] ^ bit[1] ^ bit[2] ^ bit[3] ^ bit[4] ^ bit[5] ^ bit[6] ^ bit[7];
	ret = ret | (toAdd << 2);

	//bit3 = NOT bit5
	toAdd = (~bit[5] & 1);
	ret = ret | (toAdd << 3);

	//bit4 = bit4 AND bit7 AND (NOT bit0)
	toAdd = bit[4] & bit[7] & (~(bit[0] & 1));
	ret = ret | (toAdd << 4);

	//bit5 = bit1 OR bit2
	toAdd = bit[1] | bit[2];
	ret = ret | (toAdd << 5);

	//bit6 = bit0
	toAdd = bit[0];
	ret = ret | (toAdd << 6);

	//bit7 = bit2 XOR bit3
	toAdd = bit[2] ^ bit[3];
	ret = ret | (toAdd << 7);

	return ret;
}
void paritize (void *p, unsigned int num_bytes){
	char * point = (char *)p;
	for(int x = 0; x < num_bytes; x++){
		
		unsigned char bitMask[8] = {1,2,4,8,16,32,64,128};
		unsigned char bit[8];
		unsigned int pBit = 0;
		unsigned int oneCounter = 0;
		for(int i = 0; i < 7; i++){
			bit[i] = (*(point + x) & bitMask[i]) >> i;
			if(bit[i] == 1){
				oneCounter++;
			}
		}
		bit[7] = (*(point + x) & bitMask[7]) >> 7;
		if(bit[7] == 1){
			*(point + x) = *(point + x) - 128;
		}
		pBit = oneCounter % 2;
		if(pBit == 1){
			*(point + x) += 128;
		}
	}
}

