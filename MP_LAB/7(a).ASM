assume cs:code,ds:data
data segment
    fib db 10 dup(?)       ; to store fibonacci series from 0 to 10
    n db 0ah
data ends

code segment
    start: mov ax,data
           mov ds,ax

           lea si,fib      ; loading address of fib in si
           mov al,0h       ; moving 0 into al
           mov [si],al     ; moving al into the location pointed by si
           inc si          ; incrementing si

           mov bl,01h      ; moving 1 into bl
           mov [si],bl     ; moving bl into location pointed by si
           inc si          ; incrementing si

           mov cl,n        ; moving n into cl
           sub cl,2        ; subtracting 2 because first two terms of fibonacci is already calculated

     fibo: add al,bl       ; adding al and bl
           mov [si],al     ; moving the sum into location pointed by si
           inc si          ; moving to next location in sequence
           xchg al,bl      ; exchanging al and bl values
           loop fibo       ; looping fibo

           mov ah,4ch      ; exiting program
           int 21h
 code ends
 end start
