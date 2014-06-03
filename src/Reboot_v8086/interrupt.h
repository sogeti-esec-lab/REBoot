#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <kernel.h>
#include <gp_handler.h>

#pragma pack(push, 1)
struct idte
{
	WORD offset_low;
	WORD segment;
	BYTE zero;
	BYTE flags:5;
	BYTE dpl:2;
	BYTE p:1;
	WORD offset_high;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct idtr
{
	WORD limit;
	DWORD base;
};
#pragma pack(pop)

void init_interrupt(void);

extern void isr_0(void);
extern void isr_2(void);
extern void isr_3(void);
extern void isr_4(void);
extern void isr_5(void);
extern void isr_6(void);
extern void isr_7(void);
extern void isr_8(void);
extern void isr_9(void);
extern void isr_10(void);
extern void isr_11(void);
extern void isr_12(void);
extern void isr_13(void);
extern void isr_14(void);
extern void isr_16(void);
extern void isr_17(void);
extern void isr_18(void);
extern void isr_19(void);
extern void isr_32(void);
extern void isr_33(void);
extern void isr_35(void);
extern void isr_36(void);
extern void isr_37(void);
extern void isr_38(void);
extern void isr_39(void);
extern void isr_40(void);
extern void isr_41(void);
extern void isr_42(void);
extern void isr_43(void);
extern void isr_44(void);
extern void isr_45(void);
extern void isr_46(void);
extern void isr_47(void);
extern void isr_48(void);

#endif /* __INTERRUPT_H__ */