#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *crowPuke;
int ch;
char* key; /* get key from user */
char* filename;
char *read_file();

char *read_file() {
        FILE* in_file = fopen(filename, "r");
        if (! in_file) {
            printf("file can't be read\n");
            exit(-1);
         }

        fseek(in_file, 0, SEEK_END);
        int file_length = ftell(in_file);
        fseek(in_file, 0, SEEK_SET);

        char *string = malloc(sizeof(char) * (file_length+1));
        int i = 0;
        char c;

        while ( (c = fgetc(in_file)) != EOF)
        {
        string[i] = c;
        i++;
        }
        string[i] = '\0';
        fclose(in_file);
        return string;

}

int main(int argc, char* argv[]) {


        while ((ch = getopt(argc, argv, "k:f:kf")) != -1)
        {
             switch (ch)
             {
             case 'k':
                  key = optarg;
                  break;
              case 'f':
                  filename = optarg;
                  break;
              default:
                  (void)fprintf(stderr, "Usage: %s -k <key> -f <filename>\n", argv[0]);
                  return(2);
         }
         }
        if (key == NULL || filename == NULL) {
                printf("(-) usage: %s -k <key> -f <filename>\n", argv[0]);
                return 1;
        }
        crowPuke = read_file();

        const size_t keyLen = strlen(key);
        size_t shellcodeLen = sizeof(crowPuke);

        printf("(*) encoding with key: %s\n", key);
        printf("(+) encoded %zd-bytes\n\n\r", shellcodeLen);
        printf("char crowPuke[] = \"");
        for (int i = 0; i < shellcodeLen - 1; ++i) {
                crowPuke[i] ^= key[i % keyLen];
                printf("\\x%02x", crowPuke[i]);
        }
        printf("\";\n");
        free(crowPuke);
        return 0;
}
