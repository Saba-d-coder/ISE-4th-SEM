assume cs:code,ds:data

data segment
    file db "test.txt"   ; file name test.txt which is to be opened, read , printing it's content and closed
    buff db 100 dup(0)   ; where read data in stored
    err db 0ah,0dh," file not found $"
    close db 0ah,0dh," file closed successfully$"
data ends

code segment
    start:
          mov ax,data
          mov ds,ax

          mov ah,3dh   ; to open the file
          lea dx,file  ; loading file to be opened

          mov al,0

          int 21h      ; if it's successfully opened, CF is cleared and ax is set to file handle
          jnc next     ; jump to next if CF is cleared

          lea dx,err   ; else print error msg
          mov ah,9
          int 21h

          jmp finish


         next:
              mov bx,ax    ; to set bx as file handle
              mov ah,3fh   ; to read the file               

              lea dx,buff   
              int 21h

              mov cx,100d  ; no. of characres to be read

              lea si,buff

        repeat:
                mov dl,[si]

                mov ah,2
                int 21h

                inc si
                loop repeat


                mov ah,3eh   ; to close the file
                int 21h

                lea dx,close
                mov ah,9
                int 21h

         finish: mov ah,4ch
                 int 21h

 code ends
 end start
