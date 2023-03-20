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
    char key = ''; // set your encryption key
[snip...]
}
```
