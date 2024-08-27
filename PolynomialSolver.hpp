# ifndef __POLYNOMIALSOLVER_HPP__
# define __POLYNOMIALSOLVER_HPP__
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
class PolynomialSolver {
    private:
        std::map<int, double> coefficients;
        int degree;
        
        void parseEquation(const std::string& equation);
        void reduceEquation();
        void solveLinear();
        void solveQuadratic();
        
    public:
        PolynomialSolver(const std::string& equation);
        void solve();
};

PolynomialSolver::PolynomialSolver(const std::string & equation) {
    this->parseEquation(equation);
    this->degree = this->coefficients.rbegin()->first;
}

void PolynomialSolver::reduceEquation() {
    int first = 0;
    std::cout << "Reduced form: ";
    for (auto& elem: this->coefficients) {
        if (elem.second < 0)
            std::cout << ((first) ? " - " : "") << elem.second * -1 << " * X^" << elem.first;
        else
            std::cout << ((first) ? " + " : "") << elem.second << " * X^" << elem.first;
        first = 1;
    }
    std::cout << "= 0" << std::endl;

    std::cout << "Polynomial degree: " << this->degree << std::endl;
}

void PolynomialSolver::solveLinear() {
    double solution = -this->coefficients.begin()->second / this->coefficients.rbegin()->second;
    std::cout << solution << std::endl;
}

void PolynomialSolver::solveQuadratic() {
    double a = coefficients[2];
    double b = coefficients[1];
    double c = coefficients[0];
    
    double discriminant = b*b - 4*a*c;
    std::cout << "Discriminant is " << discriminant << std::endl;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2*a);
        double root2 = (-b - sqrt(discriminant)) / (2*a);
        std::cout << "is strictly positive, the two solutions are:\n" << root1 << std::endl << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2*a);
        std::cout << "the one solution is: " << root << std::endl;
    } else {
        double rootReal = -b / (2*a);
        double rootImaginer = sqrt(discriminant) / (2*a);
        std::cout << "is strictly negative, the two solutions are: " << std::endl;
        std::cout << rootReal << " + i" << rootImaginer << std::endl;
        std::cout << rootReal << " - i" << rootImaginer << std::endl;
    }
}

void PolynomialSolver::solve() {
    this->reduceEquation();
    if (this->degree == 1) {
        std::cout << "The solution is:" << std::endl;
        this->solveLinear();
    } else if (this->degree == 2) {
        this->solveQuadratic();
    } else {
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
    }
}

void PolynomialSolver::parseEquation(const std::string& equation) {
    std::vector<std::string> tokens;
    std::stringstream str(equation);
    std::string token;
    int equal = 1;

    while (std::getline(str, token, ' ')) {
        tokens.push_back(token);
    }

    int neg = 1;
    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "-" ) {
            neg = -1;
            continue;
        }else if (tokens[i] == "=") {
            equal = -1;
            neg = 1;
            continue;
        }
        else if (tokens[i] == "+") {
            neg = 1;
            continue;
        }
        std::string number = tokens[i + 2].substr(2);

        int degree = std::stoi(number);
        double coefficient = std::stod(tokens[i]);
        if (coefficients.count(degree)) {
            
            coefficients[degree] = coefficients[degree] + coefficient * neg * equal;
        }else {
            this->coefficients.insert({degree, coefficient * neg});
        }
        i += 2;
    }

}


#endif
