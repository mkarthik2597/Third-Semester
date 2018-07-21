#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 
 
 .data
arr: .word 10, 20, 30 ,40, 50
avg: .asciiz "Average:"
 .text
main:

la $a0,arr               #a0 contains base address of arr 
li $a1,5                 #a1 stores the number of elements in arr
jal sum

li $t0,5 
div $v0,$t0              #Divide the sum by 5 to calculate average

mflo $a0                 #mflo moves the quotient from LO to a0 
li $v0,1
syscall

li $v0,10
syscall

sum:
 li $v0,0
 li $t2,0
loop:                   #Loop to calculate sum of all elements in the array
 beq $t2,$a1,return
 lw $t3,($a0)
 add $v0,$v0,$t3
 addi $t2,$t2,1 
 addi $a0,$a0,4 
 j loop
 
return:
jr $ra
 