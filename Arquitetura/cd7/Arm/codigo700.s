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
	.file	"codigo7.c"
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
	@ args = 0, pretend = 0, frame = 12304
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #12288
	sub	sp, sp, #16
	add	r7, sp, #0
	add	r3, r7, #16
	subs	r3, r3, #12
	str	r0, [r3]
	add	r3, r7, #16
	subs	r3, r3, #16
	str	r1, [r3]
	add	r3, r7, #12288
	add	r3, r3, #12
	ldr	r1, .L6
.LPIC0:
	add	r1, pc
	ldr	r2, .L6+4
	ldr	r2, [r1, r2]
	ldr	r2, [r2]
	str	r2, [r3]
	mov	r2,#0
	add	r3, r7, #16
	subs	r3, r3, #8
	movs	r2, #0
	str	r2, [r3]
	b	.L2
.L3:
	add	r3, r7, #16
	subs	r3, r3, #4
	add	r2, r7, #16
	subs	r2, r2, #8
	ldr	r2, [r2]
	ldr	r1, [r3, r2, lsl #2]
	add	r3, r7, #4096
	add	r3, r3, #16
	subs	r3, r3, #4
	add	r2, r7, #16
	subs	r2, r2, #8
	ldr	r2, [r2]
	ldr	r3, [r3, r2, lsl #2]
	add	r1, r1, r3
	add	r3, r7, #8192
	add	r3, r3, #16
	subs	r3, r3, #4
	add	r2, r7, #16
	subs	r2, r2, #8
	ldr	r2, [r2]
	str	r1, [r3, r2, lsl #2]
	add	r3, r7, #16
	subs	r3, r3, #8
	add	r2, r7, #16
	subs	r2, r2, #8
	ldr	r2, [r2]
	adds	r2, r2, #1
	str	r2, [r3]
.L2:
	add	r3, r7, #16
	subs	r3, r3, #8
	ldr	r3, [r3]
	cmp	r3, #1024
	blt	.L3
	movs	r3, #0
	add	r2, r7, #12288
	add	r2, r2, #12
	ldr	r0, .L6+8
.LPIC1:
	add	r0, pc
	ldr	r1, .L6+4
	ldr	r1, [r0, r1]
	ldr	r0, [r1]
	ldr	r1, [r2]
	eors	r0, r1, r0
	beq	.L5
	bl	__stack_chk_fail(PLT)
.L5:
	mov	r0, r3
	add	r7, r7, #12288
	adds	r7, r7, #16
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+4)
	.word	__stack_chk_guard(GOT)
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC1+4)
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu1) 9.3.0"
	.section	.note.GNU-stack,"",%progbits
