#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *p_number5{new int};
    int *p_number6{new int (23)};
    int *p_number7{new int {24}};

    cout << endl;
    cout << p_number5 << endl;
    cout << p_number6 << endl;
    cout << p_number7 << endl;

    cout << *p_number5 << endl;
    cout << *p_number6 << endl;
    cout << *p_number7 << endl;

    delete p_number6;

    cout << "Delete number :" << *p_number6 << endl;
    return 0;
}
