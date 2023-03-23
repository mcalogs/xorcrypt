#include <stdio.h>

/* place encoded shellcode here */
unsigned char crowpuke[] = "blackbird";

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("(-) usage: xorencrypter.exe <key>");
		return 1;
	}

	char key = argv[1][0]; /* get key from user */
    
    printf("(*) encoding with key: %c\n", key);
    printf("(+) encoded %zd-bytes\n\n\r", sizeof(crowpuke));
    printf("unsigned char crowpuke[] = \"");
    for (int x = 0; x < sizeof(crowpuke); x++) {
        printf("\\x%02x", crowpuke[x] ^ key);
    }

    printf("\";");
    return 0;

}
