#include <iostream>
#include <string>

// Перечисление типов монстров
enum class MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime
};

// Структура, представляющая монстра
struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

// Функция для преобразования типа монстра в строку
std::string getMonsterTypeString(MonsterType type)
{
    switch (type)
    {
    case MonsterType::Ogre: return "Ogre";
    case MonsterType::Dragon: return "Dragon";
    case MonsterType::Orc: return "Orc";
    case MonsterType::GiantSpider: return "Giant Spider";
    case MonsterType::Slime: return "Slime";
    default: return "Unknown";
    }
}

// Функция для вывода информации о монстре
void printMonster(const Monster& monster)
{
    std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name
        << " and has " << monster.health << " health.\n";
}

int main()
{
    // Создаем экземпляры огра и слизи
    Monster ogre{ MonsterType::Ogre, "Grok", 150 };
    Monster slime{ MonsterType::Slime, "Blobby", 30 };

    // Выводим информацию о монстрах
    printMonster(ogre);
    printMonster(slime);

    return 0;
}
