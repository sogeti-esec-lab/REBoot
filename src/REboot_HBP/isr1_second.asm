;-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
; Second Debug ISR called during memset()
; TODO : DESACTIVER DR7, KEEP IT SIMPLE
;-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
isr_1_2:

	push	eax
	push	ebx
	push	ecx
	; emulate memset() operation
	mov		ecx, (16 - 4)
	xor		eax, eax
	rep		stosb	
	pop		ecx
	mov		eax, (isr_1_3 - isr_1)
	add		eax, 600h
	mov		word ptr [edi], ax				; Offset low
	mov		word ptr [edi + 2], 010h		; Selector : TODO FIX HARDCODED SEGMENT
	mov		byte ptr [edi + 4], 0			; Zero
	mov		byte ptr [edi + 5], 8Eh			; Type And Attributes
	mov		word ptr [edi + 6], 0			; Offset middle bits
	mov		dword ptr [edi + 8], 0			; Offset high bits
	mov		dword ptr [edi + 12], 0			; Zero
	; DO THE REP STOSB TO AVOID TRAP !
	; OR PUT A BOOLEAN AT START OF THIS TRAP HANDLER
	push	edi
	add		edi, 10h
	sub		ecx, ((16 - 4) + 16) / 4
	xor		eax, eax
	rep		stosb
	pop		edi
	; UPDATE DRX
	mov		eax, edi
	add		eax, 28h
	mov		dr2, eax
	; reset stosb
	xor		ecx, ecx
	pop		ebx
	pop		eax
	iretd