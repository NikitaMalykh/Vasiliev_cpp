#include <cmath>
#include <iostream>
using namespace std;

class Parallelepiped {
    double width, height, length;

   public:
    Parallelepiped(double w, double h, double l) : width(w), height(h), length(l) {}

    ~Parallelepiped() {}

    void getInfo() {
        cout << "width : " << width << endl;
        cout << "heigth : " << height << endl;
        cout << "length : " << length << endl;
    }

    double getVolume() {
        return width * height * length;
    }
};

class HeavyParallelepiped : public Parallelepiped {
    double weight;

   public:
    HeavyParallelepiped(double w, double h, double l, double wt) : Parallelepiped(w, h, l), weight(wt) {}

    double getWeight() {
        return weight;
    }

    double getDensity() {
        return weight / getVolume();
    }

    HeavyParallelepiped operator/(double value) {
        weight /= value;
        return *this;
    }

    HeavyParallelepiped operator*(double value) {
        weight *= value;
        return *this;
    }

    HeavyParallelepiped operator+(HeavyParallelepiped &other) {
        double volumeNew = getVolume() + other.getVolume();
        double weightNew = weight + other.weight;
        double side = cbrt(volumeNew);
        return HeavyParallelepiped(side, side, side, weightNew);
    }
};

int main() {
    HeavyParallelepiped obj(1, 4, 5, 20);
    cout << "density_1 : " << obj.getDensity() << endl;
    HeavyParallelepiped obj2(1, 5, 10, 50);
    HeavyParallelepiped obj3 = obj + obj2;
    cout << "weight_3 : " << obj3.getWeight();
}