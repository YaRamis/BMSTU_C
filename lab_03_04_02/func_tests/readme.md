# Тесты lab_03_04_02

## Входные данные
Количество строк матрицы 0 < r < 11
Количество столбцов матрицы 0 < c < 11
r == c
Целые числа (элементы матрицы a[i][j])

## Выходные данные
Целое число

## Позитивные тесты:
- 01 - в матрице только одно положительное число заканчивающеся на 5 под побочной диоганалью;
- 02 - в матрице только одно отрицательное число заканчивающеся на 5 под побочной диоганалью;
- 03 - на побочной диагонали нужное число большее чем под ней;
- 04 - нужное число присутствует над побочной диагональю и под;
- 05 - под побочной диагональю несколько таких чисел.

## Негативные тесты:
- 01 - вводится буква вместо кол-ва строк матрицы;
- 02 - вводится буква вместо кол-ва столбцов матрицы;
- 03 - отрицательное значение кол-ва строк;
- 04 - отрицательное значение кол-ва столбцов;
- 05 - кол-во строк матрицы равно нулю;
- 06 - кол-во столбцов матрицы равно нулю;
- 07 - ввод буквы в качетсве элемента матрицы;
- 08 - кол-во строк не равно кол-ву столбцов;
- 09 - в матрице нету чисел заканчивающихся на 5.