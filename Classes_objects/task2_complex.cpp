#include <iostream>
using namespace std;

class ComplexNumbers {
    double re, im;

   public:
    ComplexNumbers(double re, double im) : re(re), im(im) {}

    ~ComplexNumbers() {}

    double getRe() { return re; }

    double getIm() { return im; }

    void show() {
        cout << "Re = " << getRe() << " ; Im = " << getIm() << endl;
    }

    ComplexNumbers operator+(const ComplexNumbers &other) const {
        return ComplexNumbers(re + other.re, im + other.im);
    }

    ComplexNumbers operator-(const ComplexNumbers &other) const {
        return ComplexNumbers(re - other.re, im - other.im);
    }

    ComplexNumbers operator*(const ComplexNumbers &other) const {
        double reNew = re * other.re - im * other.im;
        double imNew = im * other.re + re * other.im;
        return ComplexNumbers(reNew, imNew);
    }

    void operator+=(const ComplexNumbers &other) {
        re += other.re;
        im += other.im;
    }

    void operator-=(const ComplexNumbers &other) {
        re -= other.re;
        im -= other.im;
    }

    void operator*=(const ComplexNumbers &other) {
        double reNew = re * other.re - im * other.im;
        double imNew = im * other.re + re * other.im;
        re = reNew;
        im = imNew;
    }
};

int main() {
    ComplexNumbers a(1, 2), b(3, 5);
    ComplexNumbers sum = a + b;
    ComplexNumbers prod = a * b;
    cout << "sum : ";
    sum.show();
    cout << "product : ";
    prod.show();
}