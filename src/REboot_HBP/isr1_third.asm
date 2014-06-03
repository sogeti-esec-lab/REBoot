;-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
; Third Debug ISR called during memset()
; 64bit (Long mode) prefix : 0x48
;-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
isr_1_3:
	
	push	edi
	push	esi
	push	ecx
	; sub	rsp, 38
	; ALLOCATE STACK FRAME FOR SGDT INSTRUCTION
	db 		048h , 083h, 0ECh, 038h
	; clean dbg register
	xor		eax, eax
	mov		dr0, eax
	mov		dr2, eax
	mov		dr7, eax
	; lea     rcx, [rsp + 20h]
	db		048h, 08Dh, 04Ch, 024h, 020h
	; sgdt    fword ptr [rcx]
	db		00Fh, 001h, 001h
	; mov     rdi, [rsp + 22h]
	db		048h, 08bh, 07ch, 024h, 022h
	; COPY ENTRY 0x10 -> 0x8
	add		edi, 08h
	lea		esi, [edi + 08h]
	mov		ecx, 08h
	rep		movsb
	
	; COPY ENTRY 0x20 -> 0x18 
	add		edi, 08h
	lea		esi, [edi + (3 * 08h)]
	mov		ecx, 08h
	rep		movsb
	
	; Change code entry Type (especially DPL)
	sub		edi, (08h * 2)
	mov		byte ptr[edi + 05h], 0BBh
	
	; Change data entry Type (especially DPL)
	add		edi, 08h
	mov		byte ptr [edi + 05h], 0B3h
	
	; SETUP TSS
	; str	rax
	db		00Fh, 00h, 0C8h
	sub		edi, (08h * 3)
	lea		edi, [edi + eax]
	mov		eax, [edi + 2h]
	and		eax, 000FFFFFFh
	mov		dword ptr [eax + 4], 98000h
	mov		eax, 040h
	; ltr rax
	db		00Fh, 000h, 0D8h
	
	; SETUP GP Handler
	; rdi = start of idt
	; GP (0xD) : hex(0xD * 16) = 0xd0
	mov		word ptr [edx + 0d0h], 0000h            ; Offset low
	mov		word ptr [edx + 0d0h + 2], 08h			; Selector
	mov		byte ptr [edx + 0d0h + 4], 0			; Zero
	mov		byte ptr [edx + 0d0h + 5], 8Eh			; Type And Attributes
	; We should define offset of GP Handler ...
	mov		word ptr [edx + 0d0h + 6], 09h			; Offset middle bits
	mov		dword ptr [edx + 0d0h + 8], 0h			; Offset high bits
	mov		dword ptr [edx + 0d0h + 12], 0			; Zero
	
	xor			ecx, ecx
	mov			dr0, ecx
	mov			dr1, ecx
	mov			dr2, ecx
	mov			dr3, ecx
	mov			dr7, ecx
	
	; add     rsp, 38h
	db 		048h, 083h, 0C4h, 038h       
	pop		ecx
	pop		esi
	pop		edi
	; NEW RPL CS
	mov		dword ptr [esp + 8h], 11h	
	; NEW RPL SS	
	mov		dword ptr [esp + 20h], 19h
	
	; iretq
	db		048h, 0CFh