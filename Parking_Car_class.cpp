
#include <iostream>
#include <string>
#include <vector>

class Car {
    bool type; //if electric or not
    bool is_hatchback; //or sedan
    std::string mark; //Mercedes, BMW...
    int year;
    std::string seria;

public:

    Car()
    {
        std::cout << "Default constructor for Car\n";

        type = false;
        is_hatchback = false;
        mark = " ";
        year = 0;
        seria = " ";
    }

    Car(bool t, bool ish, std::string m, int y, std::string s )
    {
        std::cout << "Parametrized constructor  for Car\n";

        type = t;
        is_hatchback = ish;
        mark = m;
        year = y;
        seria = s;
    }

    ~Car()
    {
        std::cout << "Destructor  for Car\n";
    }


    bool getType()
    {
        return type;
    }

    void setType(bool t)
    {
        if (t == false)
        {
            std::cout << "This is a petrol car.\n";
        }
        else
        {
            std::cout << "This is a electric car\n";
        }

        type = t;
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
            std::cout << "Car is hatchback\n";
        }

        is_hatchback = h;
    }

    std::string getMark()
    {
        return mark;
    }

    void setMark(std::string m)
    {
        if (m.empty())
        {
            std::cout << "Mark is empty.\n";
        }
        mark = m;
    }

    int getYear()
    {
        return year;
    }

    void setYear(int y)
    {
        if (y <= 0)
        {
            std::cout << "Invalid year\n";
        }
        year = y;
    }


    std::string getSeria()
    {
        return seria;
    }

    void setSeria(std::string s)
    {
        if (s.empty())
        {
            std::cout << "Seria is empty.\n";
        }
        seria = s;
    }

    void printCarAttributes()
    {
        std::cout << "type is " << this->type << ", is_hatchback is " << this->is_hatchback << ", mark is " << this->mark << ", year is " << this->year
            << ", seria is " << this->seria << std::endl;
    }

};


class Parking {
    int parking_attendant_num; //number of parking attendants
    int place_num; //1st, 2nd...
    int place_count;  //how many places are not busy
    bool is_busy; //if there is a car in that place
    int max_size;
    bool isFree; //or payable

    Car* p;
    std::vector<Car*> cars;

public:
    inline Parking()
    {
        std::cout << "Default constructor for Parking\n";

        parking_attendant_num = 0;
        place_num = 0;
        place_count = 0;
        is_busy = false;
        max_size = 0;
        isFree = 0;
        this->p = nullptr;
    }

    Parking(int pan, int pn, int pc, bool b, int ms, bool f, Car* p1)
    {
        std::cout << "Parametrized constructor  for Parking\n";

        parking_attendant_num = pan;
        place_num = pn;
        place_count = pc;
        is_busy = b;
        max_size = ms;
        isFree = f;
        this->p = p1;
    }

    ~Parking()
    {
        delete p;
        std::cout << "Destructor  for Parking\n";
    }

    void setCar(Car* p)
    {
        std::cout << "Set car\n";
        cars.push_back(p);
    }


    int getNumberOfParkingAttendandts()
    {
        return parking_attendant_num;
    }

    void setNumberOfParkingAttendandts(int pan)
    {
        if (pan < 0)
        {
            std::cout << "the number of attendants should be greater than or equal to 0\n";
        }
        parking_attendant_num = pan;
    }


    int getPlaceNum()
    {
        return place_num;
    }

    void setPlaceNum(int p)
    {
        if (p <= 0)
        {
            std::cout << "the location of the car can't be less than 0\n";
        }
        place_num = p;
    }

    int getPlaceCount()
    {
        return place_count;
    }

    void setPlaceCount(int p)
    {
        if (p < 0)
        {
            std::cout << " Count of the places can't be less than 0\n";
        }
        place_count = p;
    }


    int getMazSize()
    {
        return max_size;
    }


    void setMaxSize(int ms)
    {
        if (ms <= 0)
        {
            std::cout << " Size can't be <= 0\n";
        }
        max_size = ms;
    }


    bool getIsBusy()
    {
        return is_busy;
    }

    void setIsBusy(bool ib)
    {
        if (ib == false)
        {
            std::cout << "This place is busy.\n";
        }
        else
        {
            std::cout << "This place is free.\n";
        }
        is_busy = ib;
    }


    bool getIsFree()
    {
        return isFree;
    }

    void setIsFree(bool isf)
    {
        if (isf == false)
        {
            std::cout << "This is not free parking, it is payable.\n";
        }
        else
        {
            std::cout << "This is free parking!!!\n";
        }

        isFree = isf;
    }

    void printParkingAttributes()
    {
        std::cout << "parking_attendant_num is " << this->parking_attendant_num << ", place_num is " << this->place_num << ", place_count is " << this->place_count << ", is_busy is " << this->is_busy
            << ", max_size is " << this->max_size << ", isFree is " << this->isFree << std::endl;
    }

};


int main()
{
    Car* car1 = new Car(true, false, "BMW", 2023, "3");
    Car* car2 = new Car(false, false, "Tesla", 2012, "S");
    Car* car3 = new Car(true, true, "Nissan", 2004, "Tiida");
    std::vector<Car*> cars;

    car1->printCarAttributes();
    car2->printCarAttributes();
    car3->printCarAttributes();

    Parking parking;

    parking.setCar(car1);
    parking.setCar(car2);
    parking.setCar(car3); 

    delete car1;
    delete car2;
    delete car3;

    return 0;
}


