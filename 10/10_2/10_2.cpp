#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Структура для хранения данных студента
struct Student
{
    std::string name;
    int grade;
};

// Функция для сравнения двух студентов по оценкам (для сортировки)
bool compareStudents(const Student& a, const Student& b)
{
    return a.grade > b.grade; // сортируем по убыванию оценок
}

int main()
{
    // Спросим пользователя, сколько студентов он хочет ввести
    std::cout << "How many students do you want to enter? ";
    int numStudents;
    std::cin >> numStudents;

    // Создаем вектор для хранения данных всех студентов
    std::vector<Student> students;

    // Считываем данные для каждого студента
    for (int i = 0; i < numStudents; ++i)
    {
        Student student;
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> student.name;
        std::cout << "Enter the grade of student " << i + 1 << ": ";
        std::cin >> student.grade;
        students.push_back(student);
    }

    // Сортируем список студентов по оценкам
    std::sort(students.begin(), students.end(), compareStudents);

    // Выводим отсортированный список студентов
    for (const auto& student : students)
    {
        std::cout << student.name << " got a grade of " << student.grade << "\n";
    }

    return 0;
}