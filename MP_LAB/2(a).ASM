assume cs:code,ds:data
data segment
    a db 95h,76h,2h,1h,67h
    n db n-a
data ends

code segment
    start:mov ax,data
          mov ds,ax

          mov cl,n
          dec cl

    first: lea si,a
           mov dl,cl

   second: mov al,[si]
           cmp al,[si+1]

           jbe do_nothing

           xchg al,[si+1]
           mov [si],al

   do_nothing: inc si
              dec dl
              jnz second
              loop first

              mov ah,4ch
              int 21h


code ends
end start













