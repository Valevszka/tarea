#include <iostream>
#include "Fraccion.h"

int main() {
    Fraccion fracciones[5];

    std::cout << "Captura de 5 fracciones:\n";

    for (int i = 0; i < 5; i++) {
        int n, d;
        std::cout << "\nFraccion " << (i + 1) << ":\n";
        std::cout << "  Numerador: ";
        std::cin >> n;

        do {
            std::cout << "  Denominador (no puede ser 0): ";
            std::cin >> d;
            if (d == 0) std::cout << "  Error: el denominador no puede ser 0.\n";
        } while (d == 0);

        fracciones[i] = Fraccion(n, d);
    }

    Fraccion sumatoria(0, 1);

    for (int i = 0; i < 5; i++) {
        sumatoria.sumar(fracciones[i]);
    }

    std::cout << "\nFracciones ingresadas:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "  " << fracciones[i].to_string() << "\n";
    }

    std::cout << "\nSumatoria total:\n";
    std::cout << "  " << sumatoria.to_string() << "\n";

    return 0;
}
