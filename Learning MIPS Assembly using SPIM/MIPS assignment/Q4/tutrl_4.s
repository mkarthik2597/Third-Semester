#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 
 
 .data
arr: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 99
 .text
main:
  la $s0,arr                    #s0 contains base address of arr
  li $s1,0                      #s1 is the sum, initialised to 0 
  li $t1,0                      #t1 is the counter initialised to 0 
  li $t2,10                     #t2 represents no of elements in the list
  
loop: beq $t1,$t2,print
      lw $t0,($s0)              
	  add $s1,$s1,$t0           #Load a word at s0, add it to s1 and store the sum in s1
	  addi $s0,$s0,4
	  addi $t1,$t1,1
	  j loop
	  
print: move $a0, $s1
       li $v0,1
	   syscall
	   
	   li $v0,10
	   syscall
	   