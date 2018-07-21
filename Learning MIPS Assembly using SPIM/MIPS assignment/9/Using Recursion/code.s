#------------------------------------------------------------------------
#	Name     : Sagar Bharadwaj K S
#	Roll No. : 15CO141
#
#	Description of Program : 
#	To calculate Factorial of number (in $t0) using recursion
#
#	Date of writing the program : 12/08/16
#------------------------------------------------------------------------

.data
factprompt:	.asciiz	"Factorial = "

.text
main:
	li $t0,6			#Number 6 loaded into $t0
	move $a0,$t0
	jal fact			#Function 'fact' is called
	move $t2,$v0

	li $v0,4
	la $a0,factprompt
	syscall

	li $v0,1			#Prints Factorial of 6
	move $a0,$t2
	syscall

	li $v0,10
	syscall
fact:
	addi $sp,$sp,-8			#To save value of $s0,$ra in stack memory
	sw $ra,($sp)
	sw $s0,4($sp)

	li $v0,1
	beq $a0,0,factDone

	move $s0,$a0
	addi $a0,$a0,-1
	jal fact			#Calls fact($a0-1)
	
	mul $v0,$s0,$v0			#Uses recursion formula Fact(n)=n*Fact(n-1)
	
	factDone:
		lw $ra,($sp)		#Restores the stack memory to previous condition
		lw $s0,4($sp)
		addi $sp,$sp,8
		jr $ra