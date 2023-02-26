#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(T value)
{
    cout << value << endl;
}

template <typename T,int N>
class Array
{
    private:
        T my_array[N];

    public:
        int Get_size() const {  return N;  }
        void add_value(int index, int value) 
        {
            my_array[index] = value;
        }
        int return_value(int index)
        {
            return my_array[index];
        }
};

int main(int argc, char const *argv[])
{
    print(5);
    print("Selam");
    print(5.5f);
    cout << "--------------\n";

    Array<int,8> arr;
    arr.add_value(0,4);

    cout << "index of " << 0 << " value is " << arr.return_value(0) << "\n";
    cout << "Sizde of Array: " << arr.Get_size() << "\n";

    return 0;
}
