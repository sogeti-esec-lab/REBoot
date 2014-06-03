.686p
.model small, C

PUBLIC	enter_v86

EXTERN	set_tss_esp0:NEAR
EXTERN  drive_number:DWORD

.code

enter_v86 proc
	mov		eax, 01000000h
	push 	eax
	call	set_tss_esp0
	pop 	eax
	pushf
	pop 	eax
	or 		eax, 20000h		; VM
	or 		eax, 2000h		; Class Interrupt
	push 	eax				; EFLAGS
	push 	0h				; CS
	push 	7C00h			; IP
	xor 	eax, eax
	xor 	ecx, ecx
	mov 	edx, drive_number
	xor 	ebx, ebx
	xor 	ebp, ebp
	xor 	esi, esi
	xor 	edi, edi
	xor 	eax, eax
	iretd
enter_v86 endp

end