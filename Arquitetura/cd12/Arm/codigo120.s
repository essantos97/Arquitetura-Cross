	.arch armv8-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"codigo12.c"
	.text
	.align	1
	.global	main
	.arch armv8-a
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfpv3-d16
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #44
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	mov	r2, #0
	mov	r3, #16384
	movt	r3, 16527
	strd	r2, [r7, #16]
	mov	r2, #0
	mov	r3, #16384
	movt	r3, 16543
	strd	r2, [r7, #24]
	adr	r3, .L15
	ldrd	r2, [r3]
	strd	r2, [r7, #32]
	vldr.64	d6, [r7, #16]
	vldr.64	d7, [r7, #24]
	vcmpe.f64	d6, d7
	vmrs	APSR_nzcv, FPSCR
	ble	.L13
	movs	r3, #1
	str	r3, [r7, #12]
	b	.L4
.L13:
	mov	r3, #-1
	str	r3, [r7, #12]
.L4:
	vldr.64	d6, [r7, #16]
	vldr.64	d7, [r7, #32]
	vcmpe.f64	d6, d7
	vmrs	APSR_nzcv, FPSCR
	bpl	.L14
	movs	r3, #2
	str	r3, [r7, #12]
	b	.L7
.L14:
	vldr.64	d6, [r7, #24]
	vldr.64	d7, [r7, #32]
	vcmpe.f64	d6, d7
	vmrs	APSR_nzcv, FPSCR
	ble	.L7
	mvn	r3, #1
	str	r3, [r7, #12]
.L7:
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #44
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
.L16:
	.align	3
.L15:
	.word	0
	.word	-1063305216
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu1) 9.3.0"
	.section	.note.GNU-stack,"",%progbits
