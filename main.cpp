#include <iostream>
#include "PolynomialSolver.hpp"

int main(int ac , char **av)
{
    if (!ac) {
        std::cout << "Adding the argument!"<< std::endl;
        return 0;
    }
    // "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0";
    // "5 * X^0 + 4 * X^1 = 4 * X^0";
    std::string equation = av[1];
    PolynomialSolver obj(equation);
    obj.solve();
    return 0;
}
