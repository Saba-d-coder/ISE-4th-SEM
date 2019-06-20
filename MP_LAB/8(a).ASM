assume cs:code

code segment
    start: mov ah,2ch      ; getting the system time ( it returns ch=hours and cl= minutes)
           int 21h

           mov al,ch       ; copying hour value in al
           aam
           mov bx,ax       ; moving into bx,ax
           call disp       ; calling display 

           mov dl,':'      ; to print ':' in between hours and minutes storing it in dl
           mov ah,2        ; printing character ':'
           int 21h

           mov al,cl       ; copying minutes into al
           aam
           mov bx,ax
           call disp

           mov ah,4ch
           int 21h

     disp proc
        mov dl,bh          ; moving bh into dl
        add dl,30h         ; converting to ascii
        mov ah,2           ; displaying value
        int 21h

        mov dl,bl
        add dl,30h
        mov ah,2
        int 21h

        ret
    disp endp

code ends
end start
