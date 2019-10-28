.text 			# Code Section
.globl main			# main needs to be global

main:				# Label for main
	# Prepare to call add8(a,b,c,d,e,f,g,h)
	movq $1, %rdi		# a = 1
	movq $2, %rsi		# b = 2
	movq $3, %rdx		# c = 3
	movq $4, %rcx		# d = 4
	movq $5, %r8		# e = 5 
	movq $6, %r9		# f = 6
	# Push last arguments on to the stack in reverse order
	pushq $8		# h = 8
	pushq $7		# g = 7
	call add8		# result = add8(a,b,c,d,e,f,g,h)
	popq %rdi		# Clean up the Stack
	popq %rdi		# Clean up the Stack
	ret			# Return what is in RAX

add8:	# add8(a,b,c,d,e,f,g,h)
	leaq (%rdi, %rsi), %rax	# RAX = a + b
	leaq (%rdx, %rcx), %rdi	# RDI = c + d
	leaq (%r8, %r9), %rsi	# RSI = e + f
	addq 8(%rsp), %rax	# RAX = (a + b) + g
	addq 16(%rsp), %rax	# RAX = (a + b + g) + h
	addq %rdi, %rax		# RAX = (a + b + g + h) + (c + d)
	addq %rsi, %rax		# RAX = (a + b + c + d + g + h) + (e + f)
	ret			# RAX = (a + b + c + d + e + f + g + h)	
