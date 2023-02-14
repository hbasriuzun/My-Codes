#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {

    public:
        Cylinder() = default;
        
        Cylinder(double rad_param, double height_param){
            base_radius = rad_param;
            height = height_param;
        }

        double volume(){
            return PI * base_radius * height * base_radius;
        }

    private:
    double base_radius{1};
    double height{1};
};aaaaa


int main(){
    Cylinder cylinder1(10,4);
    std::cout << "volume : " << cylinder1.volume() << std::endl;
   
    return 0;
}