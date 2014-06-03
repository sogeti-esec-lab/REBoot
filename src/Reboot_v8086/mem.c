#include <mem.h>

static struct gdtr gdtr;
static struct gdte gdt[10];
static struct tss tss;

int set_gdt_gate(DWORD base, DWORD limit, BYTE access, BYTE granularity, int n)
{
	struct gdte* gdte = &gdt[n];

	gdte->limit_0_15 = 0xffff & limit;
	gdte->base_0_15 = 0xffff & base;
	gdte->base_16_23 = (0xff0000 & base) >> 16;
	gdte->access = access;
	gdte->p = 1;
	gdte->limit_16_19 = (0xf0000 & limit) >> 16;
	gdte->avl = 0;
	gdte->l = 0;
	gdte->granularity = granularity;
	gdte->base_24_31 = (~0xffff & base) >> 24;
	return 1;
}

void init_mem(void)
{
	unsigned int i;

	memset(&gdt, 0, sizeof (gdt));
	memset(&tss, 0, sizeof (tss));

	tss.io_map_base_address = (WORD)&tss.io - (WORD)&tss;
	tss.eflags = 0x23202; //(1 << 17) + (3 << 12) + (1 << 14);
	write("[+] v8086 go go !\n", strlen("[+] v8086 go go !\n"));

	set_gdt_gate(0, 0xffff, CODE_SEGMENT(0), 3, KERNEL_CS);
	set_gdt_gate(0, 0xffff, DATA_SEGMENT(0), 3, KERNEL_DS);
	set_gdt_gate((DWORD)&tss, sizeof(tss), TSS_SEGMENT(0), 3, KERNEL_TSS);

	gdtr.base = (DWORD)&gdt;
	gdtr.limit = sizeof(gdt) - 1;
	__asm
	{
			/* Load GDT */
			lgdt gdtr

			/* Setup PROTECTED MODE */
			mov eax, cr0
			or  eax, 0x1
			mov cr0, eax

			/* Reload segments registers */
			mov ax, KERNEL_DATA_SELECTOR
			mov ds, ax
			mov ss, ax
			mov es, ax
			mov fs, ax
			mov gs, ax

			/* reloc cs */
			push KERNEL_CODE_SELECTOR
			push label_prot
			retf
			label_prot:
	}
	__asm
	{
			mov eax, KERNEL_TSS_SELECTOR
			ltr ax
	}
}

void set_tss_esp0(DWORD esp0)
{
	tss.ss0 = KERNEL_DATA_SELECTOR;
	tss.esp0 = esp0;
}