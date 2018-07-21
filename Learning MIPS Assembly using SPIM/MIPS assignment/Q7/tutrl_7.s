#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 

#This program takes in elemnts of two 3X3 matrices from the user and displays their product matrix 

.data
.align 2                          #.align directive sets the bytes word aligned   
mat1: .space 36
.align 2
mat2: .space 36
.align 2
mat3: .space 36
out1: .asciiz "Enter elements of the first 3X3 matrix:"
out2: .asciiz "Enter elements of the second 3X3 matrix:"
new: .asciiz "\n"
tab: .asciiz "\t"
 
 # for(row=0;row<3;row++)
 # for(col=0;col<3;col++)
 # {
 #  mat3[row][col]=0; 
 #  for(inx=0;inx<3;inx++)
 #  mat3[row][col]+=mat1[row][inx]*mat2[inx][col];
 # }

 .text
main:
 la $a0,out1
 li $v0,4
 syscall
 li $t0,0                          #t0 is a counter
 li $t1,9                          #t1 stores the maximum no. of elements(9 here)
 li $t6,1
 la $a1,mat1
loop:                              #loop to read elements for both the 3X3 matrices
 beq $t0,$t1,break_ 
 li $v0,5
 syscall
 sw $v0,($a1)
 addi $a1,$a1,4
 addi $t0,$t0,1
 j loop 
 
break_:
 beq $t6,$0,start
 la $a0,out2
 li $v0,4
 syscall
 
 li $t0,0
 li $t6,0
 la $a1,mat2
 j loop
 
start:
 la $a1,mat1
 la $a2,mat2
 la $a3,mat3
 jal matmul                       #matmul is a function that calculates the product matrix elements and stores them in mat3
 
 li $s0,0
 la $a3,mat3
 li $s1,0

loop_1:                           #code fragment to print out the matrix elements                  
 beq $s0,$t0,break_1 
 li $s1,0

loop_2:
 lw $a0,($a3)
 li $v0,1
 syscall
 
 la $a0, tab 
 li $v0,4
 syscall 
 
 addi $s1,$s1,1
 beq $s1,$t0,break_2
 
 addi $a3,$a3,4
 j loop_2
 
break_2:
 la $a0,new
 li $v0,4
 syscall
 
 addi $s0,$s0,1
 addi $a3,$a3,4
 j loop_1
 
break_1:
 li $v0,10
 syscall
 
 
matmul:                           #matmul function to multiply the matrices 
 li $s0,0
 li $s1,0
 li $t0,3

loop1:
 li $s1,0

loop2:
 li $t3,0 
 li $t4,0

loop3:
 
 lw $t5,($a1)
 lw $t6,($a2)
 multu $t5,$t6
 mflo $t7
 add $t3,$t3,$t7
 
 addi $t4,$t4,1
 beq $t4,$t0,break3
 
 addi $a1,$a1,4
 addi $a2,$a2,12
 
 j loop3
 
break3:
 sw $t3,($a3)
 addi $a3,$a3,4

 addi $s1,$s1,1
 beq $s1,$t0,break2
 
 addi $a1,$a1,-8
 addi $a2,$a2,-20
 j loop2
 
break2:
 
 addi $s0,$s0,1
 beq $s0,$t0,break1
 addi $a1,$a1,4 
 la $a2,mat2 
 j loop1
 
break1:
 jr $ra

  

