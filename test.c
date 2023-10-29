#include "include/strange.h"
#include <stdio.h>

int strcmp_(String * left, String * right) {
#if defined (__x86_64__) && defined (__OPTIMIZE__) // use AVX2
  #error "Not implemented"
#else // naive solution
  while (*left->content && *right->content) {
    if (*left->content++ != *right->content++) {
      return 1;
    }
  }
#endif
  return 0;
}

int main(void) {
  String s = string_from("14characterlong");
  // string_append(" Joe mama! 01203010230012030120301203103201023010230120310", &s);
  printf("Capacity: %ld, Length: %ld, Content: %s\n", s.capacity, s.length, s.content);
  string_append((char)'!', &s);
  printf("Capacity: %ld, Length: %ld, Content: %s\n", s.capacity, s.length, s.content);
  string_append("YEEET", &s);
  printf("Capacity: %ld, Length: %ld, Content: %s\n", s.capacity, s.length, s.content);
  return 0;
}
