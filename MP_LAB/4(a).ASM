assume cs:code,ds:data
data segment
    str1 db "mddam"
    n dw n-str1
    str2 db 5 dup(?)
    msg1 db "did not match$"
    msg2 db "match $"
data ends

code segment
    start: mov ax,data
           mov ds,ax

           
           mov cx,n           ;  moving into cx length of str1
          ; dec cl
           lea si,n           ; si points to last character of string
           dec si
           lea di,str2        ; loading into di str2

     char: mov al,[si]        ; moving into al value pointed by si
           mov [di],al        ; moving al value into location pointed by di

           inc di             ; moving to next location
           dec si             ; decremented si

           loop char          ; looping char till cx = 0

           lea di,str1        ; loading in di address of str2
           lea si,str2        ; loading in si address of str1

           mov cx,n           ; moving into cx n value for loop

     next: mov al,[si]        ; moving into al the value pointed by si
           cmp al,[di]        ; comparing al with value pointed by di

           jnz fail           ; jump to fail if not equal
           inc di             ; move to next location in sequence
           inc si             ; move to next location in sequence
           loop next          ; loop till cx =0 

           lea dx,msg2        ; load into dx msg2
           jmp disp           ; jump to display

      fail:lea dx,msg1        ; load into dx msg1
      disp: mov ah,9          ; printing msg
            int 21h

            mov ah,4ch         ; exiting the programf
            int 21h

 code ends
 end start


