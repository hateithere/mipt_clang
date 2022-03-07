# cpu

* Беззнаковые
* По модулю 256 (8-битность)
* Switch
* Массив регистров
* #ifdef REGISTERS

Используем REGISTERS

# cache

* Первая лекция Северова
* "Размазывает" справа налево
* Обнулять массив через {0}/{}
* Двумерный массив можно инициализировать последовательным списком
* Адрес массива - не lvalue
* Матрицы симметричны относительно диагонали
* У второй матрицы меняем индексы местами

# neo

* number/_of_/anomaly = 6
* Переписать значение в другой части структуры
* Учитывать "дырки" в структуре, тут её нет

# flag

* Анализ операций
* MOV меняет флаг

# cuda

* Прочитать =3

# simple_page

* Можно посчитать размер страницы
* Одноуровневая система адресов (в 32х-битном, на самом деле, двухуровневая)
* Остаток бит - смещение внутри страницы

# pdp_rw

* typedef
* Функции - однострочные 
* char mem[64K]
* typedef short/int/_16t word (+stdint)
* Приводим через указатель к word: *(word *)(mem + i)

# pdp_load

* Текстовый файл (r/rt) 

# Заметки
* (int (*)[10])p - "приведение" к массиву длины 10 
* PAE (трехстраничная память)
* Массив указателей на функции - для будущего эмулятора.