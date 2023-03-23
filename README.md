## `🦊` shellcoder xor-(en|de)crypter

`xorcrypt` is a crypter written in C, that was made for encrypting shellcode for [process injection](https://github.com/cr-0w/maldev) techniques.

## `🪙` encrypting

to encrypt your shellcode, you just need to populate the shellcode variable in the `xorencrypter` file:

```cpp
#include <stdio.h>
#include <string.h>

/* place shellcode here */
unsigned char crowPuke[] = "\x41\x42\x43\x90\x90\x90\x90\x00\x0a";

[snip...]
```

after compiling, you can supply in a key to encrypt with (you could also just specify the key by changing the `key` variable):

```cpp
PS C:\xorcrypt> .\xorencrypter.exe cr0w_waz_here_666
(*) encoding with key: cr0w_waz_here_666
(+) encoded 7-bytes

unsigned char crowPuke[] = "\x22\x30\x73\xe7\xcf\xe7\xf1";
```

you now have encrypted shellcode to work with! 

## `🔖` decrypting

to decrypt it, you can populate the shellcode variable in the `xordecrypter` file:

```cpp
#include <stdio.h>
#include <string.h>

/* place encoded shellcode here */
unsigned char crowPuke[] = "\x22\x30\x73\xe7\xcf\xe7\xf1";

[snip...]
```

now, we compile, and we can decrypt the encrypted shellcode:

```cpp
PS C:\xorcrypt> .\xordecrypter.exe cr0w_waz_here_666
(*) decoding with key: cr0w_waz_here_666
(+) decoded 8-bytes

unsigned char crowPuke[] = "\x41\x42\x43\x90\x90\x90\x90";
```

we get our original shellcode back!

## `🔮` for the future

- ~~`make the key sizes larger (as of writing this, the encryption only works with single chars)`~~ `✅`
- ~~`specify the key from the command line`~~ `✅`
- `add in support for supplying shellcode via as a file or through commandline somehow`
