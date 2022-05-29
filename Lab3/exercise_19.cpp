#include <iostream>

using namespace std;

#define BRAND_LEN ((int) 20)

class Car
{
    char* brand;
    int prod_year;

public:
    Car()
    {
        brand = new char[BRAND_LEN];
    }

    void setDataBase(char* brand, int prod_year)
    {
        this->brand = brand;
        this->prod_year = prod_year;
    }

    void displayCar()
    {
        cout << "Brand: " << this->brand << endl;
        cout << "Prod. Year: " << this->prod_year << endl;
    }
};

class TheCar: public Car
{
    int reg_num;

public:
    void setDataTheCar(char* brand, int prod_year, int reg_num)
    {
        setDataBase(brand, prod_year);
        this->reg_num = reg_num;
    }

    void displayTheCar()
    {
        displayCar();
        cout << "Reg. number: " << this->reg_num << endl;
    }
};

class RentTheCar: public TheCar
{
    int rent_price;

public:
    void setDataRent(char* brand, int prod_year, int reg_num, int rent_price)
    {
        setDataTheCar(brand, prod_year, reg_num);
        this->rent_price = rent_price;
    }

    void displayAll()
    {
        displayTheCar();
        cout << "Rent price: " << this->rent_price << endl;
    }
};

int main()
{
    RentTheCar rentCar;

    rentCar.setDataRent("BMW", 2020, 8281, 3000);

    rentCar.displayAll();

    return 0;
}
