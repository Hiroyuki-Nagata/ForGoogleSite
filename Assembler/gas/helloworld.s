.file   "helloworld.s"
.data
msg:    .ascii  "hello world\n"
msgend: .equ    len, msgend - msg

.global main
main:
        movl $4,        %eax    # write system call(sys_write)
        movl $1,        %ebx    # stdout
        movl $msg,      %ecx
        movl $len,      %edx
        int  $0x80
        ret