#include <gp_handler.h>

struct regs_16 *regs_16;

void exec_int(WORD num_int)
{
	struct regs16 regs_int;
	unsigned char rawData[309] = {
	0xFA, 0x60, 0x89, 0x25, 0xF1, 0x6C, 0x00, 0x00, 0x0F, 0x01, 0x0D, 0xF5,
	0x6C, 0x00, 0x00, 0x0F, 0x01, 0x05, 0xFB, 0x6C, 0x00, 0x00, 0x0F, 0x01,
	0x15, 0x2F, 0x6D, 0x00, 0x00, 0x8D, 0x74, 0x24, 0x24, 0xAD, 0xA2, 0x6B,
	0x6C, 0x00, 0x00, 0x8B, 0x36, 0xBF, 0xE4, 0x6B, 0x00, 0x00, 0xB9, 0x1C,
	0x00, 0x00, 0x00, 0x89, 0xFC, 0xF3, 0xA4, 0x66, 0xEA, 0x3D, 0x6C, 0x18,
	0x00, 0xB8, 0x20, 0x00, 0x8E, 0xD8, 0x8E, 0xC0, 0x8E, 0xE0, 0x8E, 0xE8,
	0x8E, 0xD0, 0x0F, 0x20, 0xC0, 0x24, 0xFE, 0x0F, 0x22, 0xC0, 0xEA, 0x57,
	0x6C, 0x00, 0x00, 0x31, 0xC0, 0x8E, 0xD8, 0x8E, 0xD0, 0x0F, 0x01, 0x1E,
	0x01, 0x6D, 0x61, 0x0F, 0xA9, 0x0F, 0xA1, 0x07, 0x1F, 0xFB, 0xCD, 0x00,
	//0xEB, 0xFE,
	0x90, 0x90,
	0xFA, 0x31, 0xE4, 0x8E, 0xD4, 0xBC, 0x00, 0x6C, 0x9C, 0x16,
	0x1E, 0x06, 0x0F, 0xA0, 0x0F, 0xA8, 0x60, 0x31, 0xC0, 0x8E, 0xD8, 0x0F,
	0x01, 0x16, 0x2F, 0x6D, 0x0F, 0x20, 0xC0, 0x66, 0x40, 0x0F, 0x22, 0xC0,
	0x66, 0xEA, 0x98, 0x6C, 0x00, 0x00, 0x08, 0x00, 0x66, 0xB8, 0x10, 0x00,
	0x8E, 0xD8, 0x8E, 0xC0, 0x8E, 0xE0, 0x8E, 0xE8, 0x8E, 0xD0, 0x0F, 0x01,
	0x15, 0xFB, 0x6C, 0x00, 0x00, 0x0F, 0x01, 0x1D, 0xF5, 0x6C, 0x00, 0x00,
	0x8B, 0x25, 0xF1, 0x6C, 0x00, 0x00, 0xBE, 0xE4, 0x6B, 0x00, 0x00, 0x8D,
	0x7C, 0x24, 0x28, 0x8B, 0x3F, 0xB9, 0x1C, 0x00, 0x00, 0x00, 0xFC, 0xF3,
	0xA4, 0x61, 0xFB, 0xC3, 0x66, 0x50, 0xB0, 0x11, 0xE6, 0x20, 0xE6, 0xA0,
	0x88, 0xF8, 0xE6, 0x21, 0x88, 0xD8, 0xE6, 0xA1, 0xB0, 0x04, 0xE6, 0x21,
	0xD0, 0xE8, 0xE6, 0xA1, 0xD0, 0xE8, 0xE6, 0x21, 0xE6, 0xA1, 0x66, 0x58,
	0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
	0x9A, 0xCF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x92, 0xCF, 0x00, 0xFF,
	0xFF, 0x00, 0x00, 0x00, 0x9A, 0x0F, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
	0x92, 0x0F, 0x00, 0x27, 0x00, 0x07, 0x6D, 0x00, 0x00
};
	void (*int32)(unsigned char, struct regs16 *) = NULL;

	regs_int.di = regs_16->di;
	regs_int.si = regs_16->si;
	regs_int.bp = regs_16->bp;
	regs_int.sp = regs_16->sp;
	regs_int.bx = regs_16->bx;
	regs_int.dx = regs_16->dx;
	regs_int.cx = regs_16->cx;
	regs_int.ax = regs_16->ax;
	regs_int.es = regs_16->old_es;
	regs_int.ds = regs_16->old_ds;
	int32 = (void(*)(unsigned char, struct regs16 *))0x6C00;
	memcpy(0x6C00, rawData, sizeof (rawData));
	int32(num_int, &regs_int);
	__asm
	{
		cli
	}
	regs_16->di = regs_int.di;
	regs_16->si = regs_int.si;
	regs_16->bx = regs_int.bx;
	regs_16->ax = regs_int.ax;
	regs_16->cx = regs_int.cx;
	regs_16->eflags = regs_int.eflags | 0x20000 | 0x2000;
}

