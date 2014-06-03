#ifndef __WRITE_H__
#define __WRITE_H__

#include <kernel.h>

enum
{
	CONS_ESCAPE	= 255,
	CONS_CLEAR	= 1,
	CONS_COLOR	= 2,
	CONS_SETX	= 3,
	CONS_SETY	= 4,
	CONS_BLACK	= 0,
	CONS_BLUE	= 1,
	CONS_GREEN	= 2,
	CONS_CYAN	= 3,
	CONS_RED	= 4,
	CONS_MAGENTA	= 5,
	CONS_YELLOW	= 6,
	CONS_WHITE	= 7,
	CONS_BLINK	= (1 << 7),
	CONS_LIGHT	= (1 << 3)
} e_cons_codes;

# define CONS_FRONT(Color)	(Color)
# define CONS_BACK(Color)	(Color << 4)

void init_screen(void);
int write(const char *s, size_t length);

#endif /* __WRITE_H__ */

