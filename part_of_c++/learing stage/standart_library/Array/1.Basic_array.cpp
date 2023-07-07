#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
 
int main()
{
    auto print = [](const auto& n) { std::cout << ' ' << n; };
    //auto print = [](const auto& n) { std::cout << ' ' << n; };

    array<int, 3> a1{1, 2, 3} ; 
    
    int a5[3] = {1,2,3};

        for (auto& s: a5)
            std::cout << s << ' ';

        cout << endl;


   // a5.front();
    cout << a1.front() << endl;

    std::array<std::string, 2> a3 = { std::string("a"), "b" };

    for (const auto& s: a3)
        std::cout << s << ' ';
    
    std::cout << '\n';
 


    for (const auto& s: a1)
        std::cout << s << ' ';
    cout << endl;
 
    // deduction guide for array creation (since C++17)
    [[maybe_unused]] std::array a4{3.5, 1.0, 4.0};  // -> std::array<double, 3>
    
    for(const auto& s: a4)
        cout << s << ' ';

    cout << endl;

    for_each(a4.begin(), a4.end(), print);

    std::cout << std::endl;

    std::reverse_copy(a1.begin(), a1.end(),std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;

    for (const auto& s: a1)
        std::cout << s << ' ';
    cout << endl;
    
    return 0;
}