.386p
.MODEL small, C

EXTERN PM_interrupt_handler:proc

ISR_NO_ERROR MACRO num
	isr_&num PROTO

	isr_&num PROC

	push	0h
	push	&num
	mov		eax, &num
	jmp		isr_common
	isr_&num ENDP

ENDM

ISR_ERROR MACRO num
	isr_&num PROTO

	isr_&num PROC

	push	eax
	mov		eax, &num
	jmp		isr_common
	isr_&num ENDP

ENDM

.code

ISR_NO_ERROR 	0
ISR_NO_ERROR 	2
ISR_NO_ERROR 	3
ISR_NO_ERROR 	4
ISR_NO_ERROR 	5
ISR_NO_ERROR 	6
ISR_NO_ERROR 	7
ISR_ERROR 		8
ISR_NO_ERROR 	9
ISR_ERROR 		10
ISR_ERROR 		11
ISR_ERROR 		12
ISR_ERROR 		13
ISR_ERROR 		14
ISR_NO_ERROR 	16
ISR_ERROR 		17
ISR_NO_ERROR 	18
ISR_NO_ERROR 	19
ISR_NO_ERROR 	32
ISR_NO_ERROR 	33
ISR_NO_ERROR 	35
ISR_NO_ERROR 	36
ISR_NO_ERROR 	37
ISR_NO_ERROR 	38
ISR_NO_ERROR 	39
ISR_NO_ERROR 	40
ISR_NO_ERROR 	41
ISR_NO_ERROR 	42
ISR_NO_ERROR 	43
ISR_NO_ERROR 	44
ISR_NO_ERROR 	45
ISR_NO_ERROR 	46
ISR_NO_ERROR 	47

isr_common:
	cli
	push	ebp				
	push    ebx				
	push    ds				
	push	es				
	push	ecx				
	push	edx				
	push	esi				
	push	edi				
	mov     ebx, 10h
	mov     ds, bx
	mov		es, bx
	call 	PM_interrupt_handler[eax * 4]
	pop 	edi
	pop 	esi
	pop 	edx
	pop 	ecx
	pop 	es
	pop		ds
	pop 	ebx
	pop		ebp
	pop 	eax
	add 	esp, 4
	sti
	iretd

end