#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
   // char a[80];

   // cin.getline(a,8);
   // cout << a;

   /* char a[80], b[80];
    cout << "Enter some input:\n";
    cin >> a >> b;
    cout << a << '-' << b << "END OF OUTPUT\n"; */

    
    char myString[80],myString1[80] = "May the hair on your toes grow long and curly.";
    cout << "Enter a line of input:\n";
    cin.getline(myString, strlen(myString1) + 1);
    cout << myString << "<END OF OUTPUT";

    return 0;
}
