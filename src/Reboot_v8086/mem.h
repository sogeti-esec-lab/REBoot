#ifndef __MEM_H__
#define __MEM_H__

#include <kernel.h>

#pragma pack(push,1)
struct gdte
{
	WORD limit_0_15;
	WORD base_0_15;
	BYTE base_16_23;
	BYTE access:7;
	BYTE p:1;
	BYTE limit_16_19:4;
	BYTE avl:1;
	BYTE l:1;
	BYTE granularity:2;
	BYTE base_24_31;
};
#pragma pack(pop)

#pragma pack(push,1)
struct gdtr
{
	WORD limit;
	DWORD base;
};
#pragma pack(pop)

#pragma pack(push,1)
struct tss
{
  DWORD link,
		esp0,
		ss0,
		esp1,
		ss1,
		esp2,
		ss2,
		cr3,
		eip,
		eflags,
		eax,
		ecx,
		edx,
		ebx,
		esp,
		ebp,
		esi,
		edi,
		es,
		cs,
		ss,
		ds,
		fs,
		gs,
		ldtr;
  WORD trace, io_map_base_address;
  BYTE io[8192];
};
#pragma pack(pop)

void init_mem(void);
void set_tss_esp0(DWORD esp0);

#endif /* __MEM_H__ */