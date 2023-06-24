#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v_1;
    
    v_1.push_back(1);
    v_1.push_back(2);
    v_1.push_back(3);
    v_1.push_back(4);
    v_1.push_back(5);

    cout << v_1.size() << endl;
    cout << v_1.capacity() << endl;


    cout << "v_1[0] = " << v_1[0] << endl;
    cout << "v_1.front() = " << v_1.front() << endl;

    cout << "v_1[2] = " << v_1[2] << endl;
    cout << "v_1.back() = " << v_1.back() << endl;
    cout << "v_1.at(2) = " << v_1.at(2) << endl;

    cout << "v_1: v_1.size() = " << v_1.size() << endl;
    cout << "v_1: v_1.capacity() = " << v_1.capacity() << endl;

    cout << "v_1'de sonuncu eleman: " << v_1[v_1.size()-1] << endl;

    cout << endl;

    cout << "v_1: ";
    for (size_t i = 0; i < v_1.size(); i++)
    {
        cout << v_1[i] << ", ";
    }
    cout << endl;
    cout << "v_1: ";
    for(auto i: v_1){
        cout << i << ", ";
    }
    
    cout << endl;
    cout << endl;

    cout << "v_1.empty() = " << v_1.empty() << endl;
   // v_1.clear();
    cout << "v_1.empty() = " << v_1.empty() << endl;

    cout << "Ilk eleman:" << *v_1.begin() << endl;
    cout << "Son eleman:" << *(v_1.end()-1) << endl;
    v_1.push_back(9);
    v_1.push_back(7);
    v_1.push_back(8);
    cout << "Son eleman:" << *(v_1.end()-1) << endl;
    cout << "v_1: ";
    for(auto i = v_1.begin(); i != v_1.end(); i++){
        cout << *i << ", ";
    }
    cout << endl;

    sort(v_1.begin(), v_1.end());

    cout << "v_1: ";
    for(auto i = v_1.begin(); i != v_1.end(); i++){
        cout << *i << ", ";
    }
    cout << endl;

    v_1.pop_back();

    cout << "v_1: ";
    for(auto i: v_1)
        cout << i << ", ";
    cout << endl;

    
    v_1[14] = 15;
    cout << "v_1[14]: " << v_1[14] << endl;

    cout << "v_1 size: " << v_1.size() << endl;
    cout << "v_1 capacity: " << v_1.capacity() << endl;

    v_1.push_back(5);
    v_1.push_back(16);

    cout << "v_1[5]: " << v_1[5] << endl;
    
    cout << "v_1 size: " << v_1.size() << endl;
    cout << "v_1 capacity: " << v_1.capacity() << endl;

    return 0;
}