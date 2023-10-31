#include "assertions.h"
#include <string.h>

int
main(void) {
    const char * first_ = "Firefox";
    // const char * second_ = "Firefox is a good browser!";
    String first = string_from(first_);
    strinfo(first);
    strassert(first.length == strlen(first.content), "Lengths are not equal");
    string_minify(&first);
    strinfo(first);
    strassert((first.length == first.capacity) && (sizeof(first.content) == first.length + 1),
        "Minify doesn't work as expected");
    strinfo(first);
    string_append(' ', &first);
    strinfo(first);
    string_append("is a good browser", &first);
    strinfo(first);
    string_append('!', &first);
    return 0;
}