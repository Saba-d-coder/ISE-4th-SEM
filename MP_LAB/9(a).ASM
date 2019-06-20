assume cs:code

code segment
    start: mov cx,100d          ; to loop 100 times
           mov bl,0

           next: mov al,bl
                 aam
                 add ax,3030h   ; converting to ascii
                 mov dl,ah
                 mov ah,2       ; printing  msb of 2 digit no.
                 push ax
                 int 21h

                 pop ax
                 mov dl,al
                 mov ah,2       ; printing lsb of 2 digit no.
                 int 21h

                 mov dl,0dh     ; carriage return
                 mov ah,2       ; printing next no. in same position
                 int 21h

                 call delay     ; calling delay procedure
                 inc bl         ; incrementing the binary no.
                 loop next

                 mov ah,4ch
                 int 21h


         delay proc               ; start of procedure
                mov si,00002h
                l1:mov di,0ffffh
                l2: dec di
                    jnz l2
                    dec si
                    jnz l1

                    ret
         delay endp               ; end of procedure


code ends
end start

