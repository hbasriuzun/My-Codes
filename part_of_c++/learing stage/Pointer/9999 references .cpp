#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void Increamen (int a){
    a ++;
}

int main(int argc, char const *argv[])
{
    int a{5} ,b{4};
    int & ref = a;
    LOG(ref);
    ref = b;
    LOG(ref);


    Increamen(a);
    LOG(a);

    return 0;
}
