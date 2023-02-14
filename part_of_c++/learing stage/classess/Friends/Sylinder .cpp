#include <iostream>
#include <math.h>

using namespace std;
#define PI 3
class Sylinder{
    private:
    double height;
    double radius;
    double area;
    double volume;
    public:
    void setSylinder(double a,double b);

    friend void PrintResualt(Sylinder);
};

int main(int argc, char const *argv[])
{
    Sylinder tın;
    tın.setSylinder(7,5);

    PrintResualt(tın);
    return 0;
}

void Sylinder::setSylinder(double a,double b){
        height = a;
        radius = b;
        volume = PI * pow(radius,2) * height;
        area = (2*PI*pow(radius,2)) + (2*PI*radius*height);

    }

void PrintResualt(Sylinder s){
    cout << "area: " << s.area << endl;
    cout << "Volume: " << s.volume << endl;
}