#include <iostream>
using namespace std;
const double PI {3.1415926535897932384626433832795};

class cylinder{
    public:
        
        double base_radius{1.0};
        double height{1.0};

    public:
        double volume(){
            return PI * base_radius * base_radius * height;
        }
};

int main(int argc, char const *argv[])
{
    cylinder cylinder1;
    cout << "Volume :" << cylinder1.volume() << endl; 
    return 0;
}
