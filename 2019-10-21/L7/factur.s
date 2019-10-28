.text 			# Code Section
.globl main		# main needs to be global

# C Code
# int main() {
#   return factur(3);
# }
#
# long factur(long x) {
#   return x * fact(x);
# }
#
# long fact(long n) {
#   if(n == 1) 
#     return 1;
#   return n * fact(n-1);
# }

main:			# Label for main
	movq $3, %rdi	# First argument is a 3
	call factur	# Call factur(3) - Returns a value in RAX
	ret		# Return what is in RAX

factur: # factur(x) = x * x!
	# Uses CALLEE-SAVE REGISTER to preserve x across call
	pushq %rbx        # Backup RBX
	movq %rdi, %rbx   # Backup x
	callq fact        # fact(x) 
	imulq %rbx, %rax  # x * x! in RAX
	popq %rbx         # Restore RBX
	ret               # Return x * x! 
fact: 	# fact(n) = n!
	# Uses STACK to preserve n across call
	cmpq $1, %rdi 
	jle base      # if n<=1, base case
	pushq %rdi    # Backup n on Stack 	
	decq %rdi     # Prep for n-1 call
	callq fact    # fact(n-1)
	popq %rdi     # Get n back
	imulq %rdi, %rax # n * (n-1)!
	jmp end 
base: 	
	movq $1, %rax # return 1
end: 
	ret	

