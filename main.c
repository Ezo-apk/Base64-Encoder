#include "base64.h"

int main() {

    char *ret;
    char input[MAX_INPUT_LENGTH];
    char choice[100]; 

    // "S1JZUFRPTklTR1JFQQ=="

    // KRYPTONISGREAT
    // S1JZUFRPTklTR1JFQVQ=


    printf("Do you want to encode or decode a string?\nType 1 for encoding and 2 for decoding.\n");
    if (!fgets(choice, 100, stdin)) {
        printf("Failed to get your choice, exitting\n");
        return 1;
    }

    if (choice[0] == '1') {
        printf("Chosen ENCODING, please write the string you want encoded:\n");
    } else if (choice[0] == '2') {
        printf("Chosen DENCODING, please write the string you want dencoded:\n");
    } else {
        printf("That is not a valid choice, run me again\n");
    }

    if (!fgets(input, MAX_INPUT_LENGTH, stdin)) {
        printf("Failed to read your input string, exitting\n");
        return 1;
    }

    if (choice[0] == '1') {
        ret = encodeBase64(input);
        printf("\nYour encoded string is:\n%s\n", ret);
    } else if (choice[0] == '2') {
        ret = decodeBase64(input);
        printf("\nYour dencoded string is:\n%s\n", ret);
    }

    return 0;
}

