#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

class Car
{
public:
	Car(const std::string _car_model)
		: car_model(_car_model) {}

	virtual ~Car(){}

protected:
	const std::string car_model;
};

class Mercedes : public Car
{
public:
	Mercedes(const std::string& _car_model)
		: Car(_car_model) {}

	~Mercedes()
	{
		std::cout << "Mercedes" << " " << car_model << std::endl;
	}
};

class BMW : public Car
{
public:
	BMW(const std::string& _car_model)
		: Car(_car_model) {}

	~BMW()
	{
		std::cout << "BMW" << " " << car_model << std::endl;
	}
};

class Audi : public Car
{
public:
	Audi(const std::string& _car_model)
		: Car(_car_model) {}

	~Audi()
	{
		std::cout << "Audi" << " " << car_model << std::endl;
	}
};

std::vector<Car*> FillVector(std::string& file)
{
	std::vector<Car*> v;
	std::ifstream f(file);
	std::string brand;
	std::string car_model;
	while (f >> brand >> car_model)
	{
		if (brand == "Mercedes")
		{
			v.push_back(new Mercedes(car_model));
		}
		else if (brand == "BMW")
		{
			v.push_back(new BMW(car_model));
		}
		else if (brand == "Audi")
		{
			v.push_back(new Audi(car_model));
		}
	}
	return v;
}

int main() {
	std::string file("lab22.txt");
	std::vector<Car*> cars = FillVector(file);

	for (Car* car : cars) {
		delete car;
	}
	return 0;
}