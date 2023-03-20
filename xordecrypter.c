#include <stdio.h>

/* place encoded shellcode here */
unsigned char crowpuke[] = "encryptedblackbird";

int main(void) {
	
	char key = 'C'; 
	printf("(+) decoded %d-bytes\n\n\r", sizeof(crowpuke)); 
    printf("unsigned char crowpuke[] = \"");
	for (int x = 0; x < sizeof(crowpuke) - 1; x++) {
		crowpuke[x] = crowpuke[x] ^ key;
        printf("\\x%02x", crowpuke[x]);
		
	}
	
    printf("\";");
    return 0;
	
}
