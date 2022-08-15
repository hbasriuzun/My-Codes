#include <iostream> 
#include <string>

using namespace std;

struct People
{
    string name;
    int age;
    People(int age, string name){
        age = age;
        name = name;
    }
int main(int argc, char const *argv[])
{
    People Peop1 = People(19,"Burcu Tas");
    
    return 0;
}
