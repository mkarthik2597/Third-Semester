#------------------------------------------------------------------------
#	Name     : Sagar Bharadwaj K S
#	Roll No. : 15CO141
#
#	Description of Program : 
#	To print "Hello World" in the console
#
#	Date of writing the program : 10/08/16
#------------------------------------------------------------------------

.data
str:	.asciiz "Hello World\n"

.text
main:
	la $a0,str	#Prints string stored in 'str'
	li $v0,4
	syscall
	
	li $v0,10
	syscall

