#Name:Karthik.M
#Roll:15co221
#Date:9.08.2016 
  
  .data
 var1: .word 10
 var2: .word 20       #Initilaise two variables to 10 and 20
  .text
main:

lw $t0,var1
sw $t0, ($gp)         #Store var1 at address in gp i.e 0x10008000
lw $t1,var2
sw $t1,-0x8000($gp)   #Store var2 at adress 0x10000000, the beginning of the data segment.
lw $t0, ($gp) 
lw $t1, -0x8000($gp)
add $t2,$t0,$t1
sw $t2, -0x7E70($gp)  #Store the sum at 4*100=0x190. Address on data segment=0x10000190 = 0x10008000-0x7E70

lw $a0, -0x7E70($gp)
li $v0,1
syscall

li $v0,10
syscall 
