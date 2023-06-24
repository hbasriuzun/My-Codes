#include <iostream>
#include <string>
using namespace std;

class People
{
private:
    string name;
    int age;
    int Birthday_month;
public:
    People();
    People(string namevalue, int agevalue, int monthvalue);
    ~People();
};

People::People(string namevalue, int agevalue, int monthvalue) 
: name(namevalue) , age(agevalue), Birthday_month(monthvalue)    
{
    

    if (monthvalue > 12 || monthvalue < 1)
    {
        cout << "illegal month value. " << endl;
        exit(1);
    }
    
    
}

People::People() : name("empty"), age(0), Birthday_month(0){}

People::~People()
{
}


int main(int argc, char const *argv[])
{
    People p1("Burcu",19,4);

    return 0;
}
