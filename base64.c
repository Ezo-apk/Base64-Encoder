#include "base64.h"

const char BASE64SYMBOLS[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

uint32_t getBaseIndex(char c) {
    for (uint32_t i = 0; i < 64; ++i) {
        if (BASE64SYMBOLS[i] == c) {
            return i;
        }
    }
    return 0;
}

char* encodeBase64(char* plain_string) {
    uint32_t len = strlen(plain_string);
    uint32_t index = 0;
    char* output = (char*)calloc(200, sizeof(char));

    for (uint32_t i = 0; i < len; i += 3) {
        uint32_t thruple = 0, nrBytes = 0;
        thruple += (uint32_t)(plain_string[i]) << 16;
        nrBytes++;
        if (i + 1 < len) {
            thruple += (uint32_t)(plain_string[i + 1]) << 8;
            nrBytes++;
            if(i + 2 < len) {
                thruple += (uint32_t)(plain_string[i + 2]);
                nrBytes++;
            }
        }
        nrBytes++;
        
        for (uint32_t j = 0; j < nrBytes; ++j) {
            uint32_t decVal = (thruple >> ((3 - j) * 6)) & 63; // 0x3F
            output[index++] = BASE64SYMBOLS[decVal];
        }
    }

    for (uint32_t i = 0; i < (3 - len % 3); ++i) {
        output[index++] = '=';
    }

    return output;
}

char* decodeBase64(char* encoded_string) {
    uint32_t len = strlen(encoded_string);
    uint32_t index = 0, nr_eqs = 0;
    char* output = (char*)calloc(200, sizeof(char));

    for (uint32_t i = len - 1; i >= 0; --i) {
        if (encoded_string[i] == '=') {
            nr_eqs++;
        } else {
            break;
        }
    }

    for (uint32_t i = 0; i < len; i += 4) {
        uint32_t quadruple = 0;
        quadruple += ((uint32_t)(getBaseIndex(encoded_string[i])) << 18) +
                     ((uint32_t)(getBaseIndex(encoded_string[i + 1])) << 12) +
                     ((uint32_t)(getBaseIndex(encoded_string[i + 2])) << 6) +
                     (uint32_t)(getBaseIndex(encoded_string[i + 3]));

        for (uint32_t j = 0; j < 3; ++j) {
            uint32_t lit = (quadruple >> ((2 - j) * 8)) & 255; // 0xFF
            output[index++] = (char)(lit);
        }
    }

    return output;
}
