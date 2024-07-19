#include <iostream>

int main()
{
	int a{};
	std::cout << "Enter an integer: ";
	std::cin >> a;

	int b{};
	std::cout << "Enter another integer: ";
	std::cin >> b;

	std::cout << a << " + " << b << " is " << a + b << ".\n";
	std::cout << a << " - " << b << " is " << a - b << ".\n";

	return 0;
}