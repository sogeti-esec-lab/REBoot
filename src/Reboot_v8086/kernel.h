#ifndef __KERNEL_H__
#define __KERNEL_H__

# define NULL ((void*) 0)

# define SELECTOR(Entry, Rpl)	((Entry << 3) + Rpl)

# define KERNEL_CS		1
# define KERNEL_CODE_SELECTOR		SELECTOR(KERNEL_CS, 0)
# define KERNEL_DS		2
# define KERNEL_DATA_SELECTOR		SELECTOR(KERNEL_DS, 0)
# define KERNEL_TSS		3
# define KERNEL_TSS_SELECTOR		SELECTOR(KERNEL_TSS, 0)

#define CODE_SEGMENT(Dpl)	(((Dpl) << 5) | (1 << 4) | 0xA)
#define DATA_SEGMENT(Dpl)	(((Dpl) << 5) | (1 << 4) | 0x3)
#define TSS_SEGMENT(Dlp)	(((Dlp) << 5) | 0x9)

typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

typedef unsigned int size_t;
typedef signed int ssize_t;
typedef signed int off_t;

void main(void);

#endif /* __KERNEL_H__ */
