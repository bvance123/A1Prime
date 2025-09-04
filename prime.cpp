
#include "prime.hpp"

using namespace std;

void incrementModOps(long long* modOps){
    if (modOps) {
        *modOps = *modOps + 1;
    }                                // increments modOps if modOps is not a nullptr
}



// TODO: Implement isPrimeHalf
bool isPrimeHalf(int n, long long* modOps) {
    if (n <= 1) {
        return false;
    }
    else if (n <= 2) {
        return true;
    }                        // quick check since all integers below 1 will not be prime and integers 2 is prime.
    incrementModOps(modOps);
    if (n % 2 == 0) {  // Eliminates the need to check for all other modulus operation on n by an even number.
        return false;
    }
    for (int i = 3; i <= n / 2; i = i + 2) {   // check for all modulus operations on n by odd numbers up to n/2.
        incrementModOps(modOps);
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// TODO: Implement isPrimeSqrt
bool isPrimeSqrt(int n, long long* modOps) {

    if (n <= 1) {
        return false;
    }
    else if (n <= 2) {
        return true;
    }                               // quick check since all integers below 1 will not be prime and integers 2 and 3 are bothe prime.
    incrementModOps(modOps);                                // increments modOps if modOps is not a nullptr
    if (n % 2 == 0) {  // Eliminates the need to check for all other modulus operation on n by an even number.
        return false;
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        incrementModOps(modOps);                            // increments modOps if modOps is not a nullptr
        if (n % i == 0) {
            return false;
        }
    }
    return true;


}

// TODO: Implement countModOps

long long countModOps(PrimeFn isPrime, int lo, int hi) {
    long long opsCount = 0;          // generates a count to keep track
    for (int i = lo; i <= hi; i = i + 1) { // runs the provided isPrime funtion from inputs lo to hi while assinging the adress of opsCount as the adress to record modOps
        isPrime(i, &opsCount);
    }
    return opsCount;
}