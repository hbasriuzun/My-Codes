#include <iostream>
#include <map>
using namespace std;

template <typename T>
void print(T& t, string sep = " "){
    typename T::iterator iter = t.begin();
    while (iter!=t.end())
    {
        cout << iter->first << " " << iter->second << sep;
        iter++;  
    }
    cout << endl;
}

using namespace std;
int main(int argc, char const *argv[])
{
    map <string,int> m;
    cout << m.empty() << endl;
    pair <string,int> deger1("bir",1);
    pair <string,int> deger2("iki",2);

    m.insert(deger1);
    m.insert(deger2);

    cout << m.empty() << endl;

    print(m,"\n");

    return 0;
}
