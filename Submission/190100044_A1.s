# Length of longest zigzag subsequence
# Complexity: O(n)
# Space constraints: O(1)

.data

size_string:
    .asciiz "Enter the size of the array\n"

elements_string:
    .asciiz "Enter the elements of the array\n"

end_string:
    .asciiz "\n"

.text

# $s1 -> N
# $s2 -> i
# $s3 -> prev
# $s4 -> curr
# $s5 -> prev_sign
# $s6 -> curr_sign
# $s7 -> length

main:
    jal init
    jal start
    jal first
    jal cond
    jal end

init:
    li $s1 0
    li $s2 1
    li $s3 0
    li $s4 0
    li $s5 0
    li $s6 0
    li $s7 1
    jr $ra

start:
    # printf("Enter the size of the array\n");
    li $v0, 4
    la $a0, size_string
    syscall

    # scanf("%i", &N);
    li $v0 5
    syscall
    move $s1 $v0
    jr $ra

first:
    # printf("Enter the elements of the array\n");
    li $v0, 4
    la $a0, elements_string
    syscall

    # scanf("%i", &prev);
    li $v0 5
    syscall
    move $s3 $v0
    jr $ra

cond:
    # if (i < N) goto loop;
    slt $t0 $s2 $s1 # t0 is 1 if i < N
    bnez $t0 loop # goto loop if t0 is 1
    jr $ra

loop:
    # scanf("%i", &curr);
    li $v0 5
    syscall
    move $s4 $v0

    # prev == curr (peqc)
    beq $s3 $s4 peqc

    slt $t0 $s3 $s4 # t0 is 1 if prev < curr
    # prev < curr (plc)
    bnez $t0 plc # plc if t0 is 1
    # prev > curr (pgc)
    beqz $t0 pgc # pgc if t0 is 0

peqc:
    # curr_sign = 0;
    li $s6 0
    j next

plc:
    # curr_sign = 1;
    li $s6 1
    # if (curr_sign != prev_sign) goto incrlen;
    bne $s5 $s6 incrlen
    j next

pgc:
    # curr_sign = -1;
    li $s6 -1
    # if (curr_sign != prev_sign) goto incrlen;
    bne $s5 $s6 incrlen
    j next

incrlen:
    # prev_sign = curr_sign;
    move $s5 $s6
    # ++length;
    addiu $s7 $s7 1
    j next

next:
    # prev = curr;
    move $s3 $s4
    # ++i;
    addiu $s2 $s2 1
    j cond

end:
    # printf("%i\n", length);
    li $v0 1
    move $a0 $s7
    syscall

    li $v0, 4
    la $a0, end_string
    syscall

    # return 0;
    li $v0 10
    syscall
