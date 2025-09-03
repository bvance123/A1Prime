﻿//main.cpp

#include "prime.hpp"​
#include "iostream"

int main() {
    constexpr int LO = 2, HI = 10000;

    // TODO: Count modulo operations for both algorithms
    long long halfOps = countModOps(isPrimeHalf, LO, HI);
    long long sqrtOps = countModOps(isPrimeSqrt, LO, HI);

    // TODO: Print the results
    std::cout << "Half method operations: " << halfOps << "\n";
    std::cout << "Square root method operations: " << sqrtOps << "\n";

    // TODO: Calculate and print the ratio
    double ratio = halfOps / sqrtOps;
    std::cout << "Ratio (Half/Sqrt): " << ratio << "\n";

    return 0;
}