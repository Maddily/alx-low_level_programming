BITS 64
CPU X64

section .data
hello: db "Hello, Holberton",0x0A,0
fmt: db "%s",0

section .text
global main
extern printf

main:
	push rbp
	mov rbp, rsp
	mov rdi, fmt
	mov rsi, hello
	mov rax, 0
	call printf

	mov rsp, rbp
	pop rbp

	mov eax, 0
	ret
