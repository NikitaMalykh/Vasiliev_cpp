#include <iostream>
#include <string>
using namespace std;

class Car {
    string brand;
    string color;
    double fuelTankCapacity;
    double consumption;  // литров на 100 км

   public:
    Car(string b, string col, double cap, double con)
        : brand(b), color(col), fuelTankCapacity(cap), consumption(con) {}

    string getBrand() const { return brand; }
    string getColor() const { return color; }
    double getFuelTankCapacity() const { return fuelTankCapacity; }
    double getConsumption() const { return consumption; }

    double getDistance() const {
        return 100.0 * fuelTankCapacity / consumption;
    }
};

class Truck : public Car {
    double loadCapacity;  // тонны

   public:
    Truck(string b, string col, double cap, double con, double load)
        : Car(b, col, cap, con), loadCapacity(load) {}

    double costTransportation(double priceLiterGasoline) const {
        double cons = getConsumption();  // расход л/100км
        return (cons / 100.0) * priceLiterGasoline / loadCapacity;
    }
};

int main() {
    Car car("Lada", "White", 50.0, 10.0);
    Truck truck("Kamaz", "Orange", 300.0, 30.0, 15.0);

    cout << car.getDistance() << endl;
    cout << truck.getDistance() << endl;
    cout << truck.costTransportation(52.0) << endl;
}