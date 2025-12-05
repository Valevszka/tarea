#include "Fraccion.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>

int Fraccion::mcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return (a == 0) ? 1 : a;
}

void Fraccion::simplificar() {
    if (den == 0) return;
    int divisor = mcd(num, den);
    num /= divisor;
    den /= divisor;

    if (den < 0) {
        den = -den;
        num = -num;
    }
}

Fraccion::Fraccion() {
    num = 1;
    den = 2;
}

Fraccion::Fraccion(int n, int d) {
    if (d == 0) {
        num = n;
        den = 1;
    } else {
        num = n;
        den = d;
    }
    simplificar();
}

int Fraccion::getNum() const { return num; }
int Fraccion::getDen() const { return den; }

void Fraccion::setNum(int n) { num = n; simplificar(); }

void Fraccion::setDen(int d) {
    if (d == 0) den = 1;
    else den = d;
    simplificar();
}

double Fraccion::calc_valor_real() const {
    return static_cast<double>(num) / static_cast<double>(den);
}

void Fraccion::sumar(const Fraccion& otra) {
    int nuevoNum = num * otra.den + den * otra.num;
    int nuevoDen = den * otra.den;

    num = nuevoNum;
    den = nuevoDen;
    simplificar();
}

std::string Fraccion::to_string() const {
    std::ostringstream oss;
    oss << num << "/" << den
        << " (" << std::fixed << std::setprecision(2)
        << calc_valor_real() << ")";
    return oss.str();
}
