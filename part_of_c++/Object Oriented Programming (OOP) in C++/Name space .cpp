#include <iostream>
using namespace std;

namespace coder1{
    int c = 5;

    void write(){
        cout << c << endl;
    }
}

int main(int argc, char const *argv[])
{
    int c = 8;
    cout << c << endl << coder1::c << endl;
    coder1::write();
    return 0;
}
