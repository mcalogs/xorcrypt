super simple XOR-encrypter for shellcode written in c

```bash
PS C:\XOR_ENCRYPT> .\xorencrypt0r.exe
(+) encoding 10-bytes

unsigned char crowpuke[] = "\x35\x3b\x36\x34\x3c\x35\x3e\x25\x33\x57";
```

put your shellcode in the script, and xor-encode it with a key:

```c
#include <stdio.h>

/* put shellcode here */
unsigned char crowpuke[] = "blackbird";

int main(void) {
    char key = ''; /* set your encryption key  */
[snip...]
}
```

then take your encrypted shellcode and decode it in the script in which you need it:

```c

unsigned char encryptedCrowPuke[] = "encryptedshellcodehere";

int main(void) {
    char key = 'CR0W';
	printf("(+) decoded xor-encrypted shellcode\n");
	for (int x = 0; x < sizeof(crowpuke) - 1; x++) {
		crowpuke[x] = crowpuke[x] ^ key;
	}
    return 0;
}

```
