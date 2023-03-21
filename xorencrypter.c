#include <stdio.h>

/* put your encrypted shellcode here */
unsigned char crowpuke[] = "blackbird";

int main(void) {
    
    char key = 'C'; 
    printf("(+) encoded %d-bytes\n\n\r", sizeof(crowpuke));
    printf("unsigned char crowpuke[] = \"");
    for (int x = 0; x<sizeof(crowpuke); x++) {
        printf("\\x%02x", crowpuke[x]^key);
    }
    
    printf("\";");
    return 0;
    
}
