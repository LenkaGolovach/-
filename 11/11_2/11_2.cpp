#include <iostream>
#include <iterator>

// array - это массив для поиска.
// target - это значение, которое мы пытаемся определить, есть оно или нет.
// min - это индекс нижней границы массива, в котором мы ищем.
// max - это индекс верхней границы массива, в котором мы ищем.
// binarySearch() должна возвращать индекс целевого элемента, если target найден, иначе -1
int binarySearch(const int* array, int target, int min, int max)
{
    if (min > max) {
        return -1;  // Если диапазон поиска стал недействительным, целевой элемент не найден
    }

    int mid = min + (max - min) / 2;  // Вычисляем среднюю точку

    if (array[mid] == target) {
        return mid;  // Если центральный элемент равен целевому, возвращаем его индекс
    }
    else if (array[mid] < target) {
        return binarySearch(array, target, mid + 1, max);  // Рекурсивный вызов для правой половины
    }
    else {
        return binarySearch(array, target, min, mid - 1);  // Рекурсивный вызов для левой половины
    }
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    constexpr int numTestValues{ 9 };
    // тестовые значения
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // ожидаемые результаты для каждого значения
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Перебираем все тестовые значения
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // Смотрим, есть ли наше тестовое значение в массиве
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
       
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // иначе функция binarySearch() не работает
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}