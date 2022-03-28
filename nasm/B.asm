extern printf
extern scanf
global main

section .text
main:	
	push x
	push nya1
	call scanf
	add esp, 8
	
	mov eax, [x]
	and eax, 0xFFFF 

	push eax
	push nya
	call printf
	add esp, 8

	xor eax, eax
	ret

section .data
nya db "%u", 10, 0
nya1 db "%u", 0

section .bss
x resd 1
