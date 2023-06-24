#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const char* p_messega{"Hello World"};

    cout << sizeof((p_messega + 1)) << endl;
    cout << *(p_messega + 9) << endl;
    cout << p_messega  << endl;

    char p_message[] {"Hello world"};

    p_message[0] = 'B';
    cout << p_message  << endl;

    return 0;
}
