#include <iostream> 
using namespace std;

int main(int argc, char const *argv[])
{
    double floor = 6 , build1 = 600000, amanities, taxes, total;
    
    for (size_t i = 0; i < floor; i++)
    {
        build1 += build1 * i * 2 / 100;
        amanities = build1 * 3 / 100;
        taxes = (build1 + amanities) * 20 / 100;
        total = build1 + amanities + taxes;
        cout << "floor " << i << " base price : " << build1 << endl;
        cout << "floor " << i << " amanities : " << amanities << endl;
        cout << "floor " << i << " taxes : " << taxes << endl;
        cout << "floor " << i << " total cost : " << total << endl;
        cout << endl;
    }
    


    return 0;
}
