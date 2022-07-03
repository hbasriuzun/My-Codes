#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    size_t a{'b'};
    const size_t  count{11};

    for (size_t i{} ; i < count; i++)
    {
        cout << i << endl;
    }
    

    cout << sizeof(a) << endl;
    cout << a << endl;


    return 0;
}
