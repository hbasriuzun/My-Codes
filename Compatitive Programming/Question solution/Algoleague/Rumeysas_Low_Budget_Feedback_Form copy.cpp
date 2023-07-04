#include <iostream>
#include <unordered_map>
#include <cmath>
#include <ctime>

typedef uint64_t ull;

std::unordered_map<ull, ull> divisor;

ull Calculate_positive_divisor_iterative(ull num) {
    if (num == 0) {
        return 0; // veya hata durumuna göre işlem yapabilirsiniz
    }

    ull sum = 1; // num'i de dahil et

    for (ull i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }

    return sum;
}

int main() {
    divisor[1] = 1;
    divisor[2] = 1;
    divisor[3] = 1;

    ull n;
    std::cin >> n;
    
    std::clock_t startTime = std::clock();
    std::cout << Calculate_positive_divisor_iterative(n) << std::endl;
    std::cout << "Elapsed time: " << double(std::clock() - startTime) / CLOCKS_PER_SEC << " seconds." << std::endl;

    return 0;
}
