#include <iostream>
using namespace std;
#include "Cube.h"

int main(int argc, char const *argv[])
{
    basri::Cube c;
    c.setLength(3.48);
    double volume = c.getVolume();
    std::cout << volume << std::endl;

    return 0;
}




