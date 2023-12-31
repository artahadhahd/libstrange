/* TODO: Optimizations */
#ifndef STRANGE_H
#define STRANGE_H 0.11f
#include <stdlib.h> /* malloc realloc */
#include <string.h> /* strcat strlen */
#include <immintrin.h>
#ifndef _WIN32
#define STRAPI __attribute__((visibility("default")))
#else
#define STRAPI __attribute__((dllexport))
#endif

#define EXTENDFACTOR 1.5f

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
STRAPI void string_free(String * string);
STRAPI void string_minify(String * string);

#ifdef __cplusplus
}
#endif /* extern "C" */
/* C11 and above */
#if __STDC_VERSION__ >= 201112L
#define string_append(src, dest) _Generic((src), char : string_append_char, char * : string_append_str, const char * : string_append_str, int : string_append_char)(src, dest)
#endif

#endif /* STRANGE_H */
