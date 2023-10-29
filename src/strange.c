#include "../include/strange.h"
#define INITIAL_CAPACITY 15
String string_new() {
  size_t capacity = INITIAL_CAPACITY;
  char * content = malloc(capacity);
  return (struct string) {
    .content = content,
    .capacity = capacity,
    .length = 0
  };
}

String string_from(const char * input) {
  size_t len = strlen(input);
  size_t capacity = len <= INITIAL_CAPACITY ? INITIAL_CAPACITY : len * EXTENDFACTOR;
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
    dest->capacity = (float)(dest->capacity + len) * 1.5f;
    dest->content = realloc(dest->content, dest->capacity);
    if (dest->content == NULL) {
      return STRNoMem;
    }
  }
  strcat(dest->content, source);
  dest->length += len; 
  return STRSuccess;
}

StrangeError string_append_char(const char c, String * dest) {
  if (dest->length >= dest->capacity) {
    dest->capacity *= EXTENDFACTOR;
    dest->content = realloc(dest->content, dest->capacity);
    if (dest->content == NULL) {
      return STRNoMem;
    }
  }
  dest->content[dest->length++] = c;
  return STRSuccess;
}

void string_free(const String * string) {
  free(string->content);
}
