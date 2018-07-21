#------------------------------------------------------------------------
#	Name     : Sagar Bharadwaj K S
#	Roll No. : 15CO141
#
#	Description of Program : 
#	To calculate Factorial of number (in $t0) using loop 
#
#	Date of writing the program : 12/08/16
#------------------------------------------------------------------------

.data
factprompt:	.asciiz	"Factorial = "

.text
main:
	li $t0,5			#Number 5 is loaded into $t0
	move $a0,$t0
	jal fact			#function 'fact' is called
	move $t2,$v0

	li $v0,4
	la $a0,factprompt
	syscall

	li $v0,1			#Prints factorial of $t0
	move $a0,$t2
	syscall

	li $v0,10
	syscall
fact:
	li $s0,1
	li $s1,1
	addi $a0,$a0,1
	
	loop:				#Loop to calculate factorial
		beq $s0,$a0,endloop
		mul $s1,$s1,$s0
		addi $s0,$s0,1
	j loop
	endloop:

	move $v0,$s1			#Return value is stored in $v0
	jr $ra