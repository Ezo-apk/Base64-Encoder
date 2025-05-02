#include <errno.h>

#include "base64.h"

int main() {

    char *ret;
    char input[MAX_INPUT_LENGTH];
    short det;

    
    // "S1JZUFRPTklTR1JFQQ=="
    
    // KRYPTONISGREAT
    // S1JZUFRPTklTR1JFQVQ=
    

    printf("Do you want to encode or decode a string?\nType 1 for encoding and 2 for decoding.\n");
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
        default:
            printf("That is not a valid choice, run me again\n");
            return 0;
    }

    if (!scanf("%64000s", input)) {
        printf("Failed to read your input string, exitting\n");
        return 1;
    }

    ret = (det == 1) ? encodeBase64(input) : decodeBase64(input);

    printf ("\nYour result is:\n%s\n", ret);

    free(ret);
    return 0;
}

