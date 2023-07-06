#include <iostream>
#include <string>

void generateBinaryStrings(int n, std::string prefix) {
    if (prefix.length() == n) {
        std::cout << prefix << std::endl;
        return;
    }

    generateBinaryStrings(n, prefix + "0");

    generateBinaryStrings(n, prefix + "1");
}

int main() {
    int n;
    std::cin >> n;

    generateBinaryStrings(n, "");

    return 0;
}
