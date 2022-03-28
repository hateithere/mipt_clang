extern scanf
extern printf

global main

section .text
main:
	push y
	push x
	push nya
	call scanf
	add esp, 12

	mov eax, [x]
	cmp eax, [y]
	jle end
	mov eax, [y]

end:
	push eax
	push nya1
	call printf
	add esp, 8

	xor eax, eax
	ret

section .data
nya db "%d %d", 0
nya1 db "%d", 10, 0

section .bss
x resd 1
y resd 1
