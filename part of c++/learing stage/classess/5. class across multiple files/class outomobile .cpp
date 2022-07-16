#include <iostream>

using namespace std;

class Automoabile{
    public:
        void setPrice(double newPrice);
        void setProfid(double newProfit);
        double getPrice();
    private:
        double price;
        double profit;
        double getProfid();
};



int main(int argc, char const *argv[])
{
    Automoabile jaguar, hyundai;

    
    return 0;
}
