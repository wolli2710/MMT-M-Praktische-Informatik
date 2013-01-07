	.text
	.globl calc_expr
calc_expr:
	movl	$4, %eax
	pushl	%eax
	movl	$5, %eax
	popl	%ebx
	imul	%ebx, %eax
	pushl	%eax
	movl	$10, %eax
	popl	%ebx
	ja	return_ebx
	retl
return_ebx:	 movl	 %ebx, %eax
	retl
	retl
