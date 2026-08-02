#include <cmath>
#include <iostream>
using namespace std;

class ComplexNumber {
    double re, im;

   public:
    ComplexNumber(double re, double im) : re(re), im(im) {}

    ~ComplexNumber() {}

    double getRe() { return re; }

    double getIm() { return im; }

    void show() {
        cout << "Re = " << getRe() << " ; Im = " << getIm() << endl;
    }

    ComplexNumber operator+(const ComplexNumber &other) const {
        return ComplexNumber(re + other.re, im + other.im);
    }

    ComplexNumber operator-(const ComplexNumber &other) const {
        return ComplexNumber(re - other.re, im - other.im);
    }

    ComplexNumber operator*(const ComplexNumber &other) const {
        double reNew = re * other.re - im * other.im;
        double imNew = im * other.re + re * other.im;
        return ComplexNumber(reNew, imNew);
    }

    void operator+=(const ComplexNumber &other) {
        re += other.re;
        im += other.im;
    }

    void operator-=(const ComplexNumber &other) {
        re -= other.re;
        im -= other.im;
    }

    void operator*=(const ComplexNumber &other) {
        double reNew = re * other.re - im * other.im;
        double imNew = im * other.re + re * other.im;
        re = reNew;
        im = imNew;
    }
};

const ComplexNumber I(0, 1);

class ComplexNumerTrig : public ComplexNumber {
    double phi;

   public:
    ComplexNumerTrig(double re, double im) : ComplexNumber(re, im) {
        phi = atan2(im, re);
    }

    double getPhi() {
        return phi;
    }

    double getAbsValue() {
        double re = getRe();
        double im = getIm();
        return sqrt(re * re + im * im);
    }
};

int main() {
    ComplexNumber a(1, 2), b(3, 5);
    ComplexNumber sum = a + b;
    ComplexNumber prod = a * b;
    cout << "sum : ";
    sum.show();
    cout << "product : ";
    prod.show();

    ComplexNumerTrig c(3, 4);
    cout << "Модуль c : " << c.getAbsValue() << endl;
    cout << "Аргумент c (в радианах): " << c.getPhi() << endl;
}