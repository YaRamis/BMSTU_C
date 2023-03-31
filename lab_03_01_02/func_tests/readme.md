# Тесты lab_03_01_02

## Входные данные
Количество строк матрицы 0 < r < 11
Количество столбцов матрицы 0 < c < 11
Целые числа (элементы матрицы a[i][j])

## Выходные данные
одномерный массив целых чисел b

## Позитивные тесты:
- 01 - все элементы положительные;
- 02 - все элементы отрицательные;
- 03 - отрицательные и положительные смешаны, но нет чередований в столбцах;
- 04 - есть чередование в некоторых столбцах;
- 05 - в чередовании вместо положительного числа ставится ноль;
- 06 - чередование во всех столбцах.

## Негативные тесты:
- 01 - вводится буква вместо кол-ва строк матрицы;
- 02 - вводится буква вместо кол-ва столбцов матрицы;
- 03 - отрицательное значение кол-ва строк;
- 04 - отрицательное значение кол-ва столбцов;
- 05 - кол-во строк матрицы равно нулю;
- 06 - кол-во столбцов матрицы равно нулю;
- 07 - ввод буквы в качетсве элемента матрицы.