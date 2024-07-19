#include "constants.h"

#include <iostream>



double getTowerHeiht()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

// Узнаём время, которое мяч будет падать по формуле
double calculateTime(double towerHeight, int seconds)
{
	double distance{ (gravity * (seconds * seconds)) / 2.0 };
	double currentTime{ (towerHeight - distance) };

	return currentTime;
}

//Выводим значение высоты, на которой находится мяч от земли, пока он не достигнет нулевого значения
void printHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateHeight(double towerHeight, int seconds)
{
	double height{ calculateTime(towerHeight, seconds) };
	printHeight(height, seconds);
}

int main()
{
	const double towerHeight{ getTowerHeiht() };

	calculateHeight(towerHeight, 0);
	calculateHeight(towerHeight, 1);
	calculateHeight(towerHeight, 2);
	calculateHeight(towerHeight, 3);
	calculateHeight(towerHeight, 4);
	calculateHeight(towerHeight, 5);

	return 0;
}