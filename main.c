#include <errno.h>

#include "base64.h"

int main() {

    char input[MAX_INPUT_LENGTH];
    short det;
    
    while (1) {
        char *ret;
        printf("Do you want to encode or decode a string?\nType 1 for encoding, 2 for decoding, or 3 to exit.\n");
        if (!scanf("%hi", &det)) {
            printf("Failed to get your choice, exitting\n");
            return 1;
        }

        switch (det) {
            case 1:
                printf("Chosen ENCODING, please write the string you want encoded:\n");
                break;
            case 2:
                printf("Chosen DENCODING, please write the string you want dencoded:\n");
                break;
            case 3:
                printf("Goodbye\n");
                return 0;
            default:
                printf("That is not a valid choice, run me again\n");
                return 0;
        }

        if (!scanf("%64000s", input)) {
            printf("Failed to read your input string, exitting\n");
            return 1;
        }

        ret = (det == 1) ? encodeBase64(input) : decodeBase64(input);

        printf ("\nYour result is:\n%s\n\n", ret);
        free(ret);
    }

    return 0;
}

