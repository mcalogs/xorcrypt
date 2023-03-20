#include <stdio.h>

/* put your shellcode here */
unsigned char crowpuke[] = "blackbird";

int main(void) {
   
    char key = 'CROW'; /* change the key */  
    printf("(+) encoding %d-bytes\n\n", sizeof(crowpuke));
    printf("\"");
    for (int x = 0; x<sizeof(crowpuke); x++) {
        printf("\\x%02x", crowpuke[x]^key);
    }
    printf("\"");
    return 0;
}
