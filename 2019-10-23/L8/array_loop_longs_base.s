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
	movq $5, %rsi		# Arg2 = 5 (num elements)
	call sum		# val = sum(ary, 5);
	addq $20, %rsp
	ret			# return val

sum:	#rdi has ary and rsi has number of elements in ary
  







