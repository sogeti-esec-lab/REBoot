.386p
.MODEL small, C

.code

isr_1 PROTO

isr_1 PROC

	nop
	push 	eax
	push 	esi
	push 	edi
	rep		movsd
	xor		ecx, ecx
	mov		eax, (isr_1_2 - isr_1)
	add		eax, 600h
	pop		edi
	pop		esi
	push	esi
	push	edi
	sub		edi, 4
	sub		esi, 4
	mov		[edi + 8], ax
	mov		[esi + 8], ax
	mov		eax, (idt_base - isr_1)
	add		eax, 600h
	mov		[eax], esi
	db		0Fh, 01h, 1Dh
	dd		((idtr - isr_1) + 600h)
	mov		dr2, edi
	mov		eax, 3000420h
	mov		dr7, eax
	xor		ecx, ecx
	pop		edi
	pop		esi
	pop		eax
	iretd
	
idtr:
	dw 0200h
idt_base:
	dd 00000000h
	
INCLUDE isr1_second.asm

INCLUDE isr1_third.asm

isr_1 ENDP

isr_1_END PROC 
	nop
	nop
	nop
	nop
	nop
isr_1_END ENDP 

include handler64.asm

GPHANDLER64_END PROC 
	nop
	nop
	nop
	nop
	nop
GPHANDLER64_END ENDP 

end