# Тесты lab_10_01_01

# Мое условие
    Даны два файла со списком названий машин и их годами выпуска.
Если первый или второй файл (либо оба) пустой, то выдать ошибку.
Надо удалить самую новую и самую старую машины в каждом списке (путем сортировки списков).
Второй список присвоить первому.
Если оба списка пустые то выдать ошибку (после удаления).
Отсортировать получившийся список и вывести в файл.

Формат данных в файле:
    [марка машины] [год выпуска]
    [марка машины] [год выпуска]
    ...

## Формат ввода аргументов
./app.exe cars_1.txt cars_2.txt all_cars.txt

## Входные данные
аргументы в терминале
данные в файле

## Выходные данные
данные в выхлопном файле

## Позитивные тесты:
- 01 - после удаления второй список оказывается пустой;
- 02 - после удаления первый список оказывается пустой;
- 03 - после удаления оба списка не пустые;
- 04 - списки уже упорядочены (по году).

## Негативные тесты:
- 01 - нету аргументов;
- 02 - аргументов больше чем 4;
- 03 - aргументов меньше чем 4;
- 04 - указанного первого файла не существует;
- 05 - указанного второго файла не существует;
- 06 - входной файл пустой;
- 07 - вместо числа (год выпуска) символы;
- 08 - после удаления оба спика пустые;
- 09 - год отрицательный;
- 10 - год равен нулю.