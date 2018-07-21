#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 

.data
out1: .asciiz "Enter no. of disks:"
out2: .asciiz "Move disk "
out3: .asciiz " from peg "
out4: .asciiz " to peg "
out5: .asciiz ".\n"
 .text
main:
 la $a0,out1
 li $v0,4
 syscall
 li $v0,5
 syscall
 
 move $a0,$v0             #a0-no. of disks, n 
 li $a1,1                 #a1-start
 li $a2,2                 #a2-finish
 li $a3,3                 #a3-extra
 jal hanoi                #hanoi(n,start,finish,extra);

 li $v0,10
 syscall
 
hanoi:
 beq $a0,$0,return        # if(n>0)
 addi $sp,$sp,-20         #push arguments to stack
 sw $a1,($sp)
 sw $a2,4($sp)
 sw $a3,8($sp)
 sw $a0,12($sp)
 sw $ra,16($sp)
 
 move $t2,$a3             #swap finish and extra 
 move $a3,$a2
 move $a2,$t2
 
 addi $a0,$a0,-1          #hanoi(n-1,start,extra,finish)
 jal hanoi 
 
 la $a0,out2              #code fragment for printing output on the screen
 li $v0,4
 syscall
 
 lw $a0,12($sp)
 li $v0,1 
 syscall
 
 la $a0,out3
 li $v0,4 
 syscall
 
 lw $a0,($sp)
 li $v0,1 
 syscall
 
 la $a0,out4
 li $v0,4
 syscall 
 
 lw $a0,4($sp)
 li $v0,1 
 syscall
 
 la $a0,out5
 li $v0,4 
 syscall
 
 lw $a0,12($sp)
 addi $a0,$a0,-1 
 
 lw $t0,8($sp)
 move $a1,$t0
 
 lw $t0,4($sp)
 move $a2,$t0
 
 lw $t0,($sp)
 move $a3,$t0

 jal hanoi                #hanoi(n-1, extra, finish, start);  
 lw $ra,16($sp)           
 addi $sp,$sp,20          #reset stack pointer to previous call
 jr $ra
 
 
return:
 jr $ra
 
 
 