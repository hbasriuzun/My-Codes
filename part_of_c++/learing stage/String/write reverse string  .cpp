#include <iostream>
#include <cstring>

using namespace std;

void reverse(char *ch,int k);
int main(int argc, char const *argv[])
{
    char my[] = "Hasan basri uzun.";
    reverse(my,0);
    return 0;
}

void reverse(char* ch,int k){
    char a = *(ch + k);

    if (a=='\0')
        return;
    
    reverse(ch,k + 1);
    
    cout << a;
}
