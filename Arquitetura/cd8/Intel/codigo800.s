	.file	"codigo8.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	lea	r11, -24576[rsp]
.LPSRL0:
	sub	rsp, 4096
	or	DWORD PTR [rsp], 0
	cmp	rsp, r11
	jne	.LPSRL0
	sub	rsp, 48
	mov	DWORD PTR -24612[rbp], edi
	mov	QWORD PTR -24624[rbp], rsi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	DWORD PTR -24596[rbp], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR -24596[rbp]
	cdqe
	movsd	xmm1, QWORD PTR -24592[rbp+rax*8]
	mov	eax, DWORD PTR -24596[rbp]
	cdqe
	movsd	xmm0, QWORD PTR -16400[rbp+rax*8]
	addsd	xmm0, xmm1
	mov	eax, DWORD PTR -24596[rbp]
	cdqe
	movsd	QWORD PTR -8208[rbp+rax*8], xmm0
	add	DWORD PTR -24596[rbp], 1
.L2:
	cmp	DWORD PTR -24596[rbp], 1023
	jle	.L3
	mov	eax, 0
	mov	rdx, QWORD PTR -8[rbp]
	xor	rdx, QWORD PTR fs:40
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
