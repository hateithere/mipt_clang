extern printf
;default rel
global main

section .text
main:
	;int 3
	;db 0xcc
	;lea eax, [hello]
	push hello
	call printf
	add esp, 4
	xor eax, eax
	ret

section .data
hello db "Liberté, égalité, fraternité!", 10, 0
