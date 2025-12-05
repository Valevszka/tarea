#ifndef FRACCION_H
#define FRACCION_H

#include <string>

class Fraccion {
private:
    int num;
    int den;

    int mcd(int a, int b);
    void simplificar();

public:
    Fraccion();             
    Fraccion(int n, int d); 

    int getNum() const;
    int getDen() const;

    void setNum(int n);
    void setDen(int d);

    double calc_valor_real() const;

    void sumar(const Fraccion& otra);

    std::string to_string() const;
};

#endif
