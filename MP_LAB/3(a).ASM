assume cs:code,ds:data

disp macro msg            ; macro for displaying the msg
    lea dx,msg
    mov ah,9
    int 21h
endm

data segment
    pwd1 db "hello"
    n1 db n1-pwd1
    pwd2 db 10 dup(?)         
    n2 db n2-pwd2

    msg1 db 0ah,0dh,"password matched$"
    msg2 db 0ah,0dh, "password did not matched $"
    msg3 db 0ah,0dh,"enter password: $"
    msg4 db 0ah,0dh,"limit reached,exiting the program $"
data ends

code segment
    start:mov ax,data
          mov ds,ax
          mov es,ax

          mov bl,0             ; bl is used to check whether the limit of entering password has reached or not. Initially made 0

     rpt: call read            ; calling read procedure
          call match           ; calling match procedure

          inc bl               ; incrementing bl
          cmp bl,3             ; comparing if bl=3 which is max limit
          jb rpt               ; jump to rpt if bl is lesser than 3
          disp msg4            ; else displaying msg4
          mov ah,4ch           ; exiting the program
          int 21h


         read proc             ; start of read proc
            disp msg3          ; displaying msg3
            mov bh,0           ; making bh 0
            lea si,pwd2        ; loading the address of pwd2 into si


            next: mov ah,8     ; taking input from user without echoing
                  int 21h

                  cmp al,0dh   ; comparing input with carriage return or end of input by user
                  je done      ; if equal then jump to done

                  mov [si],al  ; moving al into si ie, into pwd2 
                  inc si       ; inc si
                  inc bh       ; inc bh

                  mov dl,"*"   ; moving * in dl
                  mov ah,2     ; interrupt to print the character stored in dl
                  int 21h

                  jmp next     ; jump to next to take another character from user

            done: mov n2,bh    ; moving the bh value into n ie, length of pwd2
                   ret         ; returning back to where read procedure was called

       read endp               ; end of read procedure


       match proc              ; start of match procedure
            mov cl,n1          ; move n1 (length of pwd1) into cl
            cmp cl,n2          ; comparing lengths of pwd1 and pwd2
            je matching        ; if equal jump to matching label
            jmp miss           ; else jump to miss label

            matching: lea si,pwd1                 ; loading into si address of pwd1
                   lea di,pwd2                    ; loading into di address of pwd2

                   cld                            ; clearing the direction flag so that si and di can increment automatically
                   rep cmpsb                      ; comparingpwd1 and pwd2 string byte by byte
                   jnz miss                       ; jump to miss if it's not equal (zero flag is not set ie.,0)
                   disp msg1                      ; else display msg1 ie, equal

                   mov ah,4ch                     ; exiting program
                   int 21h

             miss: disp msg2
                   ret

      match endp
code ends
end start

