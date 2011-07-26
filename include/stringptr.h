/*
 * author: rofl0r
 * 
 * License: LGPL 2.1+ with static linking exception
 * 
 */

#ifndef _STRINGPTR_H_
#define _STRINGPTR_H_

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *ptr;
	size_t size;
} stringptr;


#define SPLITERAL(X) &(stringptr){(X), (sizeof((X)) - 1)}

#define stringptr_grow(a, b) (stringptr*) realloc(a, b)
#define stringptr_free(a) free(a)


#ifndef DISABLE_STRINGPTR_SHORT_MACROS
#define EQ(X, Y) stringptr_eq(X, Y) 
#define SPL(X) SPLITERAL(X)
#define SDUP(X) stringptr_copy(X)
#define CHOMP(X) stringptr_chomp(X)
#endif

int stringptr_here(stringptr* haystack, size_t bufpos, stringptr* needle);
stringptr* stringptr_new(size_t size);
stringptr* stringptr_concat(stringptr* self, ...);
stringptr* stringptr_copy(stringptr* s);
int stringptr_eq(stringptr* a, stringptr* b);
int stringptr_shiftright(stringptr* s, size_t count);
int stringptr_shiftleft(stringptr* s, size_t count);
size_t stringptr_chomp(stringptr* s);
char* stringptr_strdup(stringptr* s);
char* stringptr_rchr(stringptr* haystack, int needle);
stringptr* stringptr_format(char* fmt, ...);
stringptr* stringptr_fromfile(char* filename);
size_t stringptr_tofile(char* filename, stringptr* buffer);

#ifdef __cplusplus
}
#endif

#endif

//RcB: DEP "../src/stringptr/stringptr_*.c"
