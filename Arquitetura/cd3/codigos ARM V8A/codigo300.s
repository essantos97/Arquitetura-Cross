	.arch armv8-a
	.file	"codigo3.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp, 12]
	str	x1, [sp]
	str	xzr, [sp, 24]
	ldr	d1, [sp, 24]
	fmov	d0, 1.0e+0
	fadd	d0, d1, d0
	str	d0, [sp, 24]
	mov	w0, 0
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu1) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