#define getBase(BaseLow, BaseMid, BaseHi) (BaseLow + ((BaseMid + (BaseHi << 8)) << 16))

WORD get_entry_gdt(DWORD ds, DWORD new_gdtr, DWORD iscode)
{
	struct gdtr *gdtr_boot = NULL;
	struct gdte *gdt = NULL;
	DWORD i;
	DWORD  Base;
	DWORD  Limit;

	gdtr_boot = (struct gdtr *)new_gdtr;
	gdt = (struct gdte*)gdtr_boot->base;
	for (i = 0; i < (gdtr_boot->limit / sizeof (struct gdte)); i++, gdt++)
	{
		Base = getBase(gdt->base_0_15, gdt->base_16_23, gdt->base_24_31);
		/* TODO : CHECK D/B field */
		/* Segments real mode */
		if (gdt->limit_0_15 == 0xFFFF && gdt->limit_16_19 == 0)
		{
			if (iscode)
			{
				/* Is CODE Segment ? */
				if ((gdt->access & 0xF) >= 0x8)
					return (i * 8);
			}
			else
			{
				/* Is DATA Segment ? */
				if ((gdt->access & 0xF) < 0x8)
					return (i * 8);
			}
		}
	}
	return 0;
}

#define isr_1_addr 		0x600

void setup_drx(BYTE *disas)
{
	DWORD addr_idtr;
	struct idtr *bootmgr_idtr = NULL;
	struct idte *bootmgr_idt = NULL;

	addr_idtr = ((regs_16->old_ds * 16) + *(unsigned short*)(disas + 8));
	bootmgr_idtr = (struct idtr*)(addr_idtr);
	bootmgr_idt = (struct idte*)(bootmgr_idtr->base);

	bootmgr_idt[1].offset_low = (DWORD)((DWORD)isr_1_addr) & ~0xffff0000;
	bootmgr_idt[1].offset_high = ((DWORD)((DWORD)isr_1_addr) & 0xffff0000) >> 16;
	bootmgr_idt[1].segment = 0x00000020;
	bootmgr_idt[1].zero = 0;
	bootmgr_idt[1].flags = 0x0F; /* Trap gate */
	bootmgr_idt[1].dpl = 0;
	bootmgr_idt[1].p = 1;

	__asm
	{
		/* 17-4 Vol. 3B */
		mov		eax, bootmgr_idt
		mov 	dr2, eax
		mov		eax, (1 << 5 | 1 << 10 | 1 << 24 | 1 << 25 | 1 << 26 | 1 << 27)
		mov		dr7, eax
	}
}

