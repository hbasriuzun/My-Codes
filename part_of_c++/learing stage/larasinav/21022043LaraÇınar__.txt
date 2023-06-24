#include <iostream>
using namespace std;

int main() {
    uint32_t data = 0x84283473; 
    uint32_t part1 = (data >> 20) & 0xFFF; 
    uint32_t part2 = (data >> 6) & 0x3FFF; 
    uint32_t part3 = data & 0x3F; 

    cout << "Part 1: " << part1 << endl;
    cout << "Part 2: " << part2 << endl;
    cout << "Part 3: " << part3 << endl;

    return 0;
}
