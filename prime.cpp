
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
    else if (n <= 3) {
        return true;
    }                        // quick check since all integers below 1 will not be prime and integers 2 and 3 are bothe prime.
    incrementModOps(modOps);
    if (n % 2 == 0) {  // Eliminates the need to check for all other modulus operation on n by an even number.
        return false;
    }
    int first100Prime[99] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
        67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
        163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
        263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367,
        373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
        479, 487, 491, 499, 503, 509, 521, 523, 541 };
    for (int i = 0; i <= 98; i = i + 1) {
        incrementModOps(modOps);
        if (n % first100Prime[i] == 0) {
            return false;
        }
    }
    for (int i = 541; i <= n / 2; i = i + 2) {   // check for all modulus operations on n by odd numbers up to n/2.
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
    else if (n <= 3) {
        return true;
    }                               // quick check since all integers below 1 will not be prime and integers 2 and 3 are bothe prime.
    incrementModOps(modOps);                                // increments modOps if modOps is not a nullptr
    if (n % 2 == 0) {  // Eliminates the need to check for all other modulus operation on n by an even number.
        return false;
    }
    int first100Prime[99] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
        67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
        163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
        263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367,
        373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
        479, 487, 491, 499, 503, 509, 521, 523, 541 };
    for (int i = 0; i <= 98; i = i + 1) {
        incrementModOps(modOps);
        if (n % first100Prime[i] == 0) {
            return false;
        }
    }
    for (int i = 541; i * i <= n; i = i + 2) {
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