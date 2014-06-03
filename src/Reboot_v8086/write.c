#include <kernel.h>

static char *fb = NULL;
static int x = 0;
static int y = 0;
static int text_attr = 0;

static void clear_fb(void)
{
	memset(fb, 0, 80 * 25 * 2);
}

static void set_attr(const int back, const int front)
{
	text_attr = CONS_BACK(back) + CONS_FRONT(front);
}

static void scroll(size_t nbline)
{
	int i;

	x = 0;
	y = 25 - nbline;
	for (i = nbline * 80 * 2; i < 80 * 25 * 2; i++)
		fb[i - nbline * 80 * 2] = fb[i];
	for (i = 80 * 25 * 2 - nbline * 80 * 2; i < 80 * 25 * 2; i++)
		fb[i] = 0;
}

static void up_cursor(void)
{
	x++;
	if (x >= 80)
	{
		x = 0;
		if (++y == 25)
			scroll(1);
	}
}

static void putc(const char c)
{
	switch (c)
	{
	case '\n':
		x = 79;
		up_cursor();
		return;
	case '\r':
		x = 0;
		return;
	case '\t':
		do
		putc(' ');
		while (x % 4);
		return;
	}
	fb[(y * 80 + x) * 2] = c;
	fb[(y * 80 + x) * 2 + 1] = text_attr;
	up_cursor();
}

void init_screen(void)
{
	fb = (void *)0xb8000;
	set_attr(CONS_BLACK, CONS_WHITE);
	clear_fb();
	x = 0;
	y = 0;
}

int write(const char *s, size_t	length)
{
	size_t written = 0;
	size_t i = 0;

	while (i < length)
	{
	if ((unsigned char)(s[i]) == CONS_ESCAPE)
	{
		switch (s[++i])
		{
		case CONS_CLEAR:
			clear_fb();
			i++;
			break;
		case CONS_COLOR:
			text_attr = s[++i];
			i++;
			break;
		case CONS_SETY:
			y = s[++i];
			i++;
			break;
		case CONS_SETX:
			x = s[++i];
			i++;
			break;
		}
		continue;
	}
	putc(s[i++]);
	written++;
	}

	return (written);
}

