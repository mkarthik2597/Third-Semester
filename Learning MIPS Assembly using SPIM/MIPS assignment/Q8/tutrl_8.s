#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 

  .data
mat1: .word 1, 2, 3, 1, 2, 3, 1, 2, 3     #Initialise matrix1
mat2: .word 1, 0, 1, 0, 1, 0, 1, 0, 1     #Initialise matrix2
new: .asciiz "\n"
tab: .asciiz "\t"
 .align 2 
mat3: .space 36                           #allocate space for product matrix with the first byte aligned on a word boundary
 
 
 # for(row=0;row<3;row++)
 # for(col=0;col<3;col++)
 # {
 #  mat3[row][col]=0; 
 #  for(inx=0;inx<3;inx++)
 #  mat3[row][col]+=mat1[row][inx]*mat2[inx][col];
 # }
 
 .text
main:
 li $s0,0                               #s0-row
 li $s1,0                               #s1-col 
 li $t0,3                                
 la $a1,mat1
 la $a2,mat2
 la $a3,mat3
 
loop1:
 li $s1,0                               #row=0 

loop2:
 li $t3,0                               #t3=mat[row][col]=0
 li $t4,0                               #t4-inx 

loop3:
 
 lw $t5,($a1)
 lw $t6,($a2)
 multu $t5,$t6
 mflo $t7
 add $t3,$t3,$t7                        #mat3[row][col]+=mat1[row][inx]*mat2[inx][col];
 
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
 li $s0,0
 la $a3,mat3
 li $s1,0
  
loop_1:                                 # Code to print out product matrix                                                     
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
 