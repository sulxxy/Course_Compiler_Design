	.file	"example2.bc"
	.text
	.globl	fun_a
	.align	16, 0x90
	.type	fun_a,@function
fun_a:                                  # @fun_a
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
.Ltmp0:
	.size	fun_a, .Ltmp0-fun_a

	.globl	fun_b
	.align	16, 0x90
	.type	fun_b,@function
fun_b:                                  # @fun_b
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %ecx
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	%ecx, -8(%ebp)
	movl	-4(%ebp), %eax
	imull	%eax, %eax
	addl	%ecx, %eax
	addl	$8, %esp
	popl	%ebp
	ret
.Ltmp1:
	.size	fun_b, .Ltmp1-fun_b

	.globl	fun_c
	.align	16, 0x90
	.type	fun_c,@function
fun_c:                                  # @fun_c
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, -4(%ebp)
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	.LBB2_1
	.align	16, 0x90
.LBB2_2:                                #   in Loop: Header=BB2_1 Depth=1
	movl	-8(%ebp), %eax
	imull	-16(%ebp), %eax
	addl	%eax, -12(%ebp)
	incl	-16(%ebp)
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	movl	-16(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jl	.LBB2_2
# BB#3:
	movl	-12(%ebp), %eax
	addl	$16, %esp
	popl	%ebp
	ret
.Ltmp2:
	.size	fun_c, .Ltmp2-fun_c

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -4(%ebp)
	movl	$10, -8(%ebp)
	movl	$30, -12(%ebp)
	calll	fun_a
	movl	-8(%ebp), %eax
	movl	-12(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	calll	fun_b
	movl	%eax, -16(%ebp)
	movl	-8(%ebp), %eax
	movl	-12(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	calll	fun_c
	movl	%eax, -20(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	calll	fun_b
	movl	%eax, -24(%ebp)
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	calll	fun_b
	movl	%eax, -28(%ebp)
	movl	%eax, 4(%esp)
	movl	$.L.str, (%esp)
	calll	printf
	xorl	%eax, %eax
	addl	$40, %esp
	popl	%ebp
	ret
.Ltmp3:
	.size	main, .Ltmp3-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"result is %d\n"
	.size	.L.str, 14


	.ident	"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"
	.section	".note.GNU-stack","",@progbits
