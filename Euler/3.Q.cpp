#include <iostream>
#include <vector>

std::vector<long long> primeFactors(long long n) {
    std::vector<long long> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    long long num = 600851475143;
    std::vector<long long> factors = primeFactors(num);

    std::cout << num << " sayısının asal çarpanları:" << std::endl;
    for (long long factor : factors) {
        std::cout << factor << " ";
    }

    return 0;
}
