super simple xor-encrypter for shellcode written in c

```bash
C:\> xorencrypter.exe 
(+) encoding 10-bytes

"\x35\x3b\x36\x34\x3c\x35\x3e\x25\x33\x57"
```

put your shellcode in the script, and xor-encode it with a key:

```c
#include <stdio.h>

// put shellcode here
unsigned char crowpuke[] = "blackbird";

int main(void) {
    
    // change the key  
    char key = 'CROW';
    printf("(+) encoding %d-bytes\n\n", sizeof(crowpuke));
    printf("\"");
    for (int x = 0; x<sizeof(crowpuke); x++) {
        printf("\\x%02x", crowpuke[x]^key);
    }
    printf("\"");
    return 0;
}
```
