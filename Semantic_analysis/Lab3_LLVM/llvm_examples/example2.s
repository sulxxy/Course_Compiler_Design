	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_fun_a
	.p2align	4, 0x90
_fun_a:                                 ## @fun_a
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_fun_b
	.p2align	4, 0x90
_fun_b:                                 ## @fun_b
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	imull	%eax, %eax
	addl	%esi, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_fun_c
	.p2align	4, 0x90
_fun_c:                                 ## @fun_c
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	movl	%edi, -16(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	LBB2_1
	.p2align	4, 0x90
LBB2_2:                                 ##   in Loop: Header=BB2_1 Depth=1
	movl	-12(%rbp), %eax
	imull	-4(%rbp), %eax
	addl	%eax, -8(%rbp)
	incl	-4(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	LBB2_2
## BB#3:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -28(%rbp)
	movl	$10, -4(%rbp)
	movl	$30, -8(%rbp)
	callq	_fun_a
	movl	-4(%rbp), %edi
	movl	-8(%rbp), %esi
	callq	_fun_b
	movl	%eax, -16(%rbp)
	movl	-4(%rbp), %edi
	movl	-8(%rbp), %esi
	callq	_fun_c
	movl	%eax, -12(%rbp)
	movl	-4(%rbp), %edi
	movl	%edi, %esi
	callq	_fun_b
	movl	%eax, -24(%rbp)
	movl	-16(%rbp), %edi
	movl	-12(%rbp), %esi
	callq	_fun_b
	movl	%eax, %ecx
	movl	%ecx, -20(%rbp)
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	_printf
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"result is %d\n"


.subsections_via_symbols
