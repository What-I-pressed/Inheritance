#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
	string manufacturer;
	string model;
	int year;
public:
	Vehicle(string m, string model, int y) : manufacturer(m), model(model), year(y) {};

	virtual void Start() {};

	string GetManufacturer() {
		return manufacturer;
	}

	string GetModel() {
		return model;
	}

	int GetYear() {
		return year;
	}
};

class Car: public Vehicle {
	string engineType;
	int numDoors;
public:
	Car(string eT, int nD, string m, string model, int y) : engineType(eT), numDoors(nD), Vehicle(m, model, y) {};
	
	void Start() override {
		cout << "-------------------------------" << endl;
		cout << "Engine started\nNow car can drive" << endl << endl;
	}
};

class Bicycle: public Vehicle {
	int numGears;
	bool hasBasket;
public:
	Bicycle(int nG, bool hB, string m, string model, int y) : numGears(nG), hasBasket(hB), Vehicle(m, model, y) {};

	void Start() override {
		cout << "-------------------------------" << endl;
		cout << "Bicycle is ready to ride" << endl << endl;
	}
};

class Bus : public Vehicle {
	int numSeets;
	int ticketPrice;
public:
	Bus(int nS, int tP, string m, string model, int y) : numSeets(nS), ticketPrice(tP), Vehicle(m, model, y) {};

	void Start() override {
		cout << "-------------------------------" << endl;
		cout << "All passengers entered the bus\nDoors close" << endl << endl;
	}
};



void main() {
	vector<Vehicle*> arr;
	arr.push_back(new Car("Froh", 3, "Ford", "S300", 2011));
	arr.push_back(new Bicycle(7, false, "SportLife", "Titan", 2018));
	arr.push_back(new Bus(26, 12, "Bogdan", "Uviley", 1998));
	arr.push_back(new Bicycle(3, true, "Everless", "Mandum", 2023));
	arr.push_back(new Bus(44, 350, "Tracia", "Ele", 2015));
	arr.push_back(new Car("Smth", 2, "Audi", "TraceB", 2020));
	for (int i = 0; i < arr.size(); i++) {
		arr[i]->Start();
	}
}