#include "../include/strange.h"
String string_new() {
  size_t capacity = 15;
  char * content = malloc(capacity);
  return (struct string) {
    .content = content,
    .capacity = capacity,
    .length = 0
  };
}

String string_from(const char * input) {
  size_t len = strlen(input);
  size_t capacity = len < 15 ? 15 : len * EXTENDFACTOR;
  char * content = malloc(capacity);
  strcpy(content, input);
  return (struct string) {
    .content = content,
    .capacity = capacity,
    .length = len
  };
}

StrangeError string_append_str(const char * source, String * dest) {
  size_t len = strlen(source);
  if (dest->length + len >= dest->capacity) {
    dest->content = realloc(dest->content, (dest->capacity + len) * EXTENDFACTOR);
    if (dest->content == NULL) {
      return STRNoMem;
    }
    dest->capacity = (dest->capacity + len) * EXTENDFACTOR;
  }
  strcat(dest->content, source);
  dest->length += len; 
  return STRSuccess;
}

StrangeError string_append_char(const char c, String * dest) {
  if (dest->length >= dest->capacity) {
    dest->content = realloc(dest->content, dest->capacity * EXTENDFACTOR);
    if (dest->content == NULL) {
      return STRNoMem;
    }
    dest->capacity *= EXTENDFACTOR;
  }
  dest->content[dest->length++] = c;
  return STRSuccess;
}

void string_free(const String * string) {
  free(string->content);
}
