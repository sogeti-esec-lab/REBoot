#ifndef __GP_HANDLER_H__
#define __GP_HANDLER_H__

#include <kernel.h>
#include <mem.h>
#include <interrupt.h>

void gp_handler(void);

#pragma pack(push, 1)
struct regs16
{
	unsigned short di, si, bp, sp, bx, dx, cx, ax;
	unsigned short gs, fs, es, ds, ss, eflags;
};
#pragma pack(pop)

extern void isr_1(void);
extern void isr_1_END(void);

extern void GPHANDLER64(void);
extern void GPHANDLER64_END(void);

#pragma pack(push, 1)
struct regs_16
{
	WORD di;
	WORD di_pad;
	WORD si;
	WORD si_pad;
	WORD dx;
	WORD dx_pad;
	WORD cx;
	WORD cx_pad;
	WORD es;
	WORD es_pad;
	WORD ds;
	WORD ds_pad;
	WORD bx;
	WORD bx_pad;
	WORD bp;
	WORD bp_pad;
	WORD ax;
	WORD ax_pad;
	/* 16 - 18 Vol.3 */
	DWORD error_code;
	WORD ip;
	WORD ip_padding;
	WORD old_cs;
	WORD old_cs_padding;
	DWORD eflags;
	WORD sp;
	WORD sp_padding;
	WORD old_ss;
	WORD old_ss_padding;
	WORD old_es;
	WORD old_es_padding;
	WORD old_ds;
	WORD old_ds_padding;
	WORD old_fs;
	WORD old_fs_padding;
	WORD old_gs;
	WORD old_gs_padding;
};
#pragma pack(pop)

#endif /* __GP_HANDLER_H__ */