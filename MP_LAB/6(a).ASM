assume cs:code

code segment
    start: mov ah,00h         ; setting the video mode
           mov al,02h         ; setting screen's boundary
           int 10h            ; BIOS interrupt

           mov ah,02h         ; setting the cursor's positions
           mov dh,12d         ; setting row position into dh
           mov dl,40d         ; setting column position into dl
           int 10h
                              
           mov al,'X'         ; storing the character to be displayed on screen in al
           mov bl,8ch         ; setting attribute value i.e, red colour font with black background
           mov cl,1           ; how many times to display the character
           mov ah,09          ; to display the character with it's attributes
           int 10h

           mov ah,07          ; waits for character for the user to enter from stdin to stop the blinking process
           int 21h

           mov ah,4ch         ; exiting the program
           int 21h
 code ends
 end start
