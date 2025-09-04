//test.cpp

#include "prime.hpp"
#include <cassert>
#include <iostream>


// Testing few prime identification? 
void testPrimeId() {
    assert(isPrimeHalf(2));
    assert(isPrimeSqrt(2));
    assert(isPrimeHalf(113));
    assert(isPrimeSqrt(113));
    assert(isPrimeHalf(541));
    assert(isPrimeSqrt(541));
    assert(isPrimeHalf(1009)); 
    assert(isPrimeSqrt(1009));
}
//Testing composite numbers?
void testComposNum() {
    assert(!isPrimeHalf(8));
    assert(!isPrimeSqrt(8));
    assert(!isPrimeHalf(224));
    assert(!isPrimeSqrt(224));
    assert(!isPrimeHalf(568));
    assert(!isPrimeSqrt(568));
    assert(!isPrimeHalf(1008));
    assert(!isPrimeSqrt(1008));
}
// test for few range of prime numbers if both methods are consistent?
void testConsistentPrimeRanges() {
    assert(isPrimeHalf(2) == isPrimeSqrt(2));
    assert(isPrimeHalf(3) == isPrimeSqrt(3));
    assert(isPrimeHalf(5) == isPrimeSqrt(5));
    assert(isPrimeHalf(7) == isPrimeSqrt(7));
}

// Testing mod operation counts?
void testModCounts() {
    assert(countModOps(isPrimeHalf, 2, 17) == 25);
    assert(countModOps(isPrimeSqrt, 2, 17) == 20);
    assert(countModOps(isPrimeHalf, 2, 10) == 10);
    assert(countModOps(isPrimeSqrt, 2, 10) == 9);

}
// test edge cases
void testEdgeCases() {
    assert(!isPrimeHalf(0));
    assert(!isPrimeSqrt(0));
    assert(!isPrimeHalf(1));
    assert(!isPrimeSqrt(1));
    assert(!isPrimeHalf(-1));
    assert(!isPrimeSqrt(-1));
}


int main() {
    testPrimeId();
    testComposNum();
    testConsistentPrimeRanges();
    testModCounts();
    testEdgeCases();
    std::cout << "All test casses passed!";
    return 0;
}