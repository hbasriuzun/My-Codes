#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int * pnumber{};
    pnumber = new int(8);

    if (!(pnumber == nullptr)){
        cout << "pnumber point to valid adress :" << pnumber << endl;
        cout << *pnumber << endl;
    }else{
        cout << "pnumber point to invalid adress" << endl;
    }
    

    delete pnumber;
    nullptr;


    return 0;
}
