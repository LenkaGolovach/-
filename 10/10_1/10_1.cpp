#include <iostream>
#include <array>

// Перечисляем типы предметов
enum ItemType
{
    HealthPotion,
    Torch,
    Arrow,
    MaxItems // Вспомогательное значение для определения размера массива
};

// Создаем массив для хранения количества каждого типа предметов
using Inventory = std::array<int, ItemType::MaxItems>;

Inventory createStartingInventory()
{
    // Начальные значения предметов: 2 зелья здоровья, 5 факелов, 10 стрел
    return { 2, 5, 10 };
}

// Функция для подсчета общего количества предметов
int countTotalItems(const Inventory& inventory)
{
    int totalItems = 0;
    for (int count : inventory)
    {
        totalItems += count;
    }
    return totalItems;
}

int main()
{
    // Создаем начальный инвентарь
    Inventory inventory = createStartingInventory();

    // Выводим общее количество предметов и количество факелов
    std::cout << "Total number of items: " << countTotalItems(inventory) << "\n";
    std::cout << "Number of torches: " << inventory[ItemType::Torch] << "\n";

    return 0;
}
