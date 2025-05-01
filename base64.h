#pragma once
#ifndef BASE64_H
#define BASE64_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 64000

extern const char BASE64SYMBOLS[64];

uint32_t getBaseIndex(char c);

char* encodeBase64(char* c);
char* decodeBase64(char* c);

#endif