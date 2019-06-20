assume cs:code,ds:data

data segment
    a db 2h,4h,56h,67h,90h    ; initialising array
    n db n-a                  
    key db 90h                ; key value is 90h
    msg1 db "not found $"
    msg2 db "found at"
    pos db ?,"$"              
data ends

code segment
    start: mov ax,data
           mov ds,ax

           mov al,0        ; low =0
           mov dl,n        ; high =n
           dec dl          ; high =n-1

    comp: cmp al,dl        ; comparing low and high
          ja fail          ; jump to fail if low is greater than high

          mov cl,al        ; keeping a copy of low value in cl
          add al,dl        ; adding low and high,the sum will be stored in al
          shr al,1         ; finding mid value by dividing al by 2

          mov ah,0         ; clearing any grabage value in ah
          mov si,ax        ; moving mid value to si
          mov bl,[si]      ; moving si value to bl
          cmp bl,key       ; comparing mid value and the key
          jae loc1         ; jump to loc1 if mid value is greater thanor equal to key

          inc al           ; else increment al
          jmp comp         ; jump to comp

   loc1: je success        ; jump to success if mid and key values are equal
         dec al            ; else decrement al

         mov dl,al         ; mov al value to high(dl)
         mov al,cl         ; retrieve the low value copied in cl
         jmp comp          ; jump to comp

    fail: lea dx,msg1      ; loading msg1 in dx
          jmp disp         ; jump to display

    success: inc al        ; incrementing al
             add al,30h    ; converting to ascii value by adding 30
             mov pos,al    ; moving al value in pos
             lea dx,msg2   ; loading msg2 in dx

    disp:mov ah,9          ; interrupt to display the string or msg strored in dx
         int 21h
         mov ah,4ch        ; interrupt for exiting and returning control back to dos
         int 21h

code ends                  ; end of the code
end start

