#ifndef __STRING_H__
#define __STRING_H__

#include <kernel.h>

void *memset(void *s, int c, size_t n);
size_t	strlen(const char *s);
void *memcpy(void *dest, const void *src, size_t n);

#endif /* __STRING_H__ */

