#include <iostream>
using namespace std;

class BankAccunt
{
private:
    /* data */
public:
    BankAccunt(double Balance, double rate);
    BankAccunt(int dollars, int cents, double rate);
    BankAccunt(int dollars, double rate);
    BankAccunt();

    void update();
    void input();
    void output();
    
    double getBalance();
    int getDollars();
    int getCent();
    double getRate();

    void setBalance();
    void setBalance();
    void setRate()

    private:

    
};

BankAccunt::BankAccunt(/* args */)
{
}



int main(int argc, char const *argv[])
{

    return 0;
}
