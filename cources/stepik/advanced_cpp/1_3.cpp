/*
================================
TASK:
================================

Напишите на языке C / C++ программу, определяющую номер треугольного числа 
(см. также последовательность A000217 в «Энциклопедии целочисленных последовательностей»).

Примечание: число 0 (ноль) не считается принадлежащим ряду, который считается начинающимся 
с единицы: 1, 3, 6, 10, 15, 21, 28, ... 

Вход: одно целое (возможно, со знаком «плюс» и символом «перевод строки» \n) число в диапазоне 
от 1 до 9'223'372'036'854'775'807.

Выход: порядковый номер поданного на вход числа в последовательности треугольных чисел или 0 
(ноль), если такого числа в последовательности нет. Символ 0 (ноль) должен выдаваться и во всех 
случаях подачи на вход некорректных (отрицательных и лежащих вне допустимого диапазона положительных 
числовых, а также символьных / строковых) данных.

Sample Input:
10
Sample Output:
4
*/

/*
================================
SOLUTION:
================================
*/

#include <iostream>
#include <cmath>

const long double UPPER_LEVEL = 9223372036854775807.0;
const long double LOWER_LEVEL = 1.0;


int main(int argc, char const *argv[])
{
    long double input;
    std::cin >> input;

    if(input < LOWER_LEVEL || input > UPPER_LEVEL ||  input - llround(input) > 0.0)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    // formula from here: https://en.wikipedia.org/wiki/Triangular_number
    // see: Triangular roots and tests for triangular numbers
    long long result = (sqrt(8*input + 1)-1)/2;

    if(result*(result+1)/2 == input)
    {
        std::cout << result << '\n';
        return 0;
    }

    std::cout << 0 << '\n';
    return 0;
}
