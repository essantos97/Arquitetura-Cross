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
	.file	"codigo11.c"
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
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #28
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	mov	r3, #1000
	str	r3, [r7, #8]
	mov	r3, #2000
	str	r3, [r7, #12]
	movw	r3, #63536
	movt	r3, 65535
	str	r3, [r7, #16]
	ldr	r2, [r7, #8]
	ldr	r3, [r7, #12]
	cmp	r2, r3
	ble	.L2
	movs	r3, #1
	str	r3, [r7, #20]
	b	.L3
.L2:
	mov	r3, #-1
	str	r3, [r7, #20]
.L3:
	ldr	r2, [r7, #8]
	ldr	r3, [r7, #16]
	cmp	r2, r3
	bge	.L4
	movs	r3, #2
	str	r3, [r7, #20]
	b	.L5
.L4:
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #16]
	cmp	r2, r3
	ble	.L5
	mvn	r3, #1
	str	r3, [r7, #20]
.L5:
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #28
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu1) 9.3.0"
	.section	.note.GNU-stack,"",%progbits
