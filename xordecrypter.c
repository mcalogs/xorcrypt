#include <stdio.h>

/* place encoded shellcode here */
unsigned char crowpuke[] = "encryptedblackbird";

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("(-) usage: xordecrypter.exe <key>");
		return 1;
	}

	char key = argv[1][0]; /* make sure this is the same key used in the encryption process */

	printf("(*) decoding with key: %c\n", key);
	printf("(+) decoded %zd-bytes\n\n\r", sizeof(crowpuke));
	printf("unsigned char crowpuke[] = \"");
	for (int x = 0; x < sizeof(crowpuke) - 1; x++) {
		crowpuke[x] = crowpuke[x] ^ key;
		printf("\\x%02x", crowpuke[x]);
	}

	printf("\";");
	return 0;

}