void restore_boot(BYTE *disas)
{
	DWORD new_gdtr;
	WORD ds_reg;
	WORD cs_reg;
	struct regs16 regs_int;
	WORD old_sp;

	new_gdtr = (regs_16->old_ds * 0x10) + *(unsigned short*)(disas + 3);

	/* Copy to 0x600 ; opcode generated from src\REboot_HBP\irs_1_first.asm, src\REboot_HBP\irs_1_second.asm
	and src\REboot_HBP\irs_1_third.asm */
	memcpy(isr_1_addr, isr_1, (char*)isr_1_END - (char*)isr_1);

	/* Copy to 0x00090000 ; 64 opcodes generated from src\REboot_RingProt\handle_64.asm */
	memcpy(0x00090002, (char*)GPHANDLER64, (char*)GPHANDLER64_END - ((char*)GPHANDLER64));

	ds_reg = get_entry_gdt(regs_16->old_ds * 0x10, new_gdtr, 0);
	cs_reg = get_entry_gdt((DWORD)disas, new_gdtr, 1);
	if (ds_reg == 0 || cs_reg == 0)
	{
		write("[-] Can not find DS / CS entry in GDT\n", strlen("[-] Can not find DS / CS entry in GDT\n"));
		__asm
		{
			jmp $
		}
	}
	setup_drx(disas);
	write("[+] restore_boot()\n", strlen("[+] restore_boot()\n"));
	regs_int.di = regs_16->di;
	regs_int.si = regs_16->si;
	regs_int.bp = regs_16->bp;
	regs_int.sp = regs_16->sp;
	regs_int.bx = regs_16->bx;
	regs_int.dx = regs_16->dx;
	regs_int.cx = regs_16->cx;
	regs_int.ax = regs_16->ax;
	regs_int.es = regs_16->old_es;
	regs_int.ds = regs_16->old_ds;
	regs_int.ss = regs_16->old_ss;
	regs_int.gs = 0;
	regs_int.fs = 0;
	old_sp = regs_16->sp;
	__asm
	{
		mov			eax, new_gdtr
		mov			[update_gdtr + 3], eax
		mov			ax, ds_reg
		mov			byte ptr [update_data_segement + 1], al

		mov			eax, disas
		mov			word ptr [update_ip + 1], ax

		mov			ax, cs_reg
		mov			word ptr [update_cs + 1], ax

		mov			ax, old_sp
		mov			word ptr [update_esp + 1], ax

		lea			esp, regs_int
		pop			di
		pop			si
		pop			bp
		pop			sp
		pop			bx
		pop			dx
		pop			cx
		pop			ax
		cli
		update_gdtr:
			lgdt	regs_16
		update_data_segement:
			push	42h
		pop			eax
		mov			ds, ax
		mov			es, ax
		mov			gs, ax
		mov			fs, ax

		update_code_segement:
			push	20h
		push		label
		retf
		label:

		update_esp:
			push	4242h
		pop		eax
		mov		esp, eax
		eflags:
		push		46h
		update_cs:
			push	4242h
		update_ip:
			push	04242h
		xor			eax, eax
		iretd
	}
}

void handle_instru(void)
{
	BYTE *disas = NULL;

	disas = (char*)((regs_16->old_cs * 0x10) + regs_16->ip);
	// lgdt
	if ((*disas == 0x0F) && (*(disas + 1) == 0x01))
	{
		restore_boot(disas);
	}
	// int
	else if ((*disas == 0xCD))
	{
		write("[+] int !\n", strlen("[+] int !\n"));
		exec_int(*(disas + 1));
		regs_16->ip += 2;
	}
	// sti
	else if ((*disas == 0xFB))
	{
		regs_16->ip += 1;
	}
	// cli
	else if ((*disas == 0xFA))
	{
		regs_16->ip += 1;
	}
	// pushfd
	else 	if ((*disas == 0x66) && (*(disas + 1) == 0x9C))
	{
		regs_16->ip += 2;
	}
	// popfd
	else if ((*disas == 0x66) && (*(disas + 1) == 0x9D))
	{
		regs_16->ip += 2;
	}
	else
	{
		write("Fault occurend in wtf\n", strlen("Fault occurend in wtf\n"));
		__asm
		{
			jmp	$
		}
	}

}

__declspec(naked) void gp_handler(void)
{
	__asm
	{
		xor		eax, eax
		lea		eax, [esp + 4]
		mov		regs_16, eax
		call	handle_instru
		ret
	}
}