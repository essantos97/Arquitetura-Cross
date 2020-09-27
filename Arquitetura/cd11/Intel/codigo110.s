	.file	"codigo11.c"
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
	mov	DWORD PTR -20[rbp], edi
	mov	QWORD PTR -32[rbp], rsi
	mov	DWORD PTR -16[rbp], 1000
	mov	DWORD PTR -12[rbp], 2000
	mov	DWORD PTR -8[rbp], -2000
	mov	eax, DWORD PTR -16[rbp]
	cmp	eax, DWORD PTR -12[rbp]
	jle	.L2
	mov	DWORD PTR -4[rbp], 1
	jmp	.L3
.L2:
	mov	DWORD PTR -4[rbp], -1
.L3:
	mov	eax, DWORD PTR -16[rbp]
	cmp	eax, DWORD PTR -8[rbp]
	jge	.L4
	mov	DWORD PTR -4[rbp], 2
	jmp	.L5
.L4:
	mov	eax, DWORD PTR -12[rbp]
	cmp	eax, DWORD PTR -8[rbp]
	jle	.L5
	mov	DWORD PTR -4[rbp], -2
.L5:
	mov	eax, 0
	pop	rbp
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
