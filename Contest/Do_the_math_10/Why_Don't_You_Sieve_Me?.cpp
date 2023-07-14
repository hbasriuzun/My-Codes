#include <iostream>
#include <vector>

// Verilen sayıya kadar olan asal sayıları bulan ve toplayan fonksiyon
unsigned long long int sumOfPrimes(unsigned long long int n) {
    // İlk adım: Tüm sayıları içeren bir vektör oluşturun ve tüm elemanları "asal" olarak işaretleyin
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // İkinci adım: Asal olmayan sayıları eleyin
    for (unsigned long long int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (unsigned long long int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Üçüncü adım: Asal sayıları toplayın
    unsigned long long int sum = 0;
    for (unsigned long long int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    unsigned long long int number;
    std::cout << "Bir sayi girin: ";
    std::cin >> number;

    unsigned long long int result = sumOfPrimes(number);

    std::cout << "Girilen sayiya kadar olan asal sayilarin toplami: " << result << std::endl;

    return 0;
}
