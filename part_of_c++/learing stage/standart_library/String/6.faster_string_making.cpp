#include <bits/stdc++.h>
using namespace std;

static uint32_t s_AllocCount = 0;
#define STRING_VIEV 0


void* operator new(size_t size){
    s_AllocCount++;
    cout << "Allocating " << size << " bytes" << endl;
    return malloc(size);
}

#if STRING_VIEV
    void PrintName(string_view name){
        cout << name << endl;
    }
#else
    void PrintName(const string& name){
        cout << name << endl;
    }
#endif


int main(){

    std::string name = "hasan basri";
    PrintName(name);

#if 0
    string firstname = name.substr(0, 5);
    string lastname = name.substr(6, 5);

#else
    string_view firstName(name.c_str(), 5);
    string_view lastName(name.c_str() + 6, 5);
#endif
    cout << "AllocCount: " << s_AllocCount << endl;

    return 0;
}