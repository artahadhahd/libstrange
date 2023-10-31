#ifndef TEST_ASSERTIONS
#define TEST_ASSERTIONS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strange.h"
void assert_(bool condition, const char * message, unsigned int line, const char * file)
{
    if (condition) return;
    printf("File '%s': Line %d [ERR::ASSERTION] %s\n", file, line, message);
    exit(1);
}
#define strassert(condition, message) assert_(condition, message, __LINE__, __FILE__)
void info_(String * str, unsigned int line, const char * file) {
    printf("File '%s': Line %d [INFO] Content: \"%s\", Capacity: %zu\n", file, line, str->content, str->capacity);
}
#define strinfo(str) info_(&str, __LINE__, __FILE__)
#endif