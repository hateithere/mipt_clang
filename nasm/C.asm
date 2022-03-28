extern printf
extern scanf
global main

section .text
main:	
	push y
	push x
	push nya1
	call scanf
	add esp, 12
	
	mov eax, dword [x]
	sub eax, dword [y]

	push eax
	push nya
	call printf
	add esp, 8
	xor eax, eax
	ret

section .data
nya db "%d", 10, 0
nya1 db "%d %d", 0

section .bss
x resd 1
y resd 1
