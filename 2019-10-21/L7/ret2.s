.text 			# Code Section
.globl main		# main needs to be global

main:			# Label for main
	call ret2	# Call ret2() - Returns a value in RAX
	ret		# Return what is in RAX

ret2:			# Label for ret2
	movq $2, %rax	# result = 2
	ret		# Return result (via RAX)
