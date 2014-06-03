#include <kernel.h>

DWORD drive_number = 0x80;

void main(void)
{
	unsigned char rawData[512] = {
	/* Copy original MBR or asm code to read it (original_mbr.asm) */
	};

	init_screen();
	init_mem();
	init_interrupt();
	memcpy(0x7C00, rawData, 512);
	enter_v86();
	__asm
	{
			jmp $
	}
}