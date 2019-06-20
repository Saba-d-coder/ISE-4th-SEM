assume cs:code,ds:data
data segment
    n db 5       ; to find factorial of 5
    res db ?
data ends

code segment
    start: mov ax,data
           mov ds,ax

           mov al,n          ; moving 5 into al
           call fact         ; calling fact procedure

           mov ah,4ch        ; exiting program 
           int 21h

       fact proc             ; start of fact procedure
            cmp al,00        ; comparing if al is equal to 0
            je calc          ; if yes then jump to calc 

            mov ah,0         ; else moving 0 into ah
            push ax          ; pushing value of ax onto the stack
            dec al           ; decrementing al
            call fact        ; calling fact procedure again  to push all values of ax onto stack till ax becomes 0

            pop ax           ; popping ax value one by one
            mul res          ; multiplying ax with res
            mov res,al       ; storing multiplied result into res 
            ret              ; returning to where fact procedure was called
         calc : mov res,01   ; moving into res 1
                 ret         ; returning to where fact procedure is called
       fact endp             ; end of fact procedure
code ends
end start
