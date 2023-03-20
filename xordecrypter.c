#include <stdio.h>

unsigned char crowpuke[] = "encodedshellcodehere";

int main(void) {
	char key = 'CROW'; 
	printf("(+) decoded xor-encrypted shellcode\n");
	for (int x = 0; x < sizeof(crowpuke) - 1; x++) {
		crowpuke[x] = crowpuke[x] ^ key;
	}
	
	return 0;
}
