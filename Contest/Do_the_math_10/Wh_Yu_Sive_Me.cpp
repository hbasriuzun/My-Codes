#include <bits/stdc++.h>

using namespace std;
int countPrimes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    int sum = 0;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    unsigned long long int number = 10000000;
    std::cout << "Bir sayi girin: ";

    auto start = std::chrono::high_resolution_clock::now();

    unsigned long long int result = countPrimes(number);
    long one = log10(number)/log10(3);

    std::cout << "Girilen sayiya kadar bu sayıda asal sayı vardır: " << result << std::endl;
    std::cout << "Girilen sayıların logu: " <<  one << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Program çalışma süresi: " << duration.count() << " saniye." << std::endl;

    return 0;
}
