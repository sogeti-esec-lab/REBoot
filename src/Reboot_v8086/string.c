#include <string.h>

void *memset(void *s, int c, size_t n)
{
	unsigned char *p = NULL;

	for (p = s; n > 0; n--, p++)
		*p = c;

	return (s);
}

size_t	strlen(const char *s)
{
	const char *p = NULL;

	for (p = s; *p != '\0'; p++)
		continue;

	return (p - s);
}

void *memcpy(void *dest, const void *src, size_t n)
{
	const char *s = src;
	char *d = dest;

	for (; n > 0; n--, d++, s++)
		*d = *s;

	return (dest);
}