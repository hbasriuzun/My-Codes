#include <iostream>
#include <chrono>

// Hızlı matris üs alma (Fast Exponentiation) yöntemi
void multiplyMatrix(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void powerMatrix(long long F[2][2], long long n) {
    if (n <= 1)
        return;

    long long M[2][2] = {{1, 1}, {1, 0}};

    powerMatrix(F, n / 2);
    multiplyMatrix(F, F);

    if (n % 2 != 0)
        multiplyMatrix(F, M);
}

long long fibonacci(long long n) {
    if (n <= 0)
        return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(F, n - 1);

    return F[0][0];
}

int main() {
    long long n;
    std::cout << "Fibonacci dizisinin n. terimini hesaplamak için n değerini girin: ";
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();  // Başlama zamanını kaydet

    long long result = fibonacci(n);

    auto end = std::chrono::high_resolution_clock::now();    // Bitiş zamanını kaydet
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);  // Süreyi hesapla

    std::cout << "F(" << n << ") = " << result << std::endl;
    std::cout << "Program " << duration.count() << " mikrosaniye sürdü." << std::endl;

    return 0;
}
