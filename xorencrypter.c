#include <stdio.h>
#include <string.h>

/* place encoded shellcode here */
unsigned char crowPuke[] = "blackbird";

int main(int argc, char* argv[]) {

        if (argc < 2) {
            printf("(-) usage: xorencrypter.exe <key>\n");
            return 1;
        }

        const char* key = argv[1]; /* get key from user */
        const size_t keyLen = strlen(key);
        size_t shellcodeLen = strlen((const char*)crowPuke);

        printf("(*) encoding with key: %s\n", key);
        printf("(+) encoded %zd-bytes\n\n\r", shellcodeLen);
        printf("unsigned char crowPuke[] = \"");
        for (int i = 0; i < shellcodeLen; ++i) {
            crowPuke[i] ^= key[i % keyLen];
            printf("\\x%02x", crowPuke[i]);
        }

        printf("\";\n");
        return 0;

}
