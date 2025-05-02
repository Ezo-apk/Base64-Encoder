#include "base64.h"
#include <assert.h>

void test_EncDec_Div3 () {
    char* enc = encodeBase64("abCdEf");
    assert(strcmp(enc, "YWJDZEVm") == 0);
    free(enc);

    char* denc = decodeBase64("YWJDZEVm");
    assert(strcmp(denc, "abCdEf") == 0);
    free(denc);
}

void test_EncDec_Div2 () {
    char* enc = encodeBase64("2B5Ij");
    assert(strcmp(enc, "MkI1SWo=") == 0);
    free(enc);

    char* denc = decodeBase64("MkI1SWo=");
    assert(strcmp(denc, "2B5Ij") == 0);
    free(denc);
}

void test_EncDec_Div1 () {
    char* enc = encodeBase64("ABBD");
    assert(strcmp(enc, "QUJCRA==") == 0);
    free(enc);

    char* denc = decodeBase64("QUJCRA==");
    assert(strcmp(denc, "ABBD") == 0);
    free(denc);
}

int main() {
    test_EncDec_Div3();
    test_EncDec_Div2();
    test_EncDec_Div1();

    return 0;
}