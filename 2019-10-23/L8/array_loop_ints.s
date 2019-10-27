.text
.globl main

main:	# Let's write an array, then call a function to sum the elements!
	subq $20, %rsp
	movl $1, (%rsp)		# ary[0] = 1
	movl $3, 4(%rsp)	# ary[1] = 3
	movl $5, 8(%rsp)	# ary[2] = 5
	movl $7, 12(%rsp)	# ary[3] = 7
	movl $9, 16(%rsp)	# ary[4] = 9
	# rsp is ary
	movq %rsp, %rdi		# Arg1 = ary
	movl $5, %esi		# Arg2 = 5 (int, num elements)
	call sum		# val = sum(ary, 5);
	addq $20, %rsp
	ret			# return val (int)

sum:	#rdi has ary and esi has number of elements in ary
  movl $0, %eax # int result 
  movl $0, %ecx # int i
  jmp comp
top:
  movslq %ecx, %rcx # Sign extend i to 64-bits for the pointer math
  addl (%rdi, %rcx, 4), %eax
  incl %ecx
comp:
  cmpl %esi, %ecx
  jl top
  ret
