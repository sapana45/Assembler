section .data
	a dd 10
        c db 30
        d db 40
section .bss
        res resd 1
        b resd 5
section .txt
       global main
main:
        movr eax,a
        movr ebx,b1
        add eax,ebx
        jmp lab
 lab: print eax
        ret
