# Length of longest zigzag subsequence
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
