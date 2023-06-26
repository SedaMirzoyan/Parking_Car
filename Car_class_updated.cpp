
#include <iostream>
#include <string>
#include <conio.h>

#define GO_LEFT 75
#define GO_RIGHT 77

class Car
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual bool isFull() = 0; //fuel amount
	virtual void showSpeed() = 0;
	virtual void controlDirections() = 0;	//hand wheel
	virtual void move() = 0;
};

class Toyota: public Car
{
private:

	std::string model; 
	std::string engine_type; //petrol, electric, hybrid or gas
	bool is_hatchback; //or sedan
	int year;
	int speed;
	int amount_of_fuel;

public:

	Toyota()
	{
		std::cout << "Default constructor\n";

		model = " ";
		engine_type = " ";
		is_hatchback = false;
		year = 0;
		speed = 0;
		amount_of_fuel = 0;
	}

	Toyota(std::string m, std::string et, bool h, int y, int s, int f)
	{
		std::cout << "Parametrized constructor\n";

		model = m;
		engine_type = et;
		is_hatchback = h;
		year = y;
		speed = s; 
		amount_of_fuel = f;
	}

	~Toyota()
	{
		std::cout << "Destructor\n";
	}

	void start() override
	{
		if (speed > 0 && speed < 10)
		{
			std::cout << "Car starts moving\n";
		}
		else
		{
			return;
		}
	}
	void stop() override
	{
		if (speed == 0)
		{
			std::cout << "Car is stopping\n";
		}
		else
		{
			std::cout << "Speed is " << speed << " ,car is still moving\n";
		}
	}
	
	bool isFull() override
	{
		bool flag = false;
		if (amount_of_fuel < 12.5)  
		{
			std::cout << "Amount of fuel is low\n";
			flag = false;
		}
		else
		{
			std::cout << "Good amount of fuel,continue driving\n";
			flag = true;
		}
		return flag;
	}

	bool getIfIsHatchback()
	{
		return is_hatchback;
	}

	void setIfIsHatchback(bool h)
	{
		if (h == false)
		{
			std::cout << "Car is sedan.\n";
		}
		else
		{
			std::cout << "Car is hatchback.\n";
		}

		is_hatchback = h;
	}


	void showSpeed() override
	{
		std::cout << "Current speed is " << speed << std::endl;
	}
	

	void controlDirections() override
	{
		int c;
		bool flag = false;

		while(!flag)
		{
			switch ((c = _getch()))
			{
			case GO_RIGHT:
				std::cout << "Turn right\n";
				flag = true;
				break;
			case GO_LEFT:
				std::cout << "Turn left\n";
				flag = true;
				break;
			//default:
			//	std::cout << "Go to the same direction\n";
			}
		}
	}


	void move() override
	{
		if (speed > 70)
		{
			std::cout << "High speed, " << speed << std::endl;
		}
		else
		{
			std::cout << "Speed is okay\n";
		}
	}
};


int main()
{
	std::cout << "Interface for Car class\n";

	Car* p = new Toyota("Camry", "hybrid", false, 2018, 80, 50);
	p->move();
	p->isFull();

	int n;
	std::cout << "Press right or left arrows for turning directions\n";
	p->controlDirections();

	Car* p1 = new Toyota("Camry", "hybrid", false, 1982, 25, 10);

	p1->move();
	p1->isFull();
	p1->stop();

	delete p;
	delete p1;

	return 0;
}

