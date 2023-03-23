#include <stdio.h>

/* place encoded shellcode here */
unsigned char crowPuke[] = "encryptedblackbird";

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("(-) usage: xordecrypter.exe <key>");
		return 1;
	}

	char key = argv[1][0]; /* make sure this is the same key used in the encryption process */

	printf("(*) decoding with key: %c\n", key);
	printf("(+) decoded %zd-bytes\n\n\r", sizeof(crowPuke));
	printf("unsigned char crowPuke[] = \"");
	for (int x = 0; x < sizeof(crowPuke) - 1; x++) {
		crowPuke[x] = crowPuke[x] ^ key;
		printf("\\x%02x", crowPuke[x]);
	}

	printf("\";");
	return 0;

}
