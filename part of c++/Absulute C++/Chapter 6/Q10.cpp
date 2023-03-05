#include <bits/stdc++.h>
using namespace std;

class Weight
{
private:
    int pounds;
    int ounces;
    int Kilograms;
public:
    Weight(int pounds, int ounces);
    Weight(int Kilograms);
    ~Weight();
    void setWeightPounds(int pounds);
    void setWeightOunces(int ounces);
    void setWeightKilograms(int Kilograms);
    int getWeightPounds();
    int getWeightOunces();
    int getWeightKilograms();
    void display();
};

Weight::Weight(int pounds, int ounces)
{
    this->pounds = pounds;
    this->ounces = ounces;
}

Weight::Weight(int Kilograms)
{
    this->Kilograms = Kilograms;
    this->pounds = Kilograms * 2.21;
    this->ounces = pounds * 16;
}

Weight::~Weight()
{
}

void Weight::setWeightPounds(int pounds)
{
    this->pounds = pounds;
    this->Kilograms = pounds / 2.21;
    this->ounces = pounds * 16;
}

void Weight::setWeightOunces(int ounces)
{
    this->ounces = ounces;
    this->pounds = ounces / 16;
    this->Kilograms = pounds / 2.21;
}

void Weight::setWeightKilograms(int Kilograms)
{
    this->Kilograms = Kilograms;
    this->pounds = Kilograms * 2.21;
    this->ounces = pounds * 16;
}

int Weight::getWeightPounds()
{
    return pounds;
}

int Weight::getWeightOunces()
{
    return ounces;
}

int Weight::getWeightKilograms()
{
    return Kilograms;
}

void Weight::display()
{
    cout << "Pounds: " << pounds << endl;
    cout << "Ounces: " << ounces << endl;
    cout << "Kilograms: " << Kilograms << endl;
}

int main(int argc, char const *argv[])
{
    Weight w1(1, 2);
    w1.display();
    Weight w2(3);
    w2.display();
    cout << w1.getWeightPounds() << endl;
    cout << w1.getWeightOunces() << endl;
    cout << w1.getWeightKilograms() << endl;
    cout << w2.getWeightPounds() << endl;
    cout << w2.getWeightOunces() << endl;
    cout << w2.getWeightKilograms() << endl;
    
    return 0;
}