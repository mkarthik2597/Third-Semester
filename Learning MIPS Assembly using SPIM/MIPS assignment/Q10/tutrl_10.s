#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 

 .data

out1: .asciiz "Enter a string of numbers(Not more than 4):"
out2: .asciiz "\nEnter another number:"
string: .space 5

Zero: .asciiz "Zero"            #Labels with strings corresponding to all the decimal digits
One: .asciiz "One"
Two: .asciiz "Two"
Three: .asciiz "Three"
Four: .asciiz "Four"
Five: .asciiz "Five"
Six: .asciiz "Six"
Seven: .asciiz "Seven"
Eight: .asciiz "Eight"
Nine: .asciiz "Nine"


 .text
main:
 la $a0,out1
 li $v0,4
 syscall
 
loop1:
 la $a0,string                
 li $a1,5
 li $v0,8                       #System call code to read a string   
 syscall 
 
 lb $t0,($a0)
 li $t1,'-'                     #Terminate reading of inputs for a negative number 
 li $t7,'\n'                    #Strings are terminated by a new line character and later padded by null characters
 beq $t0,$t1,end
 move $a2,$a0
 
loop2:
 lb $a1,($a2)
 beq $a1,$0,break2              #Loop for printing word equivalent of all digits till new line or null is reached
 beq $a1,$t7,break2
 jal print
 addi $a2,$a2,1
 j loop2
 
break2:                         #Prompt to enter another number 
 la $a0,out2
 li $v0,4
 syscall 
 j loop1

end:
 li $v0,10
 syscall 
 
print:                          #Function to print the digits in words 
 li $t2,'0'
 bne $a1,$t2,one
 la $a0,Zero
 li $v0,4
 syscall
 jr $ra
 
one:
 addi $t2,$t2,1 
 bne $a1,$t2,two
 la $a0,One 
 li $v0,4
 syscall
 jr $ra
 
two:
 addi $t2,$t2,1 
 bne $a1,$t2,three
 la $a0,Two 
 li $v0,4
 syscall
 jr $ra
 
three:
 addi $t2,$t2,1 
 bne $a1,$t2,four
 la $a0,Three
 li $v0,4
 syscall
 jr $ra
 
four:
 addi $t2,$t2,1 
 bne $a1,$t2,five
 la $a0,Four 
 li $v0,4
 syscall
 jr $ra
 
five:
 addi $t2,$t2,1 
 bne $a1,$t2,six
 la $a0,Five 
 li $v0,4
 syscall
 jr $ra
 
six:
 addi $t2,$t2,1 
 bne $a1,$t2,seven
 la $a0,Six 
 li $v0,4
 syscall
 jr $ra
 
seven:
 addi $t2,$t2,1 
 bne $a1,$t2,eight
 la $a0,Seven 
 li $v0,4
 syscall
 jr $ra
 
eight:
 addi $t2,$t2,1 
 bne $a1,$t2,nine
 la $a0,Eight 
 li $v0,4
 syscall
 jr $ra
 
nine:
 addi $t2,$t2,1 
 la $a0,Nine 
 li $v0,4
 syscall
 jr $ra
 
 
 