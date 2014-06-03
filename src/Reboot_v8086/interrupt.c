#include <interrupt.h>

static struct idtr PM_idtr;
struct idte PM_idt[256];
void* PM_interrupt_handler[256];

void default_handler(void)
{
	write("default_handler\n", strlen("default_handler\n"));
	__asm
	{
		jmp $
	}
	return;
}

static int interrupt_add_gate(void *f, int n)
{
	if (n >= 256)
		return -1;
	PM_idt[n].offset_low = (DWORD)f & ~0xffff0000;
	PM_idt[n].offset_high = ((DWORD)f & 0xffff0000) >> 16;
	PM_idt[n].segment = 0x08;
	PM_idt[n].zero = 0;
	PM_idt[n].flags = 0x0F;
	PM_idt[n].dpl = 0;
	PM_idt[n].p = 1;
	return 0;
}

void init_interrupt(void)
{
	int i;

	PM_idtr.base = (DWORD)PM_idt;
	PM_idtr.limit = sizeof(PM_idt) - 1;
	for (i = 0; i < 256; i++)
	{
		if (i == 0x0D)
		{
			PM_interrupt_handler[i] = gp_handler;
		}
		else
		{
			PM_interrupt_handler[i] = default_handler;
		}
	}
	__asm
	{
		lidt PM_idtr;
	}
	interrupt_add_gate(isr_0, 0);
	interrupt_add_gate(isr_2, 2);
	interrupt_add_gate(isr_3, 3);
	interrupt_add_gate(isr_4, 4);
	interrupt_add_gate(isr_5, 5);
	interrupt_add_gate(isr_6, 6);
	interrupt_add_gate(isr_7, 7);
	interrupt_add_gate(isr_8, 8);
	interrupt_add_gate(isr_9, 9);
	interrupt_add_gate(isr_10, 10);
	interrupt_add_gate(isr_11, 11);
	interrupt_add_gate(isr_12, 12);
	interrupt_add_gate(isr_13, 13);
	interrupt_add_gate(isr_14, 14);
	interrupt_add_gate(isr_16, 16);
	interrupt_add_gate(isr_17, 17);
	interrupt_add_gate(isr_18, 18);
	interrupt_add_gate(isr_19, 19);
	interrupt_add_gate(isr_32, 32);
	interrupt_add_gate(isr_33, 33);
	interrupt_add_gate(isr_35, 35);
	interrupt_add_gate(isr_36, 36);
	interrupt_add_gate(isr_37, 37);
	interrupt_add_gate(isr_38, 38);
	interrupt_add_gate(isr_39, 39);
	interrupt_add_gate(isr_40, 40);
	interrupt_add_gate(isr_41, 41);
	interrupt_add_gate(isr_42, 42);
	interrupt_add_gate(isr_43, 43);
	interrupt_add_gate(isr_44, 44);
	interrupt_add_gate(isr_45, 45);
	interrupt_add_gate(isr_46, 46);
	interrupt_add_gate(isr_47, 47);
}