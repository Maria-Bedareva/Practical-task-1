# Многопоточное вычисление факториала

1. Создание программы, которая вычисляет факториал числа с использованием многопоточности
2. Разделение вычислений на несколько потоков
3. Объединение результатов

## Работа программы 

Программа запрашивает число, для которого нужно вычислить факториал. Затем разделяет на равные диапазоны. Для каждого потока вычисляется свой диапазон значений для вычисления факториала. После завершение всех потоков, результаты объединяются. Итог выводится на экран.

Также при использовании библиотеки <kbd>chrono</kbd>, программа подсчитывает за какое время получается результат.



