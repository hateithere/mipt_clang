# zero

```
xor %eax, %eax
```

# one
```
xor %eax, %eax
inc %eax
```

# next
```
inc %ax
```

# prev
```
dec %ax
```

# sum
```
mov %ax, %dx
add %bx, %dx
```

# sub
```
mov %rax, %rdx
sub %rbx, %rdx
```

# imul
```
imul %bl
mov %ax, %dx
```

# idiv
```
cwd
idiv %bx
mov %ax, %dx 
```

# lea
```
lea (%rax, %rbx, 8), %rdx
```

# lea1
```
lea (%rax, %rax, 4), %rdx
```

# lea32
```
lea (%eax, %ebx, 8), %edx
```

# egalite
```
cmp %ax, %bx
jne nya
mov $1, %dx
jmp nya_
nya:
mov $0, %dx
nya_:
```

# factorial
```
xor %edx, %edx
inc %edx
cmp $0, %al
je end
mov %al, %cl
mov %ecx, %eax
loop:
mov %eax, %edx
cmp $1, %ecx
jle end
dec %ecx
mul %ecx
jmp loop
end:
```

# factorial64
```
xor %rdx, %rdx
inc %rdx
cmp $0, %al
je end
mov %al, %cl
mov %rcx, %rax
loop:
mov %rax, %rdx
cmp $1, %rcx
jle end
dec %rcx
mul %rcx
jmp loop
end:
```
# antifa
```
xor %ecx, %ecx
inc %ecx
loop:
cmp $1, %eax
je end
inc %ecx
cdq
div %ecx
jmp loop
end:
mov %ecx, %ebx
```

# antifa64
```
xor %rcx, %rcx
inc %rcx
loop:
cmp $1, %rax
je end
inc %rcx
cqo
div %rcx
jmp loop
end:
mov %rcx, %rbx
```

# vector
```
xor %rbx, %rbx
cmp $0, %rcx
je end
dec %rcx
loop:
lea (%rax, %rcx, 8), %rdx
add (%rdx), %rbx
dec %rcx
cmp $-1, %rcx
je end
jmp loop
end:
```
