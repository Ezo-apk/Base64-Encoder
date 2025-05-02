#include <errno.h>

#include "base64.h"

int main() {

    char *ret;
    char input[MAX_INPUT_LENGTH];
    char choice_input[100];
    short det;

    
    // "S1JZUFRPTklTR1JFQQ=="
    
    // KRYPTONISGREAT
    // S1JZUFRPTklTR1JFQVQ=
    

    printf("Do you want to encode or decode a string?\nType 1 for encoding and 2 for decoding.\n");
    if (!fgets(choice_input, 100, stdin)) {
        printf("Failed to get your choice, exitting\n");
        return 1;
    }

    errno = 0;
    det = (short)strtol(choice_input, NULL, 0);


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

    if (!fgets(input, MAX_INPUT_LENGTH, stdin)) {
        printf("Failed to read your input string, exitting\n");
        return 1;
    }

    ret = (det == 1) ? encodeBase64(input) : decodeBase64(input);

    printf ("\nYour result is:\n%s\n", ret);

    free(ret);
    return 0;
}

