#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    //We van define the vector like this
    vector<int> v1{1,2,3,4};

    cout << v1[0] << endl;
    cout << v1.back() << endl;
    cout << v1.front() << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << "sizeof: " << sizeof(v1[0]) << endl;
    cout << endl;

    v1.push_back(25);
    cout << v1[4] << endl;
    cout << v1.capacity() << endl; //be 8 
    cout << "sizeof: " << sizeof(v1) << endl;
    cout << endl;

    v1.push_back(24);
    v1.push_back(24);
    v1.push_back(24);
    v1.push_back(24);
    cout << v1.capacity() << endl; // be 16 because vector increas yours camacity duble
    cout << v1.size() << endl;
    cout << "sizeof: " << sizeof(v1) << endl;
    cout << endl;

    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    cout << "sizeof: " << sizeof(v1) << endl;
    v1.shrink_to_fit();
    cout << endl;




    return 0;
}
