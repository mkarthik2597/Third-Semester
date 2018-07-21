#------------------------------------------------------------------------
#	Name     : Sagar Bharadwaj K S
#	Roll No. : 15CO141
#
#	Description of Program : 
#	To Reverse a string (String Chosen : "Hello")
#
#	Date of writing the program : 11/08/16
#------------------------------------------------------------------------
.data
str:	.ascii	"Hello"
rev:	.ascii	""

.text
main:
	la $t0,str
	la $t1,rev
	li $t3,5
	addi $t0,$t0,4

	loop:				#loop to reverse a string and store it in 'rev'
		beq $t3,0,end		
		lb $t2,($t0)
		addi $t0,$t0,-1		#Decrements pointer pointing to 'str' 
		addi $t3,$t3,-1
		sb $t2,($t1)
		addi $t1,$t1,1		#Increments pointer pointing to 'rev'
	j loop
	end:
	
	li $v0,4			#Prints the string stored in 'rev'
	la $a0,rev
	syscall
	
	li $v0,10
	syscall	
