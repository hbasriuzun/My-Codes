#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    char ad[] = "Hasan Basri Uzun";

    char ad1[20];

    char ad2[] = " Burcu tas";

    strcpy(ad1,"Burcu Tas");

    if (strcmp(ad1,ad2))
        cout << "The strings are NOT the same."<< endl;
    else
        cout << "The strings are the same."<<endl;
    

    cout << ad << endl ;
    cout << ad1 << endl ;
    cout << ad2 << endl ;

    cout << strlen(ad) << endl;
    cout << strcat(ad,ad2) << endl;

    char stringVar1[10] = "Hello";
    char stringVar2[10] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char stringVar3[10] = {'H', 'e', 'l', 'l', 'o'};
    char stringVar4[6] = "Hello";
    char stringVar5[] = "Hello";

    char stringVar[30] = "Hello";
    strcat(stringVar, " and Good-bye.");
    cout << stringVar;

    char shortString[] = "abc";
    char shortString1[] = { 'a', 'b', 'c'};
    
    return 0;
}
