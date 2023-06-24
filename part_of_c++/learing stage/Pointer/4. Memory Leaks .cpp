#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int *pnumber1{new int(62)};
    
    int number{55};

    pnumber1 = &number;

    int *pnumber{new int{55}};

    pnumber = new int{63};

    delete pnumber;
    pnumber = nullptr;

    return 0;
}
