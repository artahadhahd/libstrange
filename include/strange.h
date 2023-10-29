/* TODO: Optimizations */
#ifndef STRANGE_H
#define STRANGE_H 0.11f
#ifdef __cplusplus
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h> /* malloc realloc */
#include <string.h> /* strcat strlen */
#endif
#ifndef _WIN32
#define STRAPI __attribute__((visibility("default")))
#else
#define STRAPI __attribute__((dllexport))
#endif

#define EXTENDFACTOR 1.5

enum StrangeErrorHandler {
  STRSuccess,
  STRNoMem,
};

typedef enum StrangeErrorHandler StrangeError;

struct string {
  char * content;
  size_t capacity, length; 
#ifdef __cplusplus
  compl string() {
    free(this->content);
  }
#endif
};

typedef struct string String;

#ifdef __cplusplus
extern "C" {
#endif

STRAPI String string_new();
STRAPI String string_from(const char * input);
STRAPI StrangeError string_append_str(const char * source, String * dest);
STRAPI StrangeError string_append_char(const char c, String * dest);
STRAPI void string_free(const String * string);

#ifdef __cplusplus
}
#endif /* extern "C" */
/* C11 and above */
#if __STDC_VERSION__ >= 201112L
#define string_append(src, dest) _Generic((src), char : string_append_char, char * : string_append_str, const char * : string_append_str)(src, dest)
#endif

#endif /* STRANGE_H */
