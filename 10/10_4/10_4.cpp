#include <iostream>

// Функция для посимвольной печати строки в стиле C
void printString(const char* str)
{
    while (*str != '\0') // Проверяем, что текущий символ не является нулевым терминатором
    {
        std::cout << *str << '\n'; // Печатаем текущий символ
        ++str; // Перемещаем указатель на следующий символ
    }
}

int main()
{
    const char* str = "Hello, world!";
    printString(str); // Проверяем функцию с строковым литералом

    return 0;
}