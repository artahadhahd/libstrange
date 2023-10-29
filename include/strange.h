// TODO: Optimizations
#ifndef STRANGE_H
#define STRANGE_H 0.1f
#ifndef _WIN32
#define STRAPI __attribute__((visibility("default")))
#else
#define STRAPI __attribute__((dllexport))
#endif
#ifdef __cplusplus
#define restrict
extern "C" {
#endif

#include <stdlib.h> // malloc realloc
#include <string.h> // strcat strlen

enum StrangeErrorHandler {
  STRSuccess,
  STRNoMem,
};

typedef enum StrangeErrorHandler StrangeError;

struct string {
  char * content;
  size_t capacity, length; 
#ifdef __cplusplus // Destructor for C++
  compl string() {
    free(this->content);
  }
#endif
};

typedef struct string String;

STRAPI String string_new();
STRAPI String string_from(const char * restrict input);
STRAPI StrangeError string_append_str(const char * source, String * dest);
STRAPI StrangeError string_append_char(const char c, String * dest);
STRAPI void string_free(const String * string);

// C11 and above
#if __STDC_VERSION__ >= 201112L
#define string_append(src, dest) _Generic((src), char : string_append_char, char * : string_append_str, const char * : string_append_str)(src, dest)
#endif

#ifdef __cplusplus
}
#endif // extern "C"

#endif // STRANGE_H
