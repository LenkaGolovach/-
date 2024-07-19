#include <iostream>

int readNumber()
{
	int x {};
	std::cout << "Enter number:";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The answer is: " << x << '\n';
}

int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	writeAnswer(x + y);
	return 0;
}