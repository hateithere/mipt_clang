# Notices

## X86

* cmovXX (перемещение с условием)
* setXX (установка бита с условием)
* аргументы через стек в обратном порядке
* удаление из стека лежит на вызывающем
* результат работы - в al, ax, eax (стандартные типы)
* дробные - в регистрах сопроцессора
* cdecl (декларация языка Си)  
* push/pop - стек
* base pointer - для доступа к локальным переменным

```
printf(str, x, y)
---
push L1
push dword [y]
push dword [x]
push str
call printf
---
after call:
L1: add esp, 12 ; 3 * 4 
---
result in eax register (number of printed arguments)
```
* в стек помещается сначала адрес возврата (адрес, откуда вызвали, плюс длина данной инструкции)   
