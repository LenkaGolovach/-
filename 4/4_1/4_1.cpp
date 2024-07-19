#include <iostream>

double getNumber() 
{
	std::cout << "Enter double value: ";
	double x{};
	std::cin >> x;
    return x;
}

char getOperation()
{
	std::cout << "Enter one of the following: +, -, *, /: ";
	char operation {};
	std::cin >> operation;
    return operation;
}

void Result(double x, char operation, double y)
{
    if (operation == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (operation == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (operation == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (operation == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
    double x{ getNumber() };
    double y{ getNumber() };
    char operation{ getOperation() };
    Result(x, operation, y);

    return 0;
}