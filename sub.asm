segment .data

segment .text 
    global  asm_sub

asm_sub: 
    enter   0,0
    mov     eax, [ebp + 8]
    sub     eax, [ebp + 12]
    leave
    ret
