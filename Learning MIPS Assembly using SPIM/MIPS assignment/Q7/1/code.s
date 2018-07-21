#------------------------------------------------------------------------
#	Name     : Sagar Bharadwaj K S
#	Roll No. : 15CO141
#
#	Description of Program : 
#	To add two numbers(in $t0 and $t1) and display the result
#
#	Date of writing the program : 10/08/16
#------------------------------------------------------------------------

.data
a:	.word	15
c:	.word	16
sumtext:	.asciiz	"Sum = "

.text
main:
	lw $t0,a	
	lw $t1,c
	add $t2,$t0,$t1		#$t2=$t1+$t0

	li $v0,4
	la $a0,sumtext
	syscall
	
	li $v0,1		#Print contents of $t2
	move $a0,$t2
	syscall
	
	li $v0,10
	syscall