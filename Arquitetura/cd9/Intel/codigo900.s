	.file	"codigo9.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	DWORD PTR -36[rbp], edi
	mov	QWORD PTR -48[rbp], rsi
	mov	edi, 4096
	call	malloc@PLT
	mov	QWORD PTR -24[rbp], rax
	mov	edi, 4096
	call	malloc@PLT
	mov	QWORD PTR -16[rbp], rax
	mov	edi, 4096
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	DWORD PTR -28[rbp], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR -28[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	ecx, DWORD PTR [rax]
	mov	eax, DWORD PTR -28[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR [rax]
	mov	eax, DWORD PTR -28[rbp]
	cdqe
	lea	rsi, 0[0+rax*4]
	mov	rax, QWORD PTR -8[rbp]
	add	rax, rsi
	add	edx, ecx
	mov	DWORD PTR [rax], edx
	add	DWORD PTR -28[rbp], 1
.L2:
	cmp	DWORD PTR -28[rbp], 1023
	jle	.L3
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
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
