
#include "PolynomialSolver.hpp"

int valid(std::string equation) {
    std::regex pattern(R"(^([-+]?\d+(\.\d+)?\s\*\sX\^\d+(\s[-+]\s\d+(\.\d+)?\s\*\sX\^\d+)*)\s=\s([-+]?\d+(\.\d+)?\s\*\sX\^\d+(\s[-+]\s\d+(\.\d+)?\s\*\sX\^\d+)*))");

    bool ret = std::regex_match(equation, pattern);
    return ret;
}

int main(int ac , char **av)
{
    if (ac == 1) {
        std::cout << "Adding the argument!"<< std::endl;
        return 0;
    } else if (!valid(av[1])) {
        std::cout << "Invalid equation" << std::endl;
        return 0;
    }
    // "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0";
    // "5 * X^0 + 4 * X^1 = 4 * X^0";
    std::string equation = av[1];
    PolynomialSolver obj(equation);
    obj.solve();
    return 0;
}
