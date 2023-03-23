super simple shellcode XOR-encrypter written in c

```c
PS C:\xorcrypt> .\xorencrypter.exe
(+) encoded 10-bytes

unsigned char crowpuke[] = "\x35\x3b\x36\x34\x3c\x35\x3e\x25\x33\x57";
```

let's take the following bytes as an example of shellcode that we'd like to encrypt/decrypt: **`"\x41\x41\x41\x42\x42\x42\x43\x43\x43\x90\x00\x0a"`**. we would put this into our encoding script:

```c
#include <stdio.h>

/* put shellcode here*/
unsigned char crowpuke[] = "\x41\x41\x41\x42\x42\x42\x43\x43\x43\x90\x00\x0a";
[snip...]
```

once we run the script, we can see the encrypted shellcode:

```c
PS C:\xorcrypt> .\xorencrypter.exe
(+) encoded 13-bytes

unsigned char crowpuke[] = "\x02\x02\x02\x01\x01\x01\x00\x00\x00\xd3\x43\x49\x43";
```

with this newly encrypted shellcode: **`"\x35\x3b\x36\x34\x3c\x35\x3e\x25\x33\x57\x57"`**, we could put this in our decrypter script to get the original unencrypted bytes back. first, we put the encrypted shellcode into our decrypter script:

```c
#include <stdio.h>

unsigned char crowpuke[] = "\x02\x02\x02\x01\x01\x01\x00\x00\x00\xd3\x43\x49\x43";
[snip...]
```

now, we just run it:

```c
PS C:\xorcrypt> .\xordecrypter.exe
(+) decoded 14-bytes

unsigned char crowpuke[] = "\x41\x41\x41\x42\x42\x42\x43\x43\x43\x90\x00\x0a\x00";
```

## todo

- ~~add in support for bigger keysizes (right now, the program takes in a single char for a key)~~  `✅`
- ~~specify key from command-line~~ `✅`
