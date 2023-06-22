
#include <iostream>

class Car
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual bool isFull() = 0; //petrol
	virtual void showSpeed() = 0;
	virtual void controlDirections() = 0; //hand wheel
	virtual void engine() = 0;
	virtual void move() = 0;
};


int main()
{
	std::cout << "Interface for Car class\n";

	return 0;
}

