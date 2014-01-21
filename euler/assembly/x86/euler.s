# euler.s - x86 version of project euler problems
#
# author: Dan Cashman - dan.a.cashman@gmail.com

        .section .data

        .section .text

        .global _start

        # We are starting with just the test-case version of problem 1, as a first step.
        # We need to break this up into a better structure as in the c dir.
_start:

        #runs problem1_general with limit of 10
problem1:
        push $10
        call problem1_general
        movq %rax, %rbx  #move result into exit code reg
        movq $1, %rax
        int $0x80

problem1_general:
        pushq %rbp           #function prologue
        movq %rsp, %rbp
        movq 16(%rbp), %rbx   #limit in %rbx
        movq $0, %rax        #result in %rax, starts at 0
        movq $0, %rcx        #i value
        movq $3, %rdx        #amount to increase each time through loop
three_loop:
        cmpq %rcx, %rbx      # if i >= limit, exit
        jle three_exit
        addq %rcx, %rax      # sum += i
        addq %rdx, %rcx      # i += 3
        jmp three_loop
three_exit:
        movq $0, %rcx        #i value
        movq $5, %rdx        #amount to increase each time through loop
five_loop:
        cmpq %rcx, %rbx      # if i >= limit, exit
        jle five_exit
        addq %rcx, %rax      # sum += i
        addq %rdx, %rcx      # i += 5
        jmp five_loop
five_exit:
        movq $0, %rcx        #i value
        movq $15, %rdx        #amount to decrease each time through loop
sub_loop:
        cmpq %rcx, %rbx      # if i >= limit, exit
        jle sub_exit
        subq %rcx, %rax      # sum += i
        addq %rdx, %rcx      # i += 15
        jmp sub_loop
sub_exit:
        movq %rbp, %rsp      #function epilogue
        popq %rbp
        ret
