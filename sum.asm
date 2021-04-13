;segmenet data
segment .data

segment .text 
    global  asm_sum

asm_sum: 
    enter   0,0
    mov     eax, [ebp + 8]
    add     eax, [ebp + 12]
    leave
    ret

    