#------------------------------------------------------------------------
#	Name     : Sagar Bharadwaj K S
#	Roll No. : 15CO141
#
#	Description of Program : 
#	To print 1st 100 prime numbers using subroutines:
#		1. test_prime(n)
#		2. main
#
#	Date of writing the program : 11/08/16
#------------------------------------------------------------------------

.data
nl:	.ascii	"\n"

.text
main:
	li $v0,1		#Prints the first prime number, 2
	li $a0,2
	syscall

	li $v0,4
	la $a0,nl
	syscall

	addi $t0,$0,1		#$t0 keeps track of number of prime numbers printed
	addi $t1,$0,3
	
	loop:			#loop that executes until the remaining 99 prime numbers are printed
	beq $t0,100,end
	add $a0,$0,$t1
	jal test_prime
	beq $v0,0,skip		#If $t1 is not prime, then the printing part of the code is skipped
	
	addi $t0,$t0,1		#prints prime number
	li $v0,1
	add $a0,$t1,$0
	syscall

	li $v0,4		#prints new line
	la $a0,nl
	syscall
	
	skip:
	addi $t1,$t1,1
	j loop

	end:
	li $v0,10
	syscall
	
	
test_prime:
	add $s0,$a0,$0
	addi $s1,$0,2
	
	loopi:			#Loop that runs from 1 to n-1 to check if n is prime
	beq $s1,$s0,prime
	div $s0,$s1
	mfhi $s3
	beq $s3,$0,notPrime
	addi $s1,$s1,1
	j loopi
	
	prime:			#If number is prime 1 is returned
	li $v0,1
	jr $ra

	notPrime:		#If number is not prime 0 is returned
	li $v0,0
	jr $ra
	