	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_foo
	.p2align	4, 0x90
_foo:                                   ## @foo
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
	pushq	%rbx
	pushq	%rax
Ltmp3:
	.cfi_offset %rbx, -24
	movl	%edi, -16(%rbp)
	movl	$0, -12(%rbp)
	leaq	L_.str(%rip), %rbx
	jmp	LBB0_1
	.p2align	4, 0x90
LBB0_2:                                 ##   in Loop: Header=BB0_1 Depth=1
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	incl	-12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jb	LBB0_2
## BB#3:
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp4:
	.cfi_def_cfa_offset 16
Ltmp5:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp6:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-4(%rbp), %edi
	callq	_foo
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello\n"


.subsections_via_symbols
